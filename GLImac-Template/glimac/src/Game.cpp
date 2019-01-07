/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2
 * RunInTheValley - Game.cpp
 */


#include <glimac/Game.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

Game::Game(const char* levelFile,std::vector<Model> listModel, Render render)
{
	m_world = new World(levelFile,listModel);
	m_distance = 0.001;
	m_trackballCam= new TrackballCamera(3.0f,15.0f,0.0f);
	m_firstPersonCam= new FirstPersonCamera(1.0f,0.0f);
	m_render = render;
	m_princess = new Princess(listModel[0]);
	m_worldPos = glm::mat4();
	m_worldRot = glm::mat4();
	m_enemy = new Enemy(listModel[6]);
}

void Game::checkBonusAndCoins(){
	//std::cout << "je suis dans checkBonusAndCoins" << std::endl;
	int result = m_princess->collisionWithBlock(m_world->getMap()->getListBlocs()[(int)m_time]);

	if (result == 2){ //collision with a bonus
		Bonus bonus;
		bonus.generateBonus();
		m_listBonus.push_back(bonus);
        int currentState = m_princess->getState();
        if(currentState == 0 || currentState == 1)
            m_world->getMap()->convertBlocTypeToEmpty((int)m_time, 2, m_princess->getRelativePosition());
        if(currentState == 1 || currentState == 2)
            m_world->getMap()->convertBlocTypeToEmpty((int)m_time, 1, m_princess->getRelativePosition());
        if(currentState == 2)
            m_world->getMap()->convertBlocTypeToEmpty((int)m_time, 0, m_princess->getRelativePosition());
	}
	else if (result == 3) {// collision with a coin
		m_world->getPlayer()->addMoney(1);
        int currentState = m_princess->getState();
        if(currentState == 0 || currentState == 1)
            m_world->getMap()->convertBlocTypeToEmpty((int)m_time, 2, m_princess->getRelativePosition());
        if(currentState == 1 || currentState == 2)
            m_world->getMap()->convertBlocTypeToEmpty((int)m_time, 1, m_princess->getRelativePosition());
        if(currentState == 2)
            m_world->getMap()->convertBlocTypeToEmpty((int)m_time, 0, m_princess->getRelativePosition());
	}
}

bool Game::isEnd(){
	/* End of the map */
	if ((int)m_time == m_world->getMap()->getListBlocsSize()){
		//m_world->getMap()->printMap();
		return true;
	}

	/* Collision with a block or an empty block */
	else if (m_princess->collisionWithBlock(m_world->getMap()->getListBlocs()[(int)m_time]) == 1)
		return true;

	/* Collision with a enemy */
	//if (m_world->getMap().getListEnemies()[0].getProximity() == 0)
	//	return true;

	/*if ()
	*/
	return false;
}

void Game::endGame(){
    unsigned int bestScore = saveBestScore();
    getWorld().getPlayer()->getDescription();
    std::cout << "YOUR BEST SCORE : " << bestScore << std::endl;
}


void Game::playGame(){
	checkBonusAndCoins();
	Player *player = m_world->getPlayer();
	/* Increment score of the player */
	player->addScore(1);

	/* Apply bonus on the game */
	//std::cout << "***************************** switch type: "<< m_listBonus.size() << std::endl;
	for (unsigned int i = 0; i < m_listBonus.size(); i++){
		//std::cout << "***************************** switch type: "<< m_world->getListBonus()[i].getType() << std::endl;
		switch(m_listBonus[i].getType()){
			case 1:
				//std::cout << "***************************** case 1" << std::endl;
				player->addMoney(2); //BONUS TYPE 1 : add 2 coins every loop tour
				break;
			case 2:
				//std::cout << "***************************** case 2" << std::endl;
				player->addScore(5);
				m_listBonus[i].setTime(5);
				break;
			case 3:
				//std::cout << "***************************** case 3" << std::endl;
				player->addMoney(10);
				m_listBonus[i].setTime(0);
				break;
		}
	}

	manageDeleteAndIncrementBonus();
	//m_world->getPlayer()->printInfosPlayer();
}
void Game::changeActiveCam(){
	if(m_activeCam==1){
		m_activeCam=0;
	}
	else{
		m_activeCam=1;
	}
};

void Game::drawAll(){
    glm::mat4 MVMatrix = glm::translate(glm::mat4(), glm::vec3(0,0,0));
    glm::mat4 newMVMatrix;
    glm::mat4 viewMatrix;

    glEnable(GL_DEPTH_TEST);

    if(m_activeCam==0)
    	viewMatrix = m_trackballCam->getViewMatrix();
	else
		viewMatrix = m_firstPersonCam->getViewMatrix();

    m_render.reset();

    if(m_activeCam == 1)
    	viewMatrix = glm::translate(viewMatrix, glm::vec3((SIZE_BLOCK/3)-(m_princess->getRelativePosition()*SIZE_BLOCK/3),SIZE_BLOCK/2-m_princess->getState()*SIZE_BLOCK/3,0.0));

    MVMatrix = viewMatrix*MVMatrix;
    m_render.sendLight(viewMatrix);
    if(m_time-m_princess->getTimeChange()>SIZE_BLOCK*3){
    	m_princess->backToNormalState(m_time);
    }

    /* Draw Princess */
    double sizeBlock = SIZE_BLOCK;
    m_princess->draw(m_render,sizeBlock,MVMatrix,m_time);


    /* Draw Ennemies */
    m_enemy->draw(m_render,sizeBlock,MVMatrix,m_time);

    MVMatrix = m_worldPos;
    MVMatrix = viewMatrix*MVMatrix;


    /* Draw World */

    MVMatrix = glm::translate(MVMatrix, glm::vec3(0.0, -1.5, -SIZE_BLOCK/2));
    m_render.sendMatrix(MVMatrix);
    m_world->drawWorld(MVMatrix,viewMatrix,m_render,m_time);

    //Incremet global time
    m_time+=m_distance;
	if(test==0)
    	m_worldPos = glm::translate(glm::mat4(), glm::vec3(0, 0, m_distance))*m_worldPos;

    double deltaL, deltaR;
    glm::mat4 rotat;
    

    switch(m_direction){
        case (-1):
            deltaL = m_time - int(m_time);
            m_worldPos = glm::translate(glm::mat4(), glm::vec3(0, 0, -deltaL))*m_worldPos;
            m_worldPos = glm::rotate(glm::mat4(), glm::radians(-90.0f), glm::vec3(0, 1.0, 0))*m_worldPos;
            m_worldPos = glm::translate(glm::mat4(), glm::vec3(-0.5, 0, 0))*m_worldPos;
            m_worldPos = glm::translate(glm::mat4(), glm::vec3(0, 0, -0.5+deltaL))*m_worldPos;

            m_direction = 0;
            break;
        case 1:
            deltaR = m_time - int(m_time);
            m_worldPos = glm::translate(glm::mat4(), glm::vec3(0, 0, -deltaR))*m_worldPos;
            m_worldPos = glm::rotate(glm::mat4(), glm::radians(90.0f), glm::vec3(0, 1.0, 0))*m_worldPos;

            m_worldPos = glm::translate(glm::mat4(), glm::vec3(0.5, 0, 0))*m_worldPos;
            m_worldPos = glm::translate(glm::mat4(), glm::vec3(0, 0, -0.5+deltaR))*m_worldPos;

            m_direction = 0;
            break;
    }
}

bool Game::eventManager(SDL_Event &e,glm::ivec2 &mousePos){
   /* SDL_Event e;
    while(window.pollEvent(e)) {
        if(e.type == SDL_QUIT) {
            return true; // Leave the loop after this iteration
        }*/
        if(e.type == SDL_KEYDOWN){
        	switch(e.key.keysym.sym){
                case SDLK_ESCAPE:
                    return true;
                    break;

        		case SDLK_LEFT:
        		case SDLK_q:
        			if(m_world->getMap()->getListBlocs()[(int)m_time].getDirection()=='L'){
                        if(lastTurn + double(SIZE_BLOCK) < m_time){ //Impeach to spam the rotation when player is on a rotation bloc
                            m_direction = -1;
                            lastTurn = m_time;
                        }
        			}
        			else{
        				m_princess->goLeft();
        			}
        			break;
        		case SDLK_DOWN:
        		case SDLK_s:
        			m_princess->bendDown(m_time);
        			break;
        		case SDLK_RIGHT:
        		case SDLK_d:
        			if(m_world->getMap()->getListBlocs()[(int)m_time].getDirection()=='R'){
        				
                        if(lastTurn + double(SIZE_BLOCK) < m_time){ //Impeach to spam the rotation when player is on a rotation bloc
                            m_direction = 1;
                            lastTurn = m_time;
                        }
        			}
        			else{
        				m_princess->goRight();
        			}
        			break;
        		case SDLK_UP:
        		case SDLK_z:
        			m_princess->jump(m_time);
        			break;

        		case SDLK_c:
        			changeActiveCam();
        			break;
        		case SDLK_l:
        			changeLockCam();
        			break;
        	}
        }
        else if(e.type == SDL_KEYUP){
        	switch(e.key.keysym.sym){
        		case SDLK_s:
        			m_princess->backToNormalState(m_time);
        			break;
        	}
        }
        else if(e.type == SDL_MOUSEMOTION){
            	if(!m_lockCam && m_rightClicked){
            		getActiveCam()->rotateLeft(mousePos.y - m_mousePrevY);
            		getActiveCam()->rotateUp(mousePos.x - m_mousePrevX);
            	}
            	m_mousePrevX = mousePos.x;
            	m_mousePrevY = mousePos.y;
            }
        	else if(e.type == SDL_MOUSEBUTTONDOWN){
            	if(e.button.button == SDL_BUTTON_WHEELUP) // scroll up
		        {
		            getActiveCam()->moveFront(0.1);
		        }
		        else if(e.button.button == SDL_BUTTON_WHEELDOWN) // scroll down
		        {
		            getActiveCam()->moveFront(-0.1);
		        }
		        else if(e.button.button == SDL_BUTTON_RIGHT){
		        	m_rightClicked = true;
		        }

            }
            else if(e.type == SDL_MOUSEBUTTONUP){
            	if(e.button.button == SDL_BUTTON_RIGHT){
		        	m_rightClicked = false;
		        }

            }
   		return false;
    }


void Game::manageDeleteAndIncrementBonus(){
	for (unsigned int i = 0; i < m_listBonus.size(); i++){
		if(m_listBonus[i].getTime() == 0)
			m_listBonus.erase(m_listBonus.begin()+i);
		else
			m_listBonus[i].decrementTime();
	}
}


unsigned int Game::saveBestScore(){
    Player* player = m_world->getPlayer();
    player->askingForPseudo();

    std::string currentPseudo = player->getPseudo();
    unsigned int currentScore = player->getScore();
    unsigned int best = 0;

    std::ifstream file("assets/bestscore.txt", std::ios::in);  
    std::ofstream tmpFile("assets/tmp.txt",std::ios::out | std::ios::trunc);
    bool change = false;
    bool isIn = false;

    if(file && tmpFile) 
    {
            std::string content;
            std::string pseudo;
            int score;
            while(getline(file, content)) 
            {
                std::istringstream line(content);
                line >> pseudo >> score;
                if(pseudo == currentPseudo){
                    isIn = true;
                    if(currentScore > score){
                        best = currentScore;
                        change = true;
                    }
                    else{
                        best = score;
                    }
                }
                if(change)
                    tmpFile << pseudo <<  " " << currentScore << std::endl;
                else
                    tmpFile << pseudo <<  " " << score << std::endl;

            }
            if(!isIn)
                tmpFile << currentPseudo << " " << currentScore << std::endl;

            tmpFile.close();
            file.close();
            remove("assets/bestscore.txt");
            rename("assets/tmp.txt","assets/bestscore.txt");

            return best;
    }
    else{
        std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
    }
    return 0;
}

void Game::displayBestScores(){
    std::ifstream file("assets/bestscore.txt", std::ios::in);  
    if(file) 
    {
        std::string content;
        std::string pseudo;
        int score;
        std::cout << "Scoreboard:" << std::endl;
        std::cout << "\tPseudo:\t\tScore:" << std::endl;
        while(getline(file, content)) 
        {
            std::istringstream line(content);
            line >> pseudo >> score;
            std::cout << "\t"<< pseudo <<"\t\t" << score << std::endl;
        }
        
        file.close();
    }
    else{
        std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
    }
}

Game::~Game(){}

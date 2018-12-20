/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Game.cpp 
 */


#include <glimac/Game.hpp>


Game::Game(const char* levelFile,std::vector<Model> listModel, Render render)
{
	m_world = new World(levelFile,listModel);
	m_distance = 0.05;
	m_trackballCam= new TrackballCamera(5.0f,5.0f,-60.0f);
	m_render = render; 
	m_princess = new Princess(listModel[0]);  
}

void Game::checkBonusAndCoins(){
	int result = m_princess->collisionWithBlock(m_world->getMap().getListBlocs()[m_distance]);
	Bonus bonus;
	if (result == 2) //collision with a bonus
		m_world->getListBonus().push_back(bonus.generateBonus());
	else if (result == 3) // collision with a coin
		m_world->getPlayer().addMoney(1);
}

bool Game::endGame(){
	/* End of the map */ 
	if (m_distance == m_world->getMap().getListBlocsSize())
		return true;

	/* Collision with a block or an empty block */
	for (unsigned int i = 0; i < m_world->getMap().getListBlocsSize(); i++){
		if (m_princess->collisionWithBlock(m_world->getMap().getListBlocs()[i]) == 1)
			return true;
	}

	/* Collision with a enemy */
	if (m_world->getMap().getListEnemies()[0].getProximity() == 0)
		return true;

	/*if ()
	*/
	return false;
}


void Game::playGame(){
	checkBonusAndCoins();

	/* Increment score of the player */ 
	m_world->getPlayer().addScore(1);

	/* Apply bonus on the game */
	for (unsigned int i = 0; i < m_world->getListBonus().size(); i++){
		switch(m_world->getListBonus()[i].getType()){
			case 1: m_world->getPlayer().addMoney(10); //BONUS TYPE 1 : add 2 coins every loop tour 
			case 2: 
				m_world->getPlayer().addScore(100);
				m_world->getListBonus()[i].setTime(0);
			case 3: 
				m_world->getPlayer().addMoney(100);
				m_world->getListBonus()[i].setTime(0);
		}
	}


	/// Incrementer position de tous les blocs

	//m_world.deleteBonus();
	incrementDistance(0.1);
}


void Game::drawAll(){
	glm::mat4 MVMatrix;
    glm::mat4 newMVMatrix;
    glm::mat4 viewMatrix;

    viewMatrix = m_trackballCam->getViewMatrix();

    m_render.reset();
    MVMatrix= glm::translate(glm::mat4(), glm::vec3(0, -1.0, 0)); 
    MVMatrix = viewMatrix*MVMatrix;
    m_render.sendLight(viewMatrix);

    /*if(m_time-m_princess->getTimeChange()>SIZE_BLOCK){
    	m_princess->backToNormalState(m_time);
    }*/

    double sizeBlock = SIZE_BLOCK;
    m_princess->draw(m_render,sizeBlock,MVMatrix);

	MVMatrix = glm::translate(MVMatrix, glm::vec3(0.0, -(SIZE_BLOCK), m_distance));
    
	MVMatrix = glm::rotate(MVMatrix, float(m_direction*(M_PI/2.0)), glm::vec3(0, 1.0, 0));
    m_direction = 0;

    m_render.sendMatrix(MVMatrix);
    m_world->drawWorld(MVMatrix,viewMatrix,m_render);

    //Incremet global time
    m_time+=m_distance;
}

bool Game::eventManager(glimac::SDLWindowManager &window){
    SDL_Event e;
    while(window.pollEvent(e)) {
        if(e.type == SDL_QUIT) {
            return true; // Leave the loop after this iteration
        }
        else if(e.type == SDL_KEYDOWN){
        	switch(e.key.keysym.sym){
        		case SDLK_q:
        			m_princess->goLeft();
        			if(m_world->getMap().getListBlocs()[(int)m_time].getDirection()=='L'){
        				std::cout << "GO LEFT " << m_time << std::endl;
        				m_direction = -1;
        			}
        			break;
        		case SDLK_s: 
        			m_princess->bendDown(m_time);
        			break;
        		case SDLK_d: 
        			m_princess->goRight();
        			if(m_world->getMap().getListBlocs()[(int)m_time].getDirection()=='R'){
        				std::cout << "GO RIGHT" << std::endl;
        				m_direction = 1;
        			}
        			break;
        		case SDLK_z:
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
    }
    return false;
}

Game::~Game(){}
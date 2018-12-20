/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - World.cpp 
 */


#include <glimac/World.hpp>
#include <glimac/Map.hpp>
#define SIZE_BLOCK 1.0

World::World(const char* levelFile, std::vector<Model> listModel, Render render){
	m_speed = 0.001;
	m_map = new Map(levelFile); 
	m_princess = new Princess();
	m_listModel = listModel;
	m_render = render;
	m_player = new Player("",listModel[0]);
	m_trackballCam = new TrackballCamera(5.0f,5.0f,-30.0f);
	std::vector<Bonus> listBonus;
	m_listBonus = listBonus;
}

World::World(const World& world){
	m_speed = world.m_speed;
	m_map = world.m_map;
	m_listBonus = world.m_listBonus;
	m_princess = world.m_princess;
	m_player = world.m_player;
	m_listModel = world.m_listModel;
	m_render = world.m_render; 
}
void World::drawWorld(){
	glm::mat4 MVMatrix;
    glm::mat4 newMVMatrix;
    glm::mat4 viewMatrix;
    int virage = 1;

    viewMatrix = m_trackballCam->getViewMatrix();

    m_render.reset();
    MVMatrix= glm::translate(glm::mat4(), glm::vec3(0, -1.0, 0)); 
    MVMatrix = viewMatrix*MVMatrix;
	newMVMatrix = glm::scale(MVMatrix, glm::vec3(2.5, 2.5, 2.5));
	m_render.sendMatrix(newMVMatrix);
	//Draw Background
    m_render.sendLight(viewMatrix);
	m_listModel[5].draw();
    
    MVMatrix = glm::scale(MVMatrix, glm::vec3(2.0, 2.0, 2.0));
    

    newMVMatrix = glm::scale(MVMatrix, glm::vec3(1.0, 1.0, 1.0));
    newMVMatrix= glm::translate(newMVMatrix, glm::vec3(0, 0.5, 0)); 
    m_render.sendMatrix(newMVMatrix);
    //Draw princess
    m_listModel[0].draw();

    std::vector<Model> listModTmp = m_listModel;
    listModTmp.erase(listModTmp.begin()); //Remove the princess model
    unsigned int sizeList = m_map->getListBlocsSize();
    std::vector<Bloc> listBloc= m_map->getListBlocs();

    MVMatrix = glm::translate(MVMatrix, glm::vec3(0.0, -(SIZE_BLOCK), m_speed));
    
    m_speed += 0.001;m_render.sendMatrix(MVMatrix);
    for(int i = 0; i<sizeList;i++){char direction = listBloc[i].getDirection();
		
    	
    	listBloc[i].drawBlock(m_listModel, viewMatrix, m_render,MVMatrix);
    	switch(direction){
			case 'L':
				MVMatrix = glm::rotate(MVMatrix, float(M_PI/2.0), glm::vec3(0, 1.0, 0));
				m_render.sendMatrix(MVMatrix);
				virage = 0;
				break;
			case 'R':
				MVMatrix = glm::rotate(MVMatrix, float(-M_PI/2.0), glm::vec3(0, 1.0, 0));
				m_render.sendMatrix(MVMatrix);
				virage = 2;
				break;
			default:
				break;
		}
		MVMatrix = glm::translate(MVMatrix, glm::vec3(0, 0, -(SIZE_BLOCK)));
    	//m_listModel[2].draw();
	}
}

World::~World(){}

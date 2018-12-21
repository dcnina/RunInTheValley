/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - World.cpp 
 */


#include <glimac/World.hpp>
#include <glimac/Map.hpp>

World::World(const char* levelFile, std::vector<Model> listModel){
	m_speed = 0.05;
	m_map = new Map(levelFile); 
	m_listModel = listModel;
	m_player = new Player("audrey",listModel[0]);
	//std::vector<Bonus> listBonus;
	//m_listBonus = listBonus;
}

World::World(const World& world){
	m_speed = world.m_speed;
	m_map = world.m_map;
	//m_listBonus = world.m_listBonus;
	m_player = world.m_player;
	m_listModel = world.m_listModel;
}



void World::drawWorld(glm::mat4 MVMatrix,glm::mat4 viewMatrix, Render render){
    glm::mat4 newMVMatrix;
	//Draw background
	newMVMatrix = glm::scale(MVMatrix,glm::vec3(2.0, 2.0, 2.0));
	render.sendMatrix(newMVMatrix);
	m_listModel[5].draw();
    

    std::vector<Model> listModTmp = m_listModel;
    listModTmp.erase(listModTmp.begin());
    unsigned int sizeList = m_map->getListBlocsSize();
    std::vector<Bloc> listBloc= m_map->getListBlocs();

    MVMatrix = glm::translate(MVMatrix, glm::vec3(0.0, -(SIZE_BLOCK), m_speed));
    
    m_speed += 0.05;render.sendMatrix(MVMatrix);
    for(int i = 0; i<sizeList;i++){
    	char direction = listBloc[i].getDirection();
		
    	
    	listBloc[i].drawBlock(m_listModel, viewMatrix, render,MVMatrix);
    	switch(direction){
			case 'L':
				MVMatrix = glm::rotate(MVMatrix, float(M_PI/2.0), glm::vec3(0, 1.0, 0));
				render.sendMatrix(MVMatrix);
				break;
			case 'R':
				MVMatrix = glm::rotate(MVMatrix, float(-M_PI/2.0), glm::vec3(0, 1.0, 0));
				render.sendMatrix(MVMatrix);
				break;
			default:
				break;
		}
		MVMatrix = glm::translate(MVMatrix, glm::vec3(0, 0, -(SIZE_BLOCK)));
	}
}

World::~World(){}


/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - World.cpp 
 */


#include <glimac/World.hpp>
#include <glimac/TrackballCamera.hpp>
#define SIZE_BLOCK 1.0

World::World(const Map &map, const GLuint &backgroundTexture, std::vector<Bonus> listBonus, Princess princess, Player player, std::vector<Model> listModel,Render render)
	:m_map(map), m_backgroundTexture(backgroundTexture), m_speed(2.0), m_listBonus(listBonus), m_princess(princess), m_player(player), m_listModel(listModel),m_render(render){}

World::World(const World& world){
	m_speed = world.m_speed;
	m_map = world.m_map;
	m_backgroundTexture = world.m_backgroundTexture; 
	m_speed= world.m_speed;
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

    TrackballCamera trackCamera(15.0f,30.0f,-30.0f);
    viewMatrix = trackCamera.getViewMatrix();

    m_render.reset();
    MVMatrix= glm::translate(glm::mat4(), glm::vec3(0, -1.0, 0)); 
    MVMatrix = viewMatrix*MVMatrix;



    m_render.sendLight(viewMatrix);


    MVMatrix = glm::scale(MVMatrix, glm::vec3(2.0, 2.0, 2.0));

    newMVMatrix = glm::scale(MVMatrix, glm::vec3(1.0, 1.0, 1.0));
    newMVMatrix= glm::translate(newMVMatrix, glm::vec3(0, 0.5, 0)); 
    m_render.sendMatrix(newMVMatrix);

    m_listModel[0].draw();

    std::vector<Model> listModTmp = m_listModel;
    listModTmp.erase(listModTmp.begin()); //Remove the princess model
    unsigned int sizeList = m_map.getListBlocsSize();
    std::vector<Bloc> listBloc= m_map.getListBlocs();

    MVMatrix = glm::translate(MVMatrix, glm::vec3(0.0, -(SIZE_BLOCK), SIZE_BLOCK));
    for(int i = 0; i<sizeList;i++){char direction = listBloc[i].getDirection();
		
		MVMatrix = glm::translate(MVMatrix, glm::vec3(0, 0, -(SIZE_BLOCK)));
    	m_render.sendMatrix(MVMatrix);
    	
    	listBloc[i].drawBlock(m_listModel, viewMatrix, m_render,MVMatrix);
    	switch(direction){
			case 'L':
				MVMatrix = glm::rotate(MVMatrix, float(M_PI/2.0), glm::vec3(0, 1.0, 0));
				m_render.sendMatrix(MVMatrix);
				break;
			case 'R':
				MVMatrix = glm::rotate(MVMatrix, float(-M_PI/2.0), glm::vec3(0, 1.0, 0));
				m_render.sendMatrix(MVMatrix);
				break;
			default:
				break;
		}
    	//m_listModel[2].draw();
	}
}

World::~World(){}

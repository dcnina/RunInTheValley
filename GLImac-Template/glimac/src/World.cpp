/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - World.cpp 
 */


#include <glimac/World.hpp>
#include <glimac/TrackballCamera.hpp>


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

    TrackballCamera trackCamera;
    viewMatrix = trackCamera.getViewMatrix();

    m_render.reset();
    MVMatrix= glm::translate(glm::mat4(), glm::vec3(0, 0, 0)); 
    MVMatrix = viewMatrix*MVMatrix;


    m_render.sendMatrix(MVMatrix);

    m_render.sendLight(viewMatrix);

    m_listModel[0].draw();

}

World::~World(){}

/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - World.cpp 
 */


#include <glimac/World.hpp>


World::World()
	:Map(), m_speed(0), m_backgroundTexture(0){}

World::World(const Map &map, const GLuint &backgroundTexture, const double &speed)
	:m_map(map), m_backgroundTexture(backgroundTexture), m_speed(speed){}

World::~World(){}

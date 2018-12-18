/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Game.cpp 
 */


#include <glimac/Game.hpp>


Game::Game()
	:m_world(World()), m_distance(0), m_timeSpend(0){}

Game::Game(const World &world, const unsigned int &distance, const unsigned int &timeSpend)
	:m_world(world), m_distance(distance), m_timeSpend(timeSpend){}

Game::~Game(){}
/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Game.cpp 
 */


#include <glimac/Game.hpp>


Game::Game()
	:m_world(World()), m_distance(0){}

Game::Game(const World &world, const unsigned int &distance)
	:m_world(world), m_distance(distance){}



bool Game::endGame(){
	return true;
}

Game::~Game(){}
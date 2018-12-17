/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Game.cpp 
 */


#include <glimac/Game.hpp>


Game::Game()
	:m_world(World()), m_distance(0), m_timeSpend(0), m_princess(Princess()), m_player(Player()){}

Game::Game(const World &world, const unsigned int &distance, const unsigned int &timeSpend, const Princess &princess, const Player &player)
	:m_world(world), m_distance(distance), m_timeSpend(timeSpend), m_princess(princess), m_player(player){}

Game::~Game(){}
/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Enemy.cpp 
 */


#include <glimac/Enemy.hpp>

Enemy::Enemy()
{
	m_proximity = 3;
 	m_position.push_back(0.0);
 	m_position.push_back(0.0);
 	m_position.push_back(0.0);
 	m_relativePosition = 1;
}

Enemy::Enemy(const unsigned int &proximity)
 :m_proximity(proximity){
 	m_position.push_back(0.0);
 	m_position.push_back(0.0);
 	m_position.push_back(0.0);
 	m_relativePosition = 1;
 }

Enemy::~Enemy(){}
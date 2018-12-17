/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Enemy.cpp 
 */


#include <glimac/Enemy.hpp>

Enemy::Enemy()
 :m_proximity(0){}

Enemy::Enemy(const unsigned int &proximity)
 :m_proximity(proximity){}

Enemy::~Enemy(){}
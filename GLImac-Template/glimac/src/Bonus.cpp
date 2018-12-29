/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Bonus.hpp 
 */


#include <glimac/Bonus.hpp>
#include <cstdlib>
#include <iostream>
#include <ctime>

Bonus::Bonus()
	:m_type(0), m_time(0){}

Bonus::Bonus(const unsigned int &type, const unsigned int &_time)
	:m_type(type), m_time(_time){}

Bonus Bonus::generateBonus(){
	m_type = (std::rand()%3) + 1; 
	m_time = (std::rand()%10) + 5;
}

Bonus::~Bonus(){}


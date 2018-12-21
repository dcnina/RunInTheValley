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
	unsigned int randomType = (std::rand()%3) + 1; 
	unsigned int randomTime = (std::rand()%10) + 5;
	std::cout << "########## aleatoire: ##########################" << randomType << " " << randomTime << std::endl;
	return Bonus(randomType, randomTime);
}

Bonus::~Bonus(){}


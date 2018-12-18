/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Bonus.hpp 
 */


#include <glimac/Bonus.hpp>

Bonus::Bonus()
	:m_type(0), m_time(0){}

Bonus::Bonus(const unsigned int &type, const unsigned int &_time)
	:m_type(type), m_time(_time){}


Bonus::~Bonus(){}


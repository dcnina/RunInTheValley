/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Bonus.hpp 
 */


#include <glimac/Bonus.hpp>

Bonus::Bonus()
 :m_type(0), m_startTime(0), m_endTime(0){}

Bonus::Bonus(unsigned int &type, unsigned int &startTime, unsigned int &endTime)
 :m_type(type), m_startTime(startTime), m_endTime(endTime){}

Bonus::~Bonus(){}


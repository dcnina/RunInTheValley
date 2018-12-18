/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Object.cpp 
 */


#include <glimac/Object.hpp>

Object::Object(){
	for(int i=0; i<3; i++)
		m_position[i] = 0;
}

Object::Object(const std::vector<double> &position){
	for(unsigned int i=0; i<position.size(); i++)
		m_position[i] = position[i];
}
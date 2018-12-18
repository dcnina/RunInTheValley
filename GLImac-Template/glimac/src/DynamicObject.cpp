/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - DynamicObject.cpp 
 */


#include <glimac/DynamicObject.hpp>




DynamicObject::DynamicObject()
	:m_relativePosition(1){}

DynamicObject::DynamicObject(const unsigned int &relativePosition)
	:m_relativePosition(relativePosition){}

DynamicObject::~DynamicObject(){}
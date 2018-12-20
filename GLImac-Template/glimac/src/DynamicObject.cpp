/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - DynamicObject.cpp 
 */


#include <glimac/DynamicObject.hpp>
DynamicObject::DynamicObject()
	:m_relativePosition(1), m_model(Model())
{
	m_position.push_back(0.0);
	m_position.push_back(0.0);
	m_position.push_back(0.0);
}

DynamicObject::DynamicObject(Model &model)
	:m_relativePosition(1),m_model(model)
{
	m_position.push_back(0.0);
	m_position.push_back(0.0);
	m_position.push_back(0.0);
}
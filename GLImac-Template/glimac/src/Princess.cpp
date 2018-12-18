/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Princess.cpp 
 */


#include <glimac/Princess.hpp>

Princess::Princess()
:m_state(1){}

Princess::Princess(const int &state)
:m_state(state){}

bool Princess::goLeft(){
	if(m_relativePosition != 0){
		m_relativePosition--;
		return true;
	}
	return false;
}

bool Princess::goRight(){
	if(m_relativePosition != 2){
		m_relativePosition++;
		return true;
	}
	return false;
}

bool Princess::jump(){
	if(m_state != 2){
		m_state++;
		return true;
	}
	return false;
}

bool Princess::bendDown(){
	if(m_state != 0){
		m_state--;
		return true;
	}
	return false;
}

void Princess::backToNormalState(){
	m_state = 1;
}

Princess::~Princess(){}
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


int Princess::collisionWithBlock(Bloc &bloc){
	//Test if princess is in the air (jump)
	if(m_state == 2){
		switch(bloc.getMatrixTypes()[0][m_relativePosition]){
			case 'F' : return 1;
			case 'O' : return 1;
			case 'B' : return 2;
			case 'C' : return 3;
		}
		return 0;
	}

	//Test if princess stands up
	if(m_state == 1){
		switch(bloc.getMatrixTypes()[m_state][m_relativePosition]){
			case 'F' : return 1;
			case 'O' : return 1;
			case 'B' : return 2;
			case 'C' : return 3;
		}

		switch(bloc.getMatrixTypes()[3][m_relativePosition]){
			case 'E' : return 1;
			case 'F' : return 1;
			case 'O' : return 1;
		}
		return 0;
	}

	//test if princess is bend down
	if(m_state == 0){
		switch(bloc.getMatrixTypes()[2][m_relativePosition]){
			case 'F' : return 1;
			case 'O' : return 1;
			case 'B' : return 2;
			case 'C' : return 3;
		}

		if(bloc.getMatrixTypes()[3][m_relativePosition] == 'E')
			return 1;

		return 0;
	}
	return 0;
}

void Princess::drawPrincess(){
	
}

Princess::~Princess(){}
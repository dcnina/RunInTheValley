/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Princess.cpp 
*/


#include <glimac/Princess.hpp>

Princess::Princess()
:DynamicObject(){}

Princess::Princess(Model &model)
:DynamicObject(model){}

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

bool Princess::jump(double &timeChange){
	if(m_state != 2){
		m_state++;
		m_timeChange = timeChange;
		return true;
	}
	return false;
}

bool Princess::bendDown(double &timeChange){
	if(m_state != 0){
		m_state--;
		m_timeChange = timeChange;
		return true;
	}
	return false;
}

void Princess::backToNormalState(double &timeChange){
	m_state = 1;
	m_timeChange = timeChange;
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

void Princess::draw(Render &render, double &sizeBlock, glm::mat4 MVMatrix){
	glm::mat4 newMVMatrix = glm::translate(MVMatrix, glm::vec3(-sizeBlock/3+m_relativePosition*sizeBlock/3,-sizeBlock/2.0, 0));
 	if(m_state==0)
		newMVMatrix = glm::rotate(MVMatrix, float(M_PI/2.0), glm::vec3(1.0, 0, 0));
 	render.sendMatrix(newMVMatrix);
	m_model.draw();
}

Princess::~Princess(){}
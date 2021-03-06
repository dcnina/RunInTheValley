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
		if(bloc.getMatrixTypes()[0][m_relativePosition] == 'O' || bloc.getMatrixTypes()[1][m_relativePosition] == 'O')
			return 1;
		else if(bloc.getMatrixTypes()[0][m_relativePosition] == 'B' || bloc.getMatrixTypes()[1][m_relativePosition] == 'B')
			return 2;
		else if(bloc.getMatrixTypes()[0][m_relativePosition] == 'C' || bloc.getMatrixTypes()[1][m_relativePosition] == 'C'){
			return 3;
		}
		return 0;
	}

	//Test if princess stands up
	if(m_state == 1){
		if(bloc.getMatrixTypes()[2][m_relativePosition] == 'O' || bloc.getMatrixTypes()[1][m_relativePosition] == 'O')
			return 1;
		else if(bloc.getMatrixTypes()[2][m_relativePosition] == 'B' || bloc.getMatrixTypes()[1][m_relativePosition] == 'B')
			return 2;
		else if(bloc.getMatrixTypes()[2][m_relativePosition] == 'C' || bloc.getMatrixTypes()[1][m_relativePosition] == 'C')
			return 3;	
		else if(bloc.getMatrixTypes()[2][m_relativePosition] == 'H'){
			return 4;
		}
	}

	if(m_state == 1 || m_state == 0){

		switch(bloc.getMatrixTypes()[2][m_relativePosition]){
			case 'O' : return 1;
				break;
			case 'B' : return 2;
				break;
			case 'C' : return 3;
				break;
			case 'H' : return 4;
				break;
		}

		if(bloc.getMatrixTypes()[3][m_relativePosition] == 'E')
			return 1;

		return 0;
	}
	return 0;
}

void Princess::draw(Render &render, double &sizeBlock, glm::mat4 MVMatrix, double &time){
	glm::mat4 newMVMatrix = glm::translate(MVMatrix, glm::vec3((-sizeBlock/3)+(m_relativePosition*sizeBlock/3),fabs(sinf(time*5))*0.1, 0));
	//std::cout << "position " << m_relativePosition*sizeBlock/3 << std::endl;
	//glm::mat4 newMVMatrix = glm::translate(MVMatrix, glm::vec3(-sizeBlock/3+m_relativePosition*sizeBlock/3,-sizeBlock/2.0, 0));
 	if(m_state==0){
        newMVMatrix = glm::rotate(MVMatrix, float(M_PI/2.0),glm::vec3(1.0,0.0,0.0));
		newMVMatrix = glm::translate(newMVMatrix, glm::vec3((-sizeBlock/3)+(m_relativePosition*sizeBlock/3), -sizeBlock/8., 0.));
		
		//std::cout << "----------------------------------------" << sizeBlock << "--------------------------------------" << std::endl;
	}
	if(m_state == 2)
	 	newMVMatrix = glm::translate(MVMatrix, glm::vec3((-sizeBlock/3)+(m_relativePosition*sizeBlock/3),sizeBlock/2, 0.));
 	render.sendMatrix(newMVMatrix);
	m_model.draw();
}

Princess::~Princess(){}
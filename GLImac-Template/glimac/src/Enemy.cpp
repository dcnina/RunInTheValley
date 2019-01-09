/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Enemy.cpp 
 */


#include <glimac/Enemy.hpp>

Enemy::Enemy()
{
	m_proximity = 3;
 	m_position.push_back(0.0);
 	m_position.push_back(0.0);
 	m_position.push_back(0.0);
 	m_relativePosition = 1;
}

/*Enemy::Enemy(const unsigned int &proximity)
 :m_proximity(proximity){
 	m_position.push_back(0.0);
 	m_position.push_back(0.0);
 	m_position.push_back(0.0);
 	m_relativePosition = 1;
}*/
Enemy::Enemy(Model &model, Princess *princess)
:DynamicObject(model){
	m_proximity = 3;
 	m_relativePosition = 1;
 	m_princess = princess;
}

void Enemy::draw(Render &render, double &sizeBlock, glm::mat4 MVMatrix, double &time){
	int state = m_princess->getState();
	for(int i =0; i<3; i++){
		glm::mat4 newMVMatrix = glm::translate(MVMatrix, glm::vec3((-sizeBlock/3)+(i*sizeBlock/3),fabs(sinf(time*5))*0.1, 0.33*m_proximity));
	 	if(state==0){
	        newMVMatrix = glm::rotate(MVMatrix, float(M_PI/2.0),glm::vec3(1.0,0.0,0.0));
			newMVMatrix = glm::translate(newMVMatrix, glm::vec3((-sizeBlock/3)+(m_relativePosition*sizeBlock/3), -sizeBlock/8., 0.));
			
			//std::cout << "----------------------------------------" << sizeBlock << "--------------------------------------" << std::endl;
		}
		if(state == 2)
		 	newMVMatrix = glm::translate(MVMatrix, glm::vec3((-sizeBlock/3)+(m_relativePosition*sizeBlock/3),sizeBlock/2, 0.));

	 	render.sendMatrix(newMVMatrix);
		m_model.draw();	
	}
}

Enemy::~Enemy(){}
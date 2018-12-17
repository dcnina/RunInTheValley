#ifndef __FREEFLYCAMERA__HPP
#define __FREEFLYCAMERA__HPP

#include <math.h>

class FreeflyCamera{
	public:

		FreeflyCamera()
			:m_Position(0,0,0), m_fPhi(M_PI),m_fTheta(0)
		{
			computeDirectionVectors();
		}
		void moveLeft(float t){
			m_Position += t*m_LeftVector;
		}
		void moveFront(float t){
			m_Position += t*m_FrontVector;
		}
		void rotateLeft(float degrees){
			degrees = glm::radians(degrees);
			m_fPhi += degrees;
			computeDirectionVectors();
		}
		void rotateUp(float degrees){
			degrees = glm::radians(degrees);
			m_fTheta += degrees;
			computeDirectionVectors();
		}
		glm::mat4 getViewMatrix() const {
			return glm::lookAt(m_Position,m_Position+m_FrontVector, m_UpVector);
		}
	private:
		glm::vec3 m_Position;
		float m_fPhi;
		float m_fTheta;
		glm::vec3 m_FrontVector;
		glm::vec3 m_LeftVector;
		glm::vec3 m_UpVector;

		void computeDirectionVectors(){
			m_FrontVector = glm::vec3(cos(m_fTheta)*sin(m_fPhi),sin(m_fTheta),cos(m_fTheta)*cos(m_fPhi));
			m_LeftVector = glm::vec3(sin(m_fPhi+M_PI/2),0,cos(m_fPhi+M_PI/2));
			m_UpVector = glm::cross(m_FrontVector,m_LeftVector); 
		}
};

#endif
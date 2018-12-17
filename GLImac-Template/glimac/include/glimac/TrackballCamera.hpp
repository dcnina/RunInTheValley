#ifndef __TRACKBALLCAMERA__HPP
#define __TRACKBALLCAMERA__HPP

class TrackballCamera{
	public:
		TrackballCamera()
			:m_fDistance(5.0),m_fAngleX(0.0),m_fAngleY(0.0)
		{}
		TrackballCamera(float dist, float angleX, float angleY)
			:m_fDistance(dist),m_fAngleX(angleX),m_fAngleY(angleY)
		{}
		void moveFront(float delta){
			if(delta>0)
				m_fDistance-=0.5;
			else if(delta<0)
				m_fDistance+=0.5;
		}
		void rotateLeft(float degrees){
			m_fAngleY += degrees/10;
		}
		void rotateUp(float degrees){
			m_fAngleX += degrees/10;
		}
		glm::mat4 getViewMatrix() const{
			glm::mat4 mat = glm::translate(glm::mat4(),glm::vec3(0.0f, 0.0f, -m_fDistance));
			mat=glm::rotate(mat,glm::radians(m_fAngleX),glm::vec3(1.0f, 0.0f, 0.0f));
			mat=glm::rotate(mat,glm::radians(m_fAngleY),glm::vec3(0.0f, 1.0f, 0.0f));
			return mat;
		}
	private:
		float m_fDistance;
		float m_fAngleX;
		float m_fAngleY;
};

#endif
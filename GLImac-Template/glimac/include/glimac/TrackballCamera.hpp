#ifndef __TRACKBALLCAMERA__HPP
#define __TRACKBALLCAMERA__HPP

class Camera{
	protected:
		float m_distance;
		float m_angleX;
		float m_angleY;
	public:
		Camera(float angleX=0.0f,float angleY=0.0f):m_angleX(angleX),m_angleY(angleY){};
		virtual void rotateLeft(const float degrees) = 0;
		virtual void rotateUp(const float degrees) = 0;
		virtual void moveFront(const float delta) = 0;
		virtual glm::mat4 getViewMatrix() const = 0;
};

class TrackballCamera : public Camera {
	protected:
		float m_distance;
	public:
		TrackballCamera(float dist = 5.0, float angleX = 0.0, float angleY = 0.0)
			:m_distance(dist),Camera(angleX,angleY)
		{}
		void moveFront(const float delta) {
			m_distance-=delta;
		}
		void rotateLeft(float degrees) override{
			m_angleX += degrees;
		}
		void rotateUp(float degrees) override{
			m_angleY += degrees;
		}
		glm::mat4 getViewMatrix() const{
			glm::mat4 mat = glm::translate(glm::mat4(),glm::vec3(0.0f, 0.0f, -m_distance));
			mat=glm::rotate(mat,glm::radians(m_angleX),glm::vec3(1.0f, 0.0f, 0.0f));
			mat=glm::rotate(mat,glm::radians(m_angleY),glm::vec3(0.0f, 1.0f, 0.0f));
			return mat;
		}
};

class FirstPersonCamera : public Camera{
	private:
		float m_angleMax = 90.0f;
		glm::vec3 m_position = glm::vec3(0.0f,-0.5f,0.0f);
	public:
		FirstPersonCamera(float angleX=0.0f,float angleY=0.0f):Camera(angleX,angleY){}

		void setAngleMax(float angle){
			m_angleMax = angle;
		}
		void setPosition(const glm::vec3 &p) {
			m_position = p;
		}
		void rotateLeft(const float degrees) override{
			float angle = m_angleX+degrees;
			if(angle > -m_angleMax && angle < m_angleMax)
				m_angleX = angle;
		}
		void rotateUp(const float degrees) override{
			float angle = m_angleY+degrees;
			if(angle > -m_angleMax && angle < m_angleMax)
				m_angleY = angle;
		}
		void moveFront(const float delta) override{}

		glm::mat4 getViewMatrix() const override{
			glm::mat4 mat  = glm::rotate(glm::mat4(),glm::radians(m_angleX),glm::vec3(1.0,0.0,0.0));
			mat = glm::rotate(mat,glm::radians(m_angleY),glm::vec3(0.0,1.0,0.0));
			mat = glm::translate(mat,m_position);
			return mat;
		}
};

#endif
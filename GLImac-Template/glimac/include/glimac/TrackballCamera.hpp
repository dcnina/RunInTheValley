/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Render.hpp 
 */

/**
 *\file Render.hpp
 *\author  {Audrey.C, Nina.DC, Lucas.L}
 *\date 17 december 2018
 *\brief class Cameras
*/

/**
 *\class Camera
 *\brief
 *  
 */


#ifndef __TRACKBALLCAMERA__HPP
#define __TRACKBALLCAMERA__HPP

class Camera{
	protected:
		float m_distance; /*!< Distance of the camera */ 
		float m_angleX; /*!< AngleX */ 
		float m_angleY; /*!< AngleY */ 
	public:
		//CONSTRUCTOR
		/**
		*\brief Camera  constructor   
		*\details Constructor of Camera
		*/
		Camera(float angleX=0.0f,float angleY=0.0f):m_angleX(angleX),m_angleY(angleY){};
		
		/**
		*\brief rotate left / right of the camera   
		*\params float degrees
		*/
		virtual void rotateLeft(const float degrees) = 0;		
		/**
		*\brief rotate Up / down of the camera   
		*\params float degrees
		*/
		virtual void rotateUp(const float degrees) = 0;


		/**
		*\brief Moving forward/backward camera 
		*\params float delta
		*/
		virtual void moveFront(const float delta) = 0;

		/// GETTERS

		/**
		*\brief Virtual Get the viewMatrix   
		*\return viewMatrix 
		*/
		virtual glm::mat4 getViewMatrix() const = 0;
};

/**
 *\class TrackballCamera
 *  
 */

class TrackballCamera : public Camera {
	protected:
		float m_distance; /*!< Distance of the camera */ 
	public:
		//CONSTRUCTOR
		/**
		*\brief TrackballCamera  constructor   
		*\details Constructor of TrackballCamera
		*\params float dist, float angleX, float angleY
		*/
		TrackballCamera(float dist = 5.0, float angleX = 0.0, float angleY = 0.0)
			:m_distance(dist),Camera(angleX,angleY)
		{}

		/**
		*\brief Redefinition of moveFront
		*/
		void moveFront(const float delta) {
			m_distance-=delta;
		}
		/**
		*\brief Redefinition of rotateLeft
		*/
		void rotateLeft(float degrees) override{
			m_angleX += degrees;
		}

		/**
		*\brief Redefinition of rotateLeft
		*/
		void rotateUp(float degrees) override{
			m_angleY += degrees;
		}
		/// GETTERS

		/**
		*\brief Redefinition of Get the viewMatrix   
		*\return viewMatrix 
		*/
		glm::mat4 getViewMatrix() const{
			glm::mat4 mat = glm::translate(glm::mat4(),glm::vec3(0.0f, 0.0f, -m_distance));
			mat=glm::rotate(mat,glm::radians(m_angleX),glm::vec3(1.0f, 0.0f, 0.0f));
			mat=glm::rotate(mat,glm::radians(m_angleY),glm::vec3(0.0f, 1.0f, 0.0f));
			return mat;
		}
};

/**
 *\class FirstPersonCamera
 *  
 */

class FirstPersonCamera : public Camera{
	private:
		float m_angleMax = 90.0f; /*!< Angle max of the firstPerson Cam */ 
		glm::vec3 m_position = glm::vec3(0.0f,-0.5f,0.0f);  /*!< Position of the Camera */ 
	public:
		//CONSTRUCTOR
		/**
		*\brief FirstPersonCamera  constructor   
		*\details Constructor of FirstPersonCamera
		*\params float angleX, float angleY
		*/
		FirstPersonCamera(float angleX=0.0f,float angleY=0.0f):Camera(angleX,angleY){}


		///SETTERS
		/**
		*\brief set angleMax  
		*/
		void setAngleMax(float angle){
			m_angleMax = angle;
		}
		/**
		*\brief set Position  
		*/
		void setPosition(const glm::vec3 &p) {
			m_position = p;
		}
		/**
		*\brief redefinition  of rotateLeft
		*/
		void rotateLeft(const float degrees) override{
			float angle = m_angleX+degrees;
			if(angle > -m_angleMax && angle < m_angleMax)
				m_angleX = angle;
		}
		/**
		*\brief redefinition  of rotateUp
		*/
		void rotateUp(const float degrees) override{
			float angle = m_angleY+degrees;
			if(angle > -m_angleMax && angle < m_angleMax)
				m_angleY = angle;
		}

		/**
		*\brief redefinition  of moveFront
		*/
		void moveFront(const float delta) override{}

		/**
		*\brief redefinition  of getViewMatrix
		*/
		glm::mat4 getViewMatrix() const override{
			glm::mat4 mat  = glm::rotate(glm::mat4(),glm::radians(m_angleX),glm::vec3(1.0,0.0,0.0));
			mat = glm::rotate(mat,glm::radians(m_angleY),glm::vec3(0.0,1.0,0.0));
			mat = glm::translate(mat,m_position);
			return mat;
		}
};

#endif
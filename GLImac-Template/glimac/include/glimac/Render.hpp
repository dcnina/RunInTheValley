/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Render.hpp 
 */

/**
 *\file Render.hpp
 *\author  {Audrey.C, Nina.DC, Lucas.L}
 *\date 17 december 2018
 *\brief class Render
*/

/**
 *\class Render
 *\brief
 *  
 */


#ifndef __RENDER__
#define __RENDER__

#include <GL/glew.h>
#include <glimac/glm.hpp>
#include <GL/gl.h>
#include <glimac/Program.hpp>
#include <deque>
#include <iostream>


class Light
	{
		private:
			glm::vec3 m_position;
			glm::vec3 m_intensity;

		public:
			Light(const glm::vec3 &pos, const glm::vec3 &intensity):m_position(pos), m_intensity(intensity){}
			void sendUniform(const GLuint progGLId, const int i) const;
			~Light(){}
};
class Render{
	private:
		GLuint m_uMVPMatrix; /*!< Uniform MVPMatrix */ 
	    GLuint m_uMVMatrix; /*!< Uniform MVMatrix */ 
	    GLuint m_uNormalMatrix; /*!< Uniform NormalMatrix */ 

	    GLuint m_uKd; /*!< Uniform uKd */ 
	    GLuint m_uKs; /*!< Uniform uKs */ 
	    GLuint m_uShininess; /*!< Uniform uShininess */ 
	    GLuint m_uLightDir_vs; /*!< Uniform LightDir */ 
	    GLuint m_uLightIntensity; /*!< Uniform LightIntensity */ 
	    GLuint m_uTexture; /*!< Uniform Texture */ 

	    glm::vec3 m_Kd = glm::vec3(0.5,0.5,0.5); /*!< Kd */ 
		glm::vec3 m_Ks = glm::vec3(0.5,0.5,0.5); /*!< Ks */ 
		float m_Shininess = 0.5; /*!< Shininess */ 
		glm::vec4 m_LightDir_vs = glm::vec4(1, 1, 1, 0); /*!< LightDir_vs */ 
		glm::vec3 m_LightIntensity = glm::vec3(30.0,30.0,30.0); /*!< LightIntensity */ 

		std::deque<Light> m_worldLights; 

	public:

		glimac::Program *m_prog;
		glm::mat4 m_projMatrix = glm::perspective(glm::radians(70.f),8.0f/6.0f,0.1f,100.f);
		glm::mat4 m_MVMatrix = glm::translate(glm::mat4(),glm::vec3(0.0f, 0.0f, -5.0f));
		

		//CONSTRUCTOR
		/**
		*\brief Render default constructor   
		*\details Constructor by default of Render
		*/
		Render(){};

		/**
		*\brief copy constructor   
		*\params Render render
		*\details Constructor by copy of Render
		*/
		Render(const Render& render);

		/**
		*\brief Render constructor  
		*\params glimac::Program 
		*\details Constructor Render
		*/
		Render(glimac::Program *prog);


		/**
		*\brief Reset of the shader
		*/
		void reset() const;

		/**
		*\brief Send the Light uniform Matrix
		*/
		void sendLight(glm::mat4 viewMatrix) const;

		/**
		*\brief Send the uniform Matrix
		*/
		void sendMatrix(glm::mat4 MVMatrix) const;

		/**
		*\brief add a light
		*/
		void addLight(Light *l){
			m_worldLights.push_back(*l);
		}

		///DESTRUCTOR
		/**
		*\brief Default destructor   
		*\details Destructor by default of Texture2D
		*/
		~Render();
};

#endif
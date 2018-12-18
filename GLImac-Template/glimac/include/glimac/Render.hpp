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

class Render{
	private:
		GLuint m_uMVPMatrix;
	    GLuint m_uMVMatrix;
	    GLuint m_uNormalMatrix;

	    GLuint m_uKd;
	    GLuint m_uKs;
	    GLuint m_uShininess;
	    GLuint m_uLightPos_vs;
	    GLuint m_uLightIntensity;

	    glm::vec3 m_Kd = glm::vec3(0.5,0.5,0.5);
		glm::vec3 m_Ks = glm::vec3(0.5,0.5,0.5);
		float m_Shininess = 0.5;
		glm::vec4 m_LightPos_vs = glm::vec4(2.0,2.0,2.0,0.0);
		glm::vec3 m_LightIntensity = glm::vec3(10.0,10.0,10.0);

	public:

		glimac::Program m_prog;
		glm::mat4 m_projMatrix = glm::perspective(glm::radians(70.f),8.0f/6.0f,0.1f,100.f);

		Render(std::string vShader, std::string fShader);

		void reset() const;
		void sendLight(glm::mat4 viewMatrix) const;
		void sendMatrix(glm::mat4 MVMatrix) const;
		~Render();
};

#endif
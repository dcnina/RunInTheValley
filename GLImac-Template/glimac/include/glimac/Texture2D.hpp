/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Texture2D.hpp 
 */

/**
 *\file Texture2D.hpp
 *\author  {Audrey.C, Nina.DC, Lucas.L}
 *\date 17 december 2018
 *\brief class Texture2D
*/

/**
 *\class Texture2D
 *\brief Texture2D
 *  
 */

#include <string>
#include <iostream>
#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>

#ifdef __APPLE__
#include <openGL/gl.h>
#else
#include <GL/gl.h>
#endif

#include <vector>
#include <glimac/Program.hpp>

#ifndef __TEXTURE2D__
#define __TEXTURE2D__


struct Vertex2DUV{
    glm::vec2 position;
    glm::vec2 texture;
    Vertex2DUV(const glm::vec2 &pos, const glm::vec2 &tex):position(pos), texture(tex){};
};

class Texture2D{
	protected:
		GLuint m_idText;
		std::string m_textureImage; //!<Image of the Texture
		GLuint uModelMatrix;
		GLuint uTexture;

	public:
		glimac::Program *m_prog;
		///CONSTRUCTOR
		/**
		*\brief Default constructor   
		*\details Constructor by default of Texture2D
		*/
		Texture2D(glimac::Program *prog);
	
		/**
		*\brief copy constructor   
		*\details Constructor by copy of Texture2D
		*/
		Texture2D(const Texture2D &texture);

		///GETTERS
		/**
		*\brief Get uModelMatrix
		*\return current uModelMatrix
		*/
		inline GLuint getUModelMatrix() const{ return uModelMatrix; }

		/**
		*\brief Get uTexture
		*\return current uTexture
		*/
		inline GLuint getUTexture() const{ return uTexture; }

		/**
		*\brief Get idText
		*\return current idText
		*/
		inline GLuint getIdText() const{ return m_idText; }


		///METHODS
		/**
		*\brief translate matrix
		*\params translation in X, translation in Y
		*\return matrix 
		*/
		glm::mat3 translate(float tx, float ty) const;

		/**
		*\brief scale matrix
		*\params value of scale in x, value of scale in y
		*\return matrix 
		*/
		glm::mat3 scale(float sx, float sy) const;

		/**
		*\brief initialize the texture 
		*\params vShaders and fShader
		*\return gluint : vbo 
		*/
		GLuint initializeTexture2D(std::string bgImage);

		/**
		*\brief create and bind vao 
		*\params gluint vbo
		*\return gluint : vao 
		*/
		GLuint createAndBindVao(const GLuint &vbo);

		/**
		*\brief draw the background texture 
		*\params gluint vao 
		*/
		void drawTexture2D(const GLuint &vao);

		/**
		*\brief free the texture, vao and vbo 
		*\params vao and vbo 
		*/
		void freeTexture2D(const GLuint &vao, const GLuint &vbo);

		///DESTRUCTOR
		/**
		*\brief Default destructor   
		*\details Destructor by default of Player
		*/
		~Texture2D();
	
};

#endif

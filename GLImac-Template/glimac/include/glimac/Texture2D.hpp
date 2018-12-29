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
#include <GL/gl.h>
#include <vector>
#include <glimac/Program.hpp>
#include <glimac/Image.hpp>

#ifndef __TEXTURE2D__
#define __TEXTURE2D__


struct Vertex2DUV{
    glm::vec2 position;
    glm::vec2 texture;
    Vertex2DUV(const glm::vec2 &pos, const glm::vec2 &tex):position(pos), texture(tex){};
};

class Texture2D{
	protected:
		GLuint m_idText; /*!< Id of the texture */ 
		glimac::FilePath m_textureImage; /*!<Image of the Texture */
		GLuint m_uModelMatrix; /*!< uModelMatrix of the texture */
		GLuint m_uTexture; /*!< uTexture of the texture */
		GLuint m_vao; /*!< vao of the texture */
		GLuint m_vbo; /*!< vbo of the texture */

	public:
		glimac::Program *m_prog; /*!< program of the texture */
		
		///CONSTRUCTOR
		/**
		*\brief Default constructor   
		*\details Constructor by default of Texture2D
		*/
		Texture2D(glimac::Program *prog,glimac::FilePath path);
	
		/**
		*\brief copy constructor   
		*\details Constructor by copy of Texture2D
		*/
		Texture2D(const Texture2D &text);


		///GETTERS
		/**
		*\brief Get uModelMatrix
		*\return current uModelMatrix
		*/
		inline GLuint getUModelMatrix() const{ return m_uModelMatrix; }

		/**
		*\brief Get uTexture
		*\return current uTexture
		*/
		inline GLuint getUTexture() const{ return m_uTexture; }

		/**
		*\brief Get idText
		*\return current idText
		*/
		inline GLuint getIdText() const{ return m_idText; }


		///SETTERS
		/**
		*\brief Set uModelMatrix
		*\params GLUint mat
		*/
		inline void setModelMatrix(const GLuint &mat){
		    m_uModelMatrix = mat;
		}


		///METHODS

		/**
		*\brief load the Image texture
		*\return unique_ptr Image
		*/
		std::unique_ptr<glimac::Image> loadImg();
		
		/**
		*\brief initialize the texture 
		*\params unique_ptr texture
		*/
		void initializeTexture2D(std::unique_ptr<glimac::Image> &texture);

		/**
		*\brief create and bind vao 
		*/
		void createAndBindVao();

		/**
		*\brief draw the texture 
		*/
		void drawTexture2D();


		///DESTRUCTOR
		/**
		*\brief Default destructor   
		*\details Destructor by default of Texture2D
		*/
		~Texture2D();
	
};

#endif
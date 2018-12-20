/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Button.hpp 
 */

/**
 *\file Button.hpp
 *\author  {Audrey.C, Nina.DC, Lucas.L}
 *\date 17 december 2018
 *\brief class Button
*/

/**
 *\class Button
 *\brief Button
 *  
 */

#include <glimac/Texture2D.hpp>


#ifndef __BUTTON__
#define __BUTTON__


class Button{
	private:
		Texture2D m_buttonTexture;
		float m_posX;
		float m_posY;
		float m_scaleX;
		float m_scaleY;
	public:
		///CONSTRUCTOR
		/**
		*\brief Button constructor   
		*/
		Button(const float posX, const float posY, const float scaleX, const float scaleY, const Texture2D &texture);

		///METHODS
		/**
		*\brief initialize the texture 
		*\params vShaders and fShader
		*\return gluint : vbo 
		*/
		GLuint initializeButton(const std::string bgImage);
			
		/**
		*\brief create and bind the button vao 
		*\params gluint vbo
		*\return gluint : vao 
		*/
		GLuint createButton(const GLuint &vbo);

		/**
		*\brief draw the background button texture 
		*\params gluint vao 
		*/
		void drawButton(const GLuint &vao);

		/**
		*\brief free the button texture, vao and vbo 
		*\params vao and vbo 
		*/
		void freeButtonTexture(const GLuint &vao, const GLuint &vbo);

		///DESTRUCTOR
		/**
		*\brief Default destructor   
		*\details Destructor by default of Button
		*/
		~Button();
};

#endif
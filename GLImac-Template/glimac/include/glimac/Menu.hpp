/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Menu.hpp 
 */

/**
 *\file Menu.hpp
 *\author  {Audrey.C, Nina.DC, Lucas.L}
 *\date 17 december 2018
 *\brief class Menu
*/

/**
 *\class Menu
 *\brief Menu
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
#include <glimac/Texture2D.hpp>
//#include <glimac/Button.hpp>

#ifndef __MENU__
#define __MENU__


class Menu{
	private:
		Texture2D m_menuTexture;
		//std::vector<Button> m_buttons;
		// GLuint uModelMatrix;
		// GLuint uTexture;

	public:
		
		///CONSTRUCTOR
		/**
		*\brief Default constructor   
		*\details Constructor by default of Menu
		*/
		Menu(const Texture2D &texture);

		/**
		*\brief initialize the texture 
		*\params vShaders and fShader
		*\return gluint : vbo 
		*/
		GLuint initializeMenu(const std::string bgImage);

		/**
		*\brief create and bind the menu vao 
		*\params gluint vbo
		*\return gluint : vao 
		*/
		GLuint createMenu(const GLuint &vbo);

		/**
		*\brief draw the background menu texture 
		*\params gluint vao 
		*/
		void drawBackground(const GLuint &vao);

		/**
		*\brief free the menu texture, vao and vbo 
		*\params vao and vbo 
		*/
		void freeMenuTexture(const GLuint &vao, const GLuint &vbo);	
		

		/**
		*\brief Initialize the game, create Window, load GLEW
		*\return current gameState
		*/
		glimac::SDLWindowManager initializeGame();

		///DESTRUCTOR
		/**
		*\brief Default destructor   
		*\details Destructor by default of Player
		*/
		~Menu();
	
};


#endif

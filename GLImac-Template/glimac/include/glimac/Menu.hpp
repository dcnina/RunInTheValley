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
#include <GL/gl.h>
#include <vector>
#include <glimac/Program.hpp>
#include <glimac/Texture2D.hpp>
#include <glimac/Button.hpp>

#ifndef __MENU__
#define __MENU__


class Menu{
	private:
		Texture2D *m_menuTexture;
		std::vector<Button> m_buttons;
		// GLuint uModelMatrix;
		// GLuint uTexture;

	public:
		
		///CONSTRUCTOR
		/**
		*\brief Default constructor   
		*\details Constructor by default of Menu
		*/
		Menu(Texture2D *texture);

		inline std::vector<Button> getButtons(){
			return m_buttons;
		}

		/**
		*\brief initialize the texture 
		*\params vShaders and fShader
		*\return gluint : vbo 
		*/
		void initializeMenu(const std::string bgImage);

		/**
		*\brief create and bind the menu vao 
		*\params gluint vbo
		*\return gluint : vao 
		*/
		void createMenu();
		inline void addButton(Button &button){
			m_buttons.push_back(button);
		}
		/**
		*\brief draw the menu with texture 
		*/
		void drawMenu();
		
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
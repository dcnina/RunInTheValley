/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Menu.hpp 
 */

/**
 *\file GameManager.hpp
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

#ifndef __MENU__
#define __MENU__


struct Vertex2DUV{
    glm::vec2 position;
    glm::vec2 texture;
    Vertex2DUV(const glm::vec2 &pos, const glm::vec2 &tex):position(pos), texture(tex){};
};


class Menu{
	private:
		GLuint m_idText;
		std::string m_backgroundImage; //!< Background Image of the Menu
		//std::vector<Button> m_buttons;
		GLuint uModelMatrix;
		GLuint uTexture;
	public:
		
		glimac::Program m_prog;
		///CONSTRUCTOR
		/**
		*\brief Default constructor   
		*\details Constructor by default of Menu
		*/
		Menu(std::string bgImage);

		///METHODS
		/**
		*\brief Get game State
		*\return current gameState
		*/
		void drawMenu(std::string vShader, std::string fShader);
		void initializeMenu(std::string vShader, std::string fShader);
		void drawBackground(GLuint &vao);

		void drawButtons();

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

class Button{
	private:
		int m_posX;
		int m_posY;
	public:
		void drawButton();
};

#endif
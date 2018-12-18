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

#ifndef __MENU__
#define __MENU__


class Menu{
	private:
		std::string m_backgroundImage //!< Background Image of the Menu
	public:
		///CONSTRUCTOR
		/**
		*\brief Default constructor   
		*\details Constructor by default of Menu
		*/
		Menu(std::string backgroundImage);

		///METHODS
		/**
		*\brief Get game State
		*\return current gameState
		*/
		void drawMenu();

		void drawBackground();

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
		~GameManager();
	
};

#endif
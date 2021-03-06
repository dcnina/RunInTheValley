/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - GameManager.hpp 
 */

/**
 *\file GameManager.hpp
 *\author  {Audrey.C, Nina.DC, Lucas.L}
 *\date 17 december 2018
 *\brief class GameManager
*/

/**
 *\class GameManager
 *\brief GameManager
 *  
 */

#include <string>
#include <iostream>
#include <glimac/SDLWindowManager.hpp>

#ifndef __GAMEMANAGER__
#define __GAMEMANAGER__


class GameManager{
	private:
		unsigned int m_gameState; /*!< game State */
		unsigned int m_windowDimension; /*!< window dimension */
	public:
		///CONSTRUCTOR
		/**
		*\brief Default constructor   
		*\details Constructor by default of GameManager
		*/
		GameManager();


		///GETTERS
		/**
		*\brief Get game State
		*\return current gameState
		*/
		inline unsigned int getGameState() const{ return m_gameState; }


		///METHODS
		/**
		*\brief Launch the game
		*\params argc, argv
		*/
		void launchGame(int argc, char** argv);

		/**
		*\brief Initialize the game, create Window, load GLEW
		*/
		glimac::SDLWindowManager initializeGame();

		///DESTRUCTOR
		/**
		*\brief Default destructor   
		*\details Destructor by default of GameManager
		*/
		~GameManager();
	
};

#endif
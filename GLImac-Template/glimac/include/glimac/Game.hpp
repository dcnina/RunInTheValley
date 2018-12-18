/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Game.hpp 
 */

/**
 *\file Game.hpp
 *\author  {Audrey.C, Nina.DC, Lucas.L}
 *\date 17 december 2018
 *\brief class Game
*/

/**
 *\class Game
 *\brief Manage the game
 *  
 */


#ifndef __GAME__
#define __GAME__

#include <glimac/World.hpp>
#include <glimac/Princess.hpp>
#include <glimac/Player.hpp>

class Game{
	private:
		World m_world; //!< World 
		unsigned int m_distance; //!< Distance traveled during the game 
		/* à voir pour le meilleur score */
		//unsigned int m_timeSpend; //!< Time spend during the game

	public:
		///CONSTRUCTOR
		/**
		*\brief Game default constructor   
		*\details Constructor by default of Game
		*/
		Game();
		
		/**
		*\brief Game constructor   
		*\details Constructor of Game
		*/
		Game(const World &world, const unsigned int &distance);
		
		
		/// GETTERS
		/**
		*\brief Getter World of the Game   
		*\return current World 
		*/
		inline World getWorld()const{ return m_world;};

		/**
		*\brief Get distance of the Game   
		*\return current distance
		*/
		inline unsigned int getDistance()const{ return m_distance;};


		/// SETTERS
		/**
		*\brief Set distance of the Game   
		*\details set the current distance
		*/
		inline void setDistance(const unsigned int &distance){ m_distance = distance;};


		/// METHODS
		/**
		*\brief increment the travelled distance      
		*\param the distance to increment
		*/
		inline void incrementDistance(unsigned int distance){ m_distance += distance;};

		/**
		*\brief check the end of the game      
		*\ return true if the end is ended, else false
		*/
		bool endGame();



		///DESTRUCTOR
		/**
		*\brief Default destructor   
		*\details Destructor by default of Game
		*/
		~Game();
	
};

#endif
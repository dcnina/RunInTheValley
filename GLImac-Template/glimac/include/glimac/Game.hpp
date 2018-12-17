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

#include "World.hpp"
#include "Princess.hpp"

class Game{
	private:
		World m_world; /*!< World */
		unsigned int m_distance; /*!< Distance traveled during the game */
		/* à voir pour le meilleur score */
		unsigned int m_timeSpend; /*!< Time spend during the game */
		Princess m_princess; /*!< Character of the game */
		Player player; /*!< Player of the game */

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
		Game(World world, unsigned int distance, unsigned int timeSpend, Princess princess, Player player);
		
		
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

		/**
		*\brief Get time of the Game   
		*\return current time 
		*/
		inline unsigned int getTimeSpend()const{ return m_timeSpend;};

		/**
		*\brief Get princess of the Game   
		*\return current princess
		*/
		inline Princess getPrincess()const{ return m_princess;};

		/**
		*\brief Get Player of the Game   
		*\return current player 
		*/
		inline Player getPlayer()const{ return m_player;};


		/// SETTERS
		/**
		*\brief Set distance of the Game   
		*\return set the current distance
		*/
		inline unsigned int setDistance(const unsigned int &distance){ m_distance = distance;};

		/**
		*\brief Set time of the Game   
		*\return set the current time 
		*/
		inline unsigned int setTimeSpend(const unsigned int &timeSpend){ m_timeSpend = timeSpend;};


		///DESTRUCTOR
		/**
		*\brief Default destructor   
		*\details Destructor by default of Game
		*/
		~Game();
	
};

#endif
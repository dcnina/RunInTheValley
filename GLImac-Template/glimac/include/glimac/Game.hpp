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
#include <glimac/Bonus.hpp>
#include <glimac/SDLWindowManager.hpp>

class Game{
	private:
		World *m_world; //!< World 
		double m_distance; //!< Distance traveled during the game 
		/* à voir pour le meilleur score */
		//unsigned int m_timeSpend; //!< Time spend during the game
		TrackballCamera *m_trackballCam;
		Render m_render; //!< Render for the drawing
		Princess *m_princess; //!< Character of the game 
		double m_time = 0.0; //!< Time of the game 
		int m_direction = 0;

	public:
		///CONSTRUCTOR
		
		
		/**
		*\brief Game constructor   
		*\details Constructor of Game
		*/
		Game(const char* levelFile,std::vector<Model> listModel, Render render);
		
		
		/// GETTERS
		/**
		*\brief Getter World of the Game   
		*\return current World 
		*/
		inline World getWorld()const{ return *m_world;};

		/**
		*\brief Get distance of the Game   
		*\return current distance
		*/
		inline double getDistance()const{ return m_distance;};


		/// SETTERS
		/**
		*\brief Set distance of the Game   
		*\details set the current distance
		*/
		inline void setDistance(const double &distance){ m_distance = distance;};


		/// METHODS
		/**
		*\brief increment the travelled distance      
		*\param the distance to increment
		*/
		inline void incrementDistance(double distance){ m_distance += distance;};


		/**
		*\brief check the end of the game      
		*\ return true if the end is ended, else false
		*/
		bool endGame();

		void checkBonusAndCoins();

		/**
		*\brief play a game      
		*/
		void playGame();

		/**
		*\brief draw all element of the game      
		*/
		void drawAll();

		/**
		*\brief manage events       
		*/
		bool eventManager(glimac::SDLWindowManager &window);

		///DESTRUCTOR
		/**
		*\brief Default destructor   
		*\details Destructor by default of Game
		*/
		~Game();
	
};

#endif
/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - World.hpp 
 */

/**
 *\file World.hpp
 *\author  {Audrey.C, Nina.DC, Lucas.L}
 *\date 17 december 2018
 *\brief class World
*/

/**
 *\class World
 *\brief
 *  
 */


#ifndef __WORLD__
#define __WORLD__

#include <glimac/World.hpp>
#include <glimac/Map.hpp>
#include <GL/glew.h>

class World{
	private:
		Map m_map; //!< Map of World
		GLuint m_backgroundTexture; //!< background texture of World 
		double m_speed; //!< Speed camera world

	public:
		//CONSTRUCTOR
		/**
		*\brief World default constructor   
		*\details Constructor by default of World
		*/
		World();

		/**
		*\brief World constructor   
		*\details Constructor of World
		*/
		World(const Map &map, const GLuint &backgroundTexture, const double &speed);


		// GETTERS
		/**
		*\brief Getter World of the Game   
		*\return current World 
		*/
		inline Map getMap()const{ return m_map;};

		/// SETTERS
		/**
		*\brief Set distance of the Game   
		*\details set the current distance
		*/


		/// METHODS

		///DESTRUCTOR
		/**
		*\brief Default destructor   
		*\details Destructor by default of Game
		*/
		~World();
	
};

#endif
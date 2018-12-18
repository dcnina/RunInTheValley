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
		*\brief Get the map of the World   
		*\return current Map 
		*/
		inline Map getMap()const{ return m_map;};

		/**
		*\brief Get backgroundTexture   
		*\return current GLuint background texture 
		*/
		inline GLuint getBackgroundTexture()const{ return m_backgroundTexture;};

		/**
		*\brief Get current speed of the World   
		*\return current speed 
		*/
		inline double getSpeed()const{ return m_speed;};


		/// SETTERS
		/**
		*\brief Set current map of the World  
		*/
		inline void setMap(const Map &map){ m_map = map;};

		/**
		*\brief Set current backgroundTexture of the World   
		*/
		inline void setBackgroundTexture(const GLuint &backgroundTexture){ m_backgroundTexture = backgroundTexture;};

		/**
		*\brief Set current speed of the World   
		*/
		inline void setSpeed(const double &speed){ m_speed = speed;};



		/// METHODS

		///DESTRUCTOR
		/**
		*\brief Default destructor   
		*\details Destructor by default of Game
		*/
		~World();
	
};

#endif
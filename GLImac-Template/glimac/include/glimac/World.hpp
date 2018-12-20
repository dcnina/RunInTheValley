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

#include <GL/glew.h>

#include <glimac/World.hpp>
#include <glimac/Map.hpp>
#include <glimac/Bonus.hpp>
#include <glimac/Princess.hpp>
#include <glimac/Player.hpp>
#include <glimac/Model.hpp>
#include <glimac/Render.hpp>
#include <glimac/TrackballCamera.hpp>
	
class World{
	private:
		Map *m_map; //!< Map of World
		double m_speed; //!< Speed camera world
		std::vector<Bonus> m_listBonus; //!< Bonus list of the World
		Princess *m_princess; //!< Character of the game 
		Player *m_player; //!< Player of the game
		std::vector<Model> m_listModel; //!< Model list of the world
		Render m_render; //!< Render for the drawing

		TrackballCamera *m_trackballCam;

	public:
		//CONSTRUCTOR
		/**
		*\brief World default constructor   
		*\details Constructor by default of World
		*/
		World(){};

		/**
		*\brief World constructor   
		*\details Constructor of World
		*/
		World(const char* levelFile, std::vector<Model> listModel, Render render);
		

		World(const World& world);

		// GETTERS
		/**
		*\brief Get the map of the World   
		*\return current Map 
		*/
		inline Map getMap()const{ return *m_map;};

		/**
		*\brief Get the map of the World   
		*\return current Map 
		*/
		inline std::vector<Bonus> getListBonus()const{ return m_listBonus;};

		/**
		*\brief Get backgroundTexture   
		*\return current GLuint background texture 
		*/
		//inline GLuint getBackgroundTexture()const{ return m_backgroundTexture;};

		/**
		*\brief Get current speed of the World   
		*\return current speed 
		*/
		inline double getSpeed()const{ return m_speed;};


		/// SETTERS

		/**
		*\brief Set current backgroundTexture of the World   
		*/
		//inline void setBackgroundTexture(const GLuint &backgroundTexture){ m_backgroundTexture = backgroundTexture;};

		/**
		*\brief Set current speed of the World   
		*/
		inline void setSpeed(const double &speed){ m_speed = speed;};


		/**
		*\brief Get princess of the World  
		*\return current princess
		*/
		inline Princess getPrincess()const{ return *m_princess;};

		/**
		*\brief Get Player of the World   
		*\return current player 
		*/
		inline Player getPlayer()const{ return *m_player;};


		/// METHODS
		void addBonus(unsigned int m_type, unsigned int m_time);

		void deleteBonus();

		void drawWorld();

		/**
		*\brief   
		*\param 
		*\return current player 
		*/


		///DESTRUCTOR
		/**
		*\brief Default destructor   
		*\details Destructor by default of Game
		*/
		~World();
	
};

#endif
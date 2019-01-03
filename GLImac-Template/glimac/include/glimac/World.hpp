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

#define SIZE_BLOCK 1.0

	
class World{
	private:
		Map *m_map; /*!< Map of World  */
		double m_speed; /*!< Speed camera world */
		Player *m_player; /*!< Player of the game */
		std::vector<Model> m_listModel; /*!< Model list of the world */
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
		World(const char* levelFile, std::vector<Model> listModel);
		
		/**
		*\brief World constructor   
		*\details Constructor of World
		*/
		World(const World& world);


		/// GETTERS
		/**
		*\brief Get the map of the World   
		*\return current Map 
		*/
		inline Map* getMap()const{ return m_map;};

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

		/**
		*\brief Get Player of the World   
		*\return current player 
		*/
		inline Player* getPlayer(){ return m_player;};


		/// SETTERS
		/**
		*\brief Set current backgroundTexture of the World   
		*/
		//inline void setBackgroundTexture(const GLuint &backgroundTexture){ m_backgroundTexture = backgroundTexture;};

		/**
		*\brief Set current speed of the World  
		*\params speed 
		*/
		inline void setSpeed(const double &speed){ m_speed = speed;};


		/// METHODS
		/**
		*\brief draw the world  
		*\params MVMatrix, viewMatrix, render 
		*/
		void drawWorld( glm::mat4 MVMatrix,glm::mat4 viewMatrix, Render render, double time);


		///DESTRUCTOR
		/**
		*\brief Default destructor   
		*\details Destructor by default of World
		*/
		~World();
	
};

#endif
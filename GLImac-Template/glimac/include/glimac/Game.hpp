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
		World *m_world; /*!< World */
		double m_distance; /*!< Distance traveled during the game */
		/* à voir pour le meilleur score */
		/*unsigned int m_timeSpend; //!< Time spend during the game */
		Camera *m_trackballCam; /*!< Trackaball camera */
		Camera *m_firstPersonCam;
		Render m_render; /*!< Render for the drawing */
		Princess *m_princess; /*!< Character of the game  */
		Enemy *m_enemy;
		int m_activeCam = 0; /*! Active Camera */
		double m_time = 0.0; /*!< Time of the game  */
		int m_direction = 0; /*!< Direction of the game  */
		std::vector<Bonus> m_listBonus; /*!< Bonus list of the World */
		glm::mat4 m_worldPos; /*!< Matrix of world position */
		glm::mat4 m_worldRot; /*!< Matrix of world rotation */
		bool m_lockCam = false; /*! Edit state of the camera */
		int m_mousePrevX = 0;
		int m_mousePrevY = 0;
		bool m_rightClicked = false;
		int test = 0;

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
		inline Camera * getActiveCam() const{
			if(m_activeCam ==0)
				return m_trackballCam;
			return m_firstPersonCam;
		}
		/**
		*\brief Get distance of the Game   
		*\return current distance
		*/
		inline double getDistance()const{ return m_distance;};

		/**
		*\brief Get the bonus list of the World   
		*\return current bonus list 
		*/
		inline std::vector<Bonus> getListBonus()const{ return m_listBonus;};


		/// SETTERS
		/**
		*\brief Set distance of the Game  
		*\params distance
		*\details set the current distance
		*/
		inline void setDistance(const double &distance){ m_distance = distance;};
		inline void changeLockCam(){
			if(m_lockCam)
				m_lockCam = false;
			else
				m_lockCam = true;
		}
		void changeActiveCam();
		/// METHODS
		/**
		*\brief increment the travelled distance      
		*\params the distance to increment
		*/
		inline void incrementTime(double distance){ m_time += m_time;};

		/**
		*\brief check the end of the game      
		*\ return true if the end is ended, else false
		*/
		bool endGame();

		/**
		*\brief check if collision with a bonus or a coin      
		*/
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
		*\params SDK_Event e
		*\return false if no event detected      
		*/
		bool eventManager(SDL_Event &e,glm::ivec2 &mousePos);

		/**
		*\brief manage the bonus for deleting or incrementing      
		*/
		void manageDeleteAndIncrementBonus();


		///DESTRUCTOR
		/**
		*\brief Default destructor   
		*\details Destructor by default of Game
		*/
		~Game();
	
};

#endif
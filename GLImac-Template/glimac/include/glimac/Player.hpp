/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Player.hpp 
 */

/**
 *\file Player.hpp
 *\author  {Audrey.C, Nina.DC, Lucas.L}
 *\date 17 december 2018
 *\brief class Player
*/

/**
 *\class Player
 *\brief Manage the Player
 *  
 */

#include <string>
#include <iostream>
#include <glimac/Model.hpp>
 #include <glimac/Bonus.hpp>

#ifndef __PLAYER__
#define __PLAYER__


class Player{
	private:
		std::string m_pseudo; /*!< Player's pseudo */
		unsigned int m_score; /*!< Score of the player */
		unsigned int m_money; /*!< Number of coins owned by the player */
		Model m_model; /*!< Model of the player */

	public:
		///CONSTRUCTOR
		/**
		*\brief Default constructor   
		*\details Constructor by default of Player
		*/
		Player();

		/**
		*\brief Player Constructor
		*\details Constructor of Player
		*/
		Player(const std::string &pseudo, const Model &model);


		///GETTERS
		/**
		*\brief Get pseudo of the player
		*\return current pseudo
		*/
		inline std::string getPseudo() const{ return m_pseudo;}

		/**
		*\brief Get score of the player
		*\return current score
		*/
		inline unsigned int getScore() const{ return m_score;}

		/**
		*\brief Get money of the player
		*\return current money
		*/
		inline unsigned int getMoney() const{ return m_money;}

		/**
		*\brief Get model of the player
		*\return current model
		*/
		inline Model getModel() const{ return m_model;}


		///SETTERS
		/**
		*\brief Set pseudo of the player
		*\params pseudo
		*/
		inline void setPseudo(const std::string &pseudo) { m_pseudo = pseudo; }

		/**
		*\brief Set score of the player
		*\params score
		*/
		inline void setScore(const unsigned int &score) { m_score = score; }

		/**
		*\brief Set money of the player
		*\params money
		*/
		inline void setMoney(const unsigned int &money) { m_money = money; }

		/**
		*\brief Set model of the player
		*\params model
		*/
		inline void setModel(const Model &model) { m_model = model; }


		///METHODS
		/**
		*\brief add coins to the player money      
		*\param number of coins
		*/
		inline void addMoney(unsigned int nbCoins){ m_money += nbCoins; }

		/**
		*\brief remove coins of the player money     
		*\param number of coins
		*/
		inline void removeMoney(unsigned int nbCoins){ m_money -= nbCoins; };

		/**
		*\brief add points to the player score       
		*\param number of points
		*/
		inline void addScore(unsigned int score){ m_score += score; }

		/**
		*\brief remove points of the player score      
		*\param number of points
		*/
		inline void removeScore(unsigned int &score){ m_score -= score; };

		/**
		*\brief print the player infos 
		*/
		void printInfosPlayer();


		///DESTRUCTOR
		/**
		*\brief Default destructor   
		*\details Destructor by default of Player
		*/
		~Player();
	
};

#endif
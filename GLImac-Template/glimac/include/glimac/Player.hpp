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

#include <string.h>
#include <iostream.h>

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
		Player(std::string &pseudo, Model &model);


		///GETTERS
		/**
		*\brief Get pseudo of the player
		*\return current pseudo
		*/
		inline std::string getPseudo() const{ return m_pseudo; }

		/**
		*\brief Get score of the player
		*\return current score
		*/
		inline unsigned int getScore() const{ return m_score; }

		/**
		*\brief Get money of the player
		*\return current money
		*/
		inline unsigned int getMoney() const{ return m_money; }

		/**
		*\brief Get model of the player
		*\return current model
		*/
		inline Model getModel() const{ return m_model; }


		///SETTERS
		/**
		*\brief Set pseudo of the player
		*/
		inline void setPseudo(const std::string &pseudo) { strcpy(m_pseudo, pseudo); }

		/**
		*\brief Set score of the player
		*/
		inline void setScore(const unsigned int &score) { m_score = score; }

		/**
		*\brief Set money of the player
		*/
		inline void setMoney(const unsigned int &money) { m_money = money; }

		/**
		*\brief Set model of the player
		*/
		inline void setModel(const Model &model) { m_model = model }


		///METHODES
		/**
		*\brief add coins to the player money     
		*\details add the number of coins earned to the player's money  
		*\param number of coins
		*/
		inline void addMoney(unsigned int &nbCoins){ m_money += nbCoins; }

		/**
		*\brief remove coins of the player money     
		*\details remove the number of coins used of the player's money  
		*\param number of coins
		*/
		inline void removeMoney(unsigned int &nbCoins){ m_money -= nbCoins };


		///DESTRUCTOR
		/**
		*\brief Default destructor   
		*\details Destructor by default of Player
		*/
		~Player();
	
};

#endif
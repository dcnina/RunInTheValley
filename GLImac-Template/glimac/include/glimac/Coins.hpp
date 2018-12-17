/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Coins.hpp 
 */

/**
 *\file Coins.hpp
 *\author  {Audrey.C, Nina.DC, Lucas.L}
 *\date 17 december 2018
 *\brief class Coins
*/

/**
 *\class Coins
 *\brief
 *  
 */


#ifndef __COINS__
#define __COINS__

#include <glimac/Object.hpp>


class Coins : public Object{
	private:
		unsigned int m_value; /*!< Value of coin */
	public:
		///CONSTRUCTEUR
		/**
		*\brief Default constructor   
		*\details Constructor by default of Coins
		*/
		Coins();

		/**
		*\brief Coins Constructor
		*\details Constructor of Coins
		*/
		Coins(const unsigned int &m_value);


		///GETTERS
		/**
		*\brief Get value of the coin
		*\return current value
		*/
		inline unsigned int getValue() const{ return m_value; }


		///SETTERS
		/**
		*\brief Set value of the coin
		*/
		inline void setValue(const unsigned int &value) { m_value = value; }


		///DESTRUCTOR
		/**
		*\brief Default destructor   
		*\details Destructor by default of Coins
		*/
		~Coins();
	
};

#endif
/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Bonus.hpp 
 */

/**
 *\file Bonus.hpp
 *\author  {Audrey.C, Nina.DC, Lucas.L}
 *\date 17 december 2018
 *\brief class Bonus
*/

/**
 *\class Bonus
 *\brief
 *  
 */


#ifndef __BONUS__
#define __BONUS__

#include <glimac/Object.hpp>
#include <ctime>

class Bonus /*: public Object*/{
	private:
		unsigned int m_type; /*!< Bonus' type */
		unsigned int m_time; /*!< Bonus start time */

	public:
		///CONSTRUCTOR
		/**
		*\brief Default constructor   
		*\details Constructor by default of Bonus
		*/
		Bonus();

		/**
		*\brief Bonus Constructor
		*\details Constructor of Bonus
		*/
		Bonus(const unsigned int &type, const unsigned int &_time);


		///GETTERS
		/**
		*\brief Get type of the bonus
		*\return current type
		*/
		inline unsigned int getType() const{ return m_type;}
		/**
		*\brief Get start time of the bonus
		*\return current start time
		*/
		inline unsigned int getTime() const{ return m_time;}


		///SETTERS
		/**
		*\brief Set type of bonus
		*/
		inline void setType(const unsigned int type) { m_type = type;}

		/**
		*\brief Set start time of bonus
		*/
		inline void setTime(const unsigned int _time) { m_time = _time;}


		///METHODS
		inline void decrementTime(){ if (getTime() > 0){m_time--;}};
		inline void draw(Render &render, double &sizeBlock){};
		Bonus generateBonus();

		///DESTRUCTOR
		/**
		*\brief Default destructor   
		*\details Destructor by default of Bonus
		*/
		~Bonus();
	
};

#endif
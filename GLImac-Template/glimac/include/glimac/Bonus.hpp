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


class Bonus{
	private:
		unsigned int m_type; /*!< Bonus' type */
		unsigned int m_startTime; /*!< Bonus start time */
		unsigned int m_endTime; /*!< Bonus end time */

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
		Bonus(const unsigned int &type, const unsigned int &startTime, const unsigned int &endTime);


		///GETTERS
		/**
		*\brief Get type of the bonus
		*\return current type
		*/
		inline unsigned int getType() const{ return m_type; }

		/**
		*\brief Get start time of the bonus
		*\return current start time
		*/
		inline unsigned int getStartTime() const{ return m_startTime; }

		/**
		*\brief Get end time of the bonus
		*\return current end time
		*/
		inline unsigned int getEndTime() const{ return m_endTime; }


		///DESTRUCTOR
		/**
		*\brief Default destructor   
		*\details Destructor by default of Bonus
		*/
		~Bonus();
	
};

#endif
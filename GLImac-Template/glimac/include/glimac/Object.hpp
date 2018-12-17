/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Object.hpp 
 */

/**
 *\file Object.hpp
 *\author  {Audrey.C, Nina.DC, Lucas.L}
 *\date 17 december 2018
 *\brief class Object
*/

/**
 *\class Object : abstract
 *\brief
 *  
 */


#ifndef __OBJECT__
#define __OBJECT__

#include <vector>

class Object{
	private:
		std::vector<double> m_position; //!< Object position

	public:
		//CONSTRUCTOR
		/**
		*\brief Object constructor   
		*/
		Object(){};

		//DESTRUCTOR
		/**
		*\brief Object destructor   
		*/
		~Object(){};
	
};

#endif
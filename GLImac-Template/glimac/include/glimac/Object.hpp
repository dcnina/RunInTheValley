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
		///CONSTRUCTOR
		/**
		*\brief Object constructor   
		*/
		Object();

		/**
		*\brief Object constructor
		*/
		Object(const std::vector<double> &position);


		///GETTER
		/**
		*\brief Get the current position of object   
		*\return the current object position
		*/
		inline std::vector<double> getPosition()const{ return m_position;}


		///SETTER
		/**
		*\brief Set the current position of a Object
		*/
		inline void setPosition(const std::vector<double> &position){ 
			for(unsigned int i =0; i<position.size(); i++)
				m_position[i] = position[i];
		}


		///DESTRUCTOR
		/**
		*\brief Object destructor   
		*/
		~Object(){};
	
};

#endif
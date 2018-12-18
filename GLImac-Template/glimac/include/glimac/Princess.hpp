/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Princess.hpp 
 */

/**
 *\file Princess.hpp
 *\author  {Audrey.C, Nina.DC, Lucas.L}
 *\date 17 december 2018
 *\brief class Princess
*/

/**
 *\class Princess
 *\brief
 *  
 */


#ifndef __PRINCESS__
#define __PRINCESS__

#include <glimac/DynamicObject.hpp>

class Princess : public DynamicObject{
	private:
		int m_state = 1;//!< Princess state

	public:
		///CONSTRUCTOR
		/**
		*\brief Default constructor   
		*\details Constructor by default of Princess
		*/
		Princess();

		/**
		*\brief Princess constructor   
		*\details Constructor of Princess
		*/
		Princess(const int &state);


		///GETTER
		/**
		*\brief Get the current state of Princess   
		*\return the current state
		*/
		inline int getState()const{ return m_state;}


		///METHODS
		/**
		*\brief move princess to the left  
		*\return boolean
		*/
		bool goLeft();

		/**
		*\brief move princess to the right  
		*\return boolean
		*/
		bool goRight();

		/**
		*\brief princess jump  
		*\return boolean
		*/
		bool jump();

		/**
		*\brief princess bend down  
		*\return boolean
		*/
		bool bendDown();

		/**
		*\brief princess come back to normal state 
		*\return boolean
		*/
		void backToNormalState();


		///DESTRUCTOR
		/**
		*\brief Default destructor   
		*\details Destructor by default of Princess
		*/
		~Princess();
	
};

#endif
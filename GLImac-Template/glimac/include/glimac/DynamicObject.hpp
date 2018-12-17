/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - DynamicObject.hpp 
 */

/**
 *\file DynamicObject.hpp
 *\author  {Audrey.C, Nina.DC, Lucas.L}
 *\date 17 december 2018
 *\brief class DynamicObject
*/

/**
 *\class DynamicObject
 *\brief
 *  
 */


#ifndef __DYNAMICOBJECT__
#define __DYNAMICOBJECT__


class DynamicObject{
	private:
		unsigned int m_relativePosition = 1; //!< Object position

	public:
		///CONSTRUCTOR
		/**
		*\brief DynamicObject default constructor   
		*\details Constructor by default of DynamicObject
		*/
		DynamicObject();

		/**
		*\brief DynamicObject constructor   
		*\details Constructor of DynamicObject
		*/
		DynamicObject(const unsigned int &relativePosition);

		///GETTER
		/**
		*\brief Get the current position of a DynamicObject   
		*\return the current m_relativePosition
		*/
		inline unsigned int getRelativePosition()const{ return m_relativePosition;}

		///SETTER
		/**
		*\brief Set the current position of a DynamicObject
		*/
		inline void setRelativePosition(const unsigned int &relativePosition){ m_relativePosition = relativePosition;}


		///DESTRUCTOR
		/**
		*\brief DynamicObject default Ddestructor   
		*\details Destructor by default of Bloc
		*/
		~DynamicObject();
	
};

#endif
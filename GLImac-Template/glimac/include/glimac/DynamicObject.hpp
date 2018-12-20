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

#include <glimac/Model.hpp>
#include <glimac/Object.hpp>

#ifndef __DYNAMICOBJECT__
#define __DYNAMICOBJECT__


class DynamicObject/*: public Object*/{
	protected:
		unsigned int m_relativePosition = 1; //!< Object position
		Model m_model;
		std::vector<double> m_position;

	public:
		///CONSTRUCTOR
		/**
		*\brief DynamicObject default constructor   
		*\details Constructor by default of DynamicObject
		*/
		DynamicObject();
		
		DynamicObject(Model &model);

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

		virtual void draw(Render &render, double &sizeBlock, glm::mat4 MVMatrix) =0;

		///DESTRUCTOR
		/**
		*\brief DynamicObject default Ddestructor   
		*\details Destructor by default of Bloc
		*/
		~DynamicObject(){};
	
};

#endif
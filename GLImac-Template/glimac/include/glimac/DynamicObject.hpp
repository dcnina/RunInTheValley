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
 *\brief Mother class for dynamics objects
 *  
 */

#include <glimac/Model.hpp>
#include <glimac/Object.hpp>

#ifndef __DYNAMICOBJECT__
#define __DYNAMICOBJECT__


class DynamicObject{
	protected:
		unsigned int m_relativePosition = 1; /*!< Object relative position */
		Model m_model; /*!< Object Model */
		std::vector<double> m_position; /*!< positions x, y, z */

	public:
		///CONSTRUCTOR
		/**
		*\brief DynamicObject default constructor   
		*\details Constructor by default of DynamicObject
		*/
		DynamicObject();
		
		/**
		*\brief DynamicObject Constructor
		*\details Constructor of DynamicObject
		*/
		DynamicObject(Model &model);


		///GETTER
		/**
		*\brief Get the current relative position of a DynamicObject   
		*\return the current m_relativePosition
		*/
		inline unsigned int getRelativePosition()const{ return m_relativePosition;}


		///SETTER
		/**
		*\brief Set the current relative position of a DynamicObject
		*\params relativePosition
		*/
		inline void setRelativePosition(const unsigned int &relativePosition){ m_relativePosition = relativePosition;}

		/**
		*\brief virtual function draw
		*\params render, sizeblock, MVMatrix
		*/
		virtual void draw(Render &render, double &sizeBlock, glm::mat4 MVMatrix, double &time) =0;

		///DESTRUCTOR
		/**
		*\brief DynamicObject default Ddestructor   
		*\details Destructor by default of DynamicObject
		*/
		~DynamicObject(){};
	
};

#endif
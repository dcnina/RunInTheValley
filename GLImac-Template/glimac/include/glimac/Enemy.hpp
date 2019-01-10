/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Enemy.hpp 
 */

/**
 *\file Enemy.hpp
 *\author  {Audrey.C, Nina.DC, Lucas.L}
 *\date 17 december 2018
 *\brief class Enemy
*/

/**
 *\class Enemy
 *\brief
 *  
 */



#ifndef __ENEMY__
#define __ENEMY__

#include <glimac/DynamicObject.hpp>
#include <glimac/Princess.hpp>

class Enemy : public DynamicObject{
	private:
		Princess *m_princess;

	public:
		///CONSTRUCTOR
		/**
		*\brief Default constructor   
		*\details Constructor by default of Enemy
		*/
		Enemy();

		/**
		*\brief Enemy Constructor
		*\details Constructor of Enemy
		*/
		//Enemy(const unsigned int &proximity);

		Enemy(Model &model, Princess *princess);

		///GETTERS
		/**
		*\brief Get position of the enemy
		*\return current position
		*/
		inline std::vector<double> getPosition()const{return m_position;};
		

		///SETTERS
		// /**
		// *\brief Set proximity of the enemy
		// */
		// inline void setProximity(const unsigned int &proximity) { m_proximity = proximity; }


		///METHODS

		/**
		*\brief redefinition of virtual function draw
		*/
		void draw(Render &render, double &sizeBlock, glm::mat4 MVMatrix, double &time);
		

		///DESTRUCTOR
		/**
		*\brief Default destructor   
		*\details Destructor by default of Enemy
		*/
		~Enemy();
	
};

#endif
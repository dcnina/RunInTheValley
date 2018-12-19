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

class Enemy : public DynamicObject{
	private:
		unsigned int m_proximity; //!< Enemy's level of proximity

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
		Enemy(const unsigned int &proximity);


		///GETTERS
		/**
		*\brief Get proximity of the enemy
		*\return current proximity
		*/
		inline unsigned int getProximity() const{ return m_proximity; }


		///SETTERS
		/**
		*\brief Set proximity of the enemy
		*/
		inline void setProximity(const unsigned int &proximity) { m_proximity = proximity; }


		///METHODS
		/**
		*\brief decrease distance of proximity of the enemy
		*/
		inline void decreaseProximity(){ m_proximity--; }

		/**
		*\brief increase distance of proximity of the enemy
		*/
		inline void increaseProximity(){ m_proximity++; }

		///DESTRUCTOR
		/**
		*\brief Default destructor   
		*\details Destructor by default of Enemy
		*/
		~Enemy();
	
};

#endif
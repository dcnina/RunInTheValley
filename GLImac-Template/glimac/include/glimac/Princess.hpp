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
#include <glimac/Bloc.hpp>

class Princess : public DynamicObject{
	private:
		int m_state = 1;//!< Princess state
		double m_timeChange = 0.0;

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
		Princess(Model &model);


		///GETTER
		/**
		*\brief Get the current state of Princess   
		*\return the current state
		*/
		inline int getState()const{ return m_state;}
		inline std::vector<double> getPosition()const {return m_position;};
		inline double getTimeChange() const{return m_timeChange;};

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
		bool jump(double &timeChange);

		/**
		*\brief princess bend down  
		*\return boolean
		*/
		bool bendDown(double &timeChange);

		/**
		*\brief princess come back to normal state 
		*\return boolean
		*/
		void backToNormalState(double &timeChange);

		/**
		*\brief detect collision which make the player lose
		*\details detect the collision of a block "P" or "O" or "V" with the princess 
		*\return 0 : nothing 
		*\return 1 : collision with a wall or an obstacle (princess die) or fall in a empty block
		*\return 2 : Bonus
		*\return 3 : Coins
		*/
		int collisionWithBlock(Bloc &bloc);
		void draw(Render &render, double &sizeBlock, glm::mat4 MVMatrix);
		///DESTRUCTOR
		/**
		*\brief Default destructor   
		*\details Destructor by default of Princess
		*/
		~Princess();
	
};

#endif
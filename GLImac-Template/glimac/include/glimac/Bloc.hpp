/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Bloc.hpp 
 */

/**
 *\file Bloc.hpp
 *\author  {Audrey.C, Nina.DC, Lucas.L}
 *\date 17 december 2018
 *\brief class Bloc
*/

/**
 *\class Bloc
 *\brief
 *  
 */


#ifndef __BLOC__
#define __BLOC__

#include <vector>


class Bloc : public Object{
	private:
		std::vector<std::vector<char>> m_listTypes; //!< List of blocks' types 

	public:
		///CONSTRUCTOR
		/**
		*\brief Default constructor   
		*\details Constructor by default of Bloc
		*/
		Bloc();

		/**
		*\brief Bloc Constructor
		*\details Constructor of Bloc
		*/
		Bloc(const std::vector<std::vector<char>> &listTypes);

		///DESTRUCTOR
		/**
		*\brief Default destructor   
		*\details Destructor by default of Bloc
		*/
		~Bloc();
	
};

#endif
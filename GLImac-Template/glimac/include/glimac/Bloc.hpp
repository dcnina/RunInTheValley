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
#include <glimac/Object.hpp>

class Bloc : public Object{
	private:
		/* voir pour utiliser glm::vec3 ...*/
		std::vector<std::vector<char>> m_matriceTypes; //!< Matrice of blocks' types
		int m_rows = 4; 
		int m_cols = 3; 

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
		Bloc(const std::vector<std::vector<char>> &matriceTypes);

		///GETTER
		inline std::vector<std::vector<char>> getMatriceTypes() const { return m_matriceTypes;}

		///SETTER


		///DESTRUCTOR
		/**
		*\brief Default destructor   
		*\details Destructor by default of Bloc
		*/
		~Bloc();
	
};

#endif
/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Map.hpp 
 */

/**
 *\file Map.hpp
 *\author  {Audrey.C, Nina.DC, Lucas.L}
 *\date 17 december 2018
 *\brief class Map
*/

/**
 *\class Map
 *\brief
 *  
 */


#ifndef __MAP__
#define __MAP__

#include <vector>
#include <glimac/Bloc.hpp>
#include <glimac/Enemy.hpp>

class Map{
	private:
		std::vector<Bloc> m_listBlocs; //!< List of blocks 
		std::vector<Enemy> m_listEnemies; //!< List of enemies



	public:
		Map();
		~Map();
	
};

#endif

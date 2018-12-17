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
		///CONSTRUCTOR
		/**
		*\brief Default constructor   
		*\details Constructor by default of Map
		*/
		Map();

		/**
		*\brief Map Constructor
		*\details Constructor of Map
		*/
		Map(const std::vector<Bloc> &listBlocs, const std::vector<Enemy> &listEnemies);

		/// GETTERS
		/**
		*\brief Get list of blocks of the map   
		*\return current list of blocks
		*/
		inline std::vector<Bloc> getListBlocs() const{ return m_listBlocs; }

		/**
		*\brief Get list of enemies of the map   
		*\return current list of enemies
		*/
		inline std::vector<Enemy> getListEnemies() const{ return m_listEnemies; }

		///SETTERS
		/**
		*\brief Set listBlocs of the map
		*/
		inline void setListBlocs(const std::vector<Bloc> &listBlocs) { 
			for(unsigned int i=0; i<listBlocs.size(); i++)
				m_listBlocs[i] = listBlocs[i];
		}

		/**
		*\brief Set listEnemies of the map
		*/
		inline void setListEnemies(const std::vector<Enemy> &listEnemies) { 
			for(unsigned int i=0; i<listEnemies.size(); i++)
				m_listEnemies[i] = listEnemies[i];
		}

		///METHODS
		/**
		*\brief initialise list of Blocks   
		*\details initialise list of blocks from file
		*\param file
		*/
		void initialiseListBlocFromFile(const char* filename);
		
		//DESTRUCTOR
		/**
		*\brief Default destructor   
		*\details Destructor by default of Bloc
		*/
		~Map();
	
};

#endif

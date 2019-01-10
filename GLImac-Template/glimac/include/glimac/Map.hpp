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
		std::vector<Bloc> m_listBlocs; /*!< List of blocks  */
		std::vector<Enemy> m_listEnemies; /*!< List of enemies */
		unsigned int m_listBlocsSize = 0; /*!< Size of the list of blocks */

	public:
		///CONSTRUCTOR
		/**
		*\brief Default constructor   
		*\details Constructor by default of Map
		*/
		Map();

		/**
		*\brief Map Constructor
		*\params char * filename
		*\details Constructor of Map
		*/
		Map(const char* filename);


		/**
		*\brief Map Copy Constructor
		*\params Map
		*\details Copy Constructor of Map
		*/
		Map(const Map& map);

		/**
		*\brief create a random level file   
		*\params int length of the level
		*/
		static void randomMap(const int length);

		/// GETTERS
		/**
		*\brief Get list of blocks of the map   
		*\return current list of blocks
		*/
		inline std::vector<Bloc> getListBlocs() const{ return m_listBlocs;}

		/**
		*\brief Get list of enemies of the map   
		*\return current list of enemies
		*/
		inline std::vector<Enemy> getListEnemies() const{ return m_listEnemies;}

		/**
		*\brief Get size of the list of blocks of the map   
		*\return size of the current list of blocks
		*/
		inline unsigned int getListBlocsSize() const{ return m_listBlocsSize;}


		///SETTERS
		/**
		*\brief Set listBlocs of the map
		*\params listBlocs
		*/
		inline void setListBlocs(const std::vector<Bloc> &listBlocs) { 
			for(unsigned int i=0; i<listBlocs.size(); i++)
				m_listBlocs[i] = listBlocs[i];
		}

		/**
		*\brief Set listEnemies of the map
		*\params listEnemies
		*/
		inline void setListEnemies(const std::vector<Enemy> &listEnemies) { 
			for(unsigned int i=0; i<listEnemies.size(); i++)
				m_listEnemies[i] = listEnemies[i];
		}

		/**
		*\brief Set the size of the listBlocs of the map
		*\params size
		*/
		inline void setListBlocsSize(const unsigned int size) { m_listBlocsSize = size;}

		///METHODS
		/**
		*\brief initialise list of Blocks   
		*\details initialise list of blocks from file
		*\params file
		*/
		void initialiseListBlocFromFile(const char* filename);

		/**
		*\brief create list of Blocks   
		*\params file 
		*\return std::vector<Bloc> (list of blocks)
		*/
		std::vector<Bloc> createListBlocFromFile(const char* &filename);
		
		/**
		*\brief print elements of the map   
		*\details print the current elements of the map 
		*/
		void printMap();

		/**
		*\brief add a block to listBlocs
		*\params bloc to add
		*/
		inline void addBlocToList(const Bloc &bloc){ 
			m_listBlocs.push_back(bloc);
			m_listBlocsSize++;
		};

		/**
		*\brief add an enemy to listEnemies
		*\params enemy to add
		*/
		inline void addEnemyToList(const Enemy &enemy){ m_listEnemies.push_back(enemy);};

		/**
		*\brief delete a block of listBlocs at a given index
		*\params index, princessState, princessRelativePosition
		*/
		void convertBlocTypeToEmpty(const unsigned int &index, const int &princessState, const int &princessRelativePosition);
		
		/**
		*\brief delete a block of listBlocs at a given index
		*\params index
		*/
		inline void deleteEnemyOfList(const unsigned int index){ m_listEnemies.erase(m_listEnemies.begin()+index);};


		//DESTRUCTOR
		/**
		*\brief Default destructor   
		*\details Destructor by default of Map
		*/
		~Map();
	
};

#endif

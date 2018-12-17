/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Map.cpp 
 */


#include <glimac/Map.hpp>
#include <iostream>
#include <fstream>

Map::Map(){
	for(unsigned int i = 0; i < m_listBlocs.size(); i++)
		m_listBlocs[i] = Bloc();

	for(unsigned int i = 0; i < m_listEnemies.size(); i++)
		m_listEnemies[i] = Enemy();
}

Map::Map(const std::vector<Bloc> &listBlocs, const std::vector<Enemy> &listEnemies){
	for(unsigned int i = 0; i < listBlocs.size(); i++)
		m_listBlocs[i] = listBlocs[i];

	for(unsigned int i = 0; i < listEnemies.size(); i++)
		m_listEnemies] = listEnemies[i];
}

void Map::initialiseListBlocFromFile(const char* filename){
	/*fstream file;

	file.open(filename, ios::in);

	if(!file){
		////////////exception
		std::cout << "error in opening file " << std::endl;
		return 0;
	}

	char ch;
	int nbLines = 0;

	nbLines = fgetc(file);

	for(int i = 0; i<nbLines; i++){
		
	}*/
}


Map::~Map(){}
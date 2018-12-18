/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Map.cpp 
 */


#include <glimac/Map.hpp>
#include <iostream>
#include <fstream> 
#include <vector>
#include <glimac/Bloc.hpp>

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
		m_listEnemies[i] = listEnemies[i];
}

void Map::initialiseListBlocFromFile(const char* &filename){
	//std::ifstream file;
	FILE *file;
	file = fopen(filename, "r");

	if(!file){
		std::cerr << "erreur chargement fichier : " << filename << std::endl;
		exit(EXIT_FAILURE);
	}

	// unsigned int listSize;
	Bloc blocType;
	// file >> listSize;
	while(! feof(file)){
		blocType.createBloc(file);
		m_listBlocs.push_back(blocType);
	}

	fclose(file);
}


Map::~Map(){}
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
		addBlocToList(Bloc());

	for(unsigned int i = 0; i < m_listEnemies.size(); i++)
		addEnemyToList(Enemy());
}

Map::Map(const char* filename){
	this->initialiseListBlocFromFile(filename);
}

void Map::initialiseListBlocFromFile(const char* filename){
	FILE *file;
	file = fopen(filename, "r");

	if(!file){
		std::cerr << "erreur chargement fichier : " << filename << std::endl;
		exit(EXIT_FAILURE);
	}

	while(!feof(file)){
		int index;
		char type, direction;
		fscanf(file,"%d",&index);
		std::vector<std::vector<char>> tmpMatrix;
		for (int i = 0; i < ROWS; i++){
			std::vector<char> vectTmp;
			for (int j = 0; j < COLS; j++){
				fscanf(file," %c",&type);
				vectTmp.push_back(type);
			}
			tmpMatrix.push_back(vectTmp);
		}
		fscanf(file," %c\n",&direction);
		Bloc bloc(tmpMatrix, direction, index);
		addBlocToList(bloc);
	}
	fclose(file);
}

void Map::convertBlocTypeToEmpty(const unsigned int &index, const int &princessState, const int &princessRelativePosition){ 
	m_listBlocs[index].setMatrixTypesElement('E', princessState, princessRelativePosition);
};


void Map::printMap(){
	for(int i = 0; i<m_listBlocs.size();i++){
		m_listBlocs[i].printBlock();
		std::cout << std::endl;
	}
}


Map::~Map(){}
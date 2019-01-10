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
#include <glimac/Exception.hpp>

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
		THROW_EXCEPTION("Loading file failed");
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



void Map::randomMap(const int length){
	/*int lastTurn = 0, lastObst = 0, lastHole = 0;
	bool firstTurn = true;
	char typeLastTurn = 'S';
 
    std::ofstream file;
    file.open("./assets/map/map.txt", std::ofstream::out);


	std::vector<char>  niv1;
	niv1.push_back('E'); 
	niv1.push_back('E'); 
	niv1.push_back('E'); 

	std::vector<char>  niv2; 
	niv2.push_back('E'); 
	niv2.push_back('E'); 
	niv2.push_back('E');

	std::vector<char>  niv3; 
	niv3.push_back('E'); 
	niv3.push_back('E'); 
	niv3.push_back('E');

	std::vector<char> niv4; 
	niv4.push_back('F'); 
	niv4.push_back('F'); 
	niv4.push_back('F');

    if(file) 
    {    
		for(int i =1; i<length;i++){
			int randomNumber = (std::rand()%100) + 1;
			if(randomNumber<30 && lastHole-i<-2){
				int randomPlacement = (std::rand()%3);

				niv4[randomPlacement] = 'E';
				lastHole = i;
			}
			else{
				niv4[0] = niv4[1] = niv4[2] = 'F';
			}

			if(randomNumber>30 && randomNumber<50 && i-lastTurn > 5){
				if(firstTurn){
					firstTurn = false;
					int randomDir = (std::rand()%2);
					if(randomDir == 1){
						typeLastTurn = 'R';
					}
					else{
						typeLastTurn = 'L';
					}
				}
				else{
					if(typeLastTurn == 'R')
						typeLastTurn = 'L';
					else
						typeLastTurn = 'R';
				}
				lastTurn = i;
			}

			if(lastTurn = i)
				file << i << " " << "EEE" <<  " " << "EEE" << " " << "EEE" << " "<< niv4[0]<< niv4[1]<< niv4[2] << " " << typeLastTurn << std::endl;
			else	
				file << i << " " << "EEE" <<  " " << "EEE" << " " << "EEE" << " "<< niv4[0]<< niv4[1]<< niv4[2] << " " << 'S' << std::endl;
			
		}
    }
    else{
        std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
    }*/
}

void Map::convertBlocTypeToEmpty(const unsigned int &index, const int &princessState, const int &princessRelativePosition){ 
	if(m_listBlocs[index].getMatrixTypesElement(princessState, princessRelativePosition) != 'O')
		m_listBlocs[index].setMatrixTypesElement('E', princessState, princessRelativePosition);
}


void Map::printMap(){
	for(int i = 0; i<m_listBlocs.size();i++){
		m_listBlocs[i].printBlock();
		std::cout << std::endl;
	}
}


Map::~Map(){}
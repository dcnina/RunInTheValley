/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Map.cpp 
 */


#include <glimac/Map.hpp>
#include <iostream>
#include <fstream> 
#include <vector>
#include <ctime>
#include <cmath>
#include <chrono>
#include <random>
#include <algorithm>
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

Map::Map(const Map& map){
	m_listBlocs = map.m_listBlocs;
	m_listEnemies = map.m_listEnemies;
	m_listBlocsSize = map.m_listBlocsSize;
}

void Map::initialiseListBlocFromFile(const char* filename){
   	
   	std::string content;
	std::ifstream file;
	char type,direction;
	int index;

	file.open(filename, std::fstream::in);

	if(!file.is_open())
		THROW_EXCEPTION("Loading file failed");
	else{
		while(getline(file, content)) 
	    {
	        std::istringstream line(content);
	        line >> index;
			std::vector<std::vector<char>> tmpMatrix;
	        for (int i = 0; i < ROWS; i++){
				std::vector<char> vectTmp;
				for (int j = 0; j < COLS; j++){
					line >> type;
					vectTmp.push_back(type);
				}
				tmpMatrix.push_back(vectTmp);
			}
			line >> direction;
			Bloc bloc(tmpMatrix, direction, index);
			addBlocToList(bloc);
	   	}
		file.close();
	}
}



void Map::randomMap(const int length){
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> uniformInt100Distribution(0,100);
    std::uniform_int_distribution<int> uniformInt01Distribution(0,1);
    std::uniform_int_distribution<int> uniformInt1200Distribution(1,200);
    std::uniform_int_distribution<int> uniformInt04Distribution(0,4);
    std::uniform_int_distribution<int> uniformInt18Distribution(1,8);
    std::uniform_int_distribution<int> uniformInt19Distribution(1,9);
    std::uniform_int_distribution<int> uniformInt17Distribution(1,7);
    int lastTurn = 0, lastObst = 0, lastHole = 0, lastHalf = 0;
    bool firstTurn = true;
    char typeLastTurn = 'S';
    char typeCurrentTurn = 'S';
    int randomInt2;
    int i;
    std::ofstream file;
    file.open("./assets/map/map.txt", std::ios::out);


    std::vector<char> niv123;
    for (int i = 0; i < 9; i++)
            niv123.push_back('E');
    std::vector<char> niv4;
     for (int i = 0; i < 3; i++)
            niv4.push_back('E');

    if (file){
        for(i = 1; i<length;i++){
            int randomNumber = uniformInt100Distribution(generator);
            /* NIVEAU 4 */
            if (randomNumber < 30 && lastHole-i<-2 && i-lastObst >= 2){
                int randomPlacement = uniformInt17Distribution(generator);
                switch (randomPlacement) {
                    case 1: niv4[0] = 'E'; niv4[1] = 'E'; niv4[2] = 'E'; break;
                    case 2:  niv4[0] = 'E'; niv4[1] = 'F'; niv4[2] = 'E'; break;
                    case 3: niv4[0] = 'E'; niv4[1] = 'E'; niv4[2] = 'F'; break;
                    case 4: niv4[0] = 'F'; niv4[1] = 'E'; niv4[2] = 'E'; break;
                    case 5: niv4[0] = 'F'; niv4[1] = 'F'; niv4[2] = 'E'; break;
                    case 6: niv4[0] = 'E'; niv4[1] = 'F'; niv4[2] = 'F'; break;
                    case 7: niv4[0] = 'F'; niv4[1] = 'E'; niv4[2] = 'F'; break;
                }
                lastHole = i;
            }

            /* TURN */
            if (30 < randomNumber && randomNumber <= 60){
                if (firstTurn == true && i >= 4){
                    firstTurn = false;
                    int randomDir = uniformInt01Distribution(generator);
                    if (randomDir == 1)
                        typeLastTurn = 'R';
                    else
                        typeLastTurn = 'L';
                    lastTurn = i;
                }
                else if (i-lastTurn >= 5){
                    if (typeLastTurn == 'R')
                        typeLastTurn = 'L';
                    else
                        typeLastTurn = 'R';
                    lastTurn = i;
                }
            }

            if (lastTurn == i)
                typeCurrentTurn = typeLastTurn;
            else
                typeCurrentTurn = 'S';

            /* NIVEAU 1-2-3 */
            int randomInt = uniformInt04Distribution(generator);

            if (randomInt == 1){ /* Obstacle */
                if (i-lastObst >= 5){
                    randomInt2 = uniformInt18Distribution(generator);
                    switch (randomInt2) {
                        case 1: file << i << " " << "EEE" <<  " " << "EEE"  << " " << "EEO" << " "<< "FFF" << " " << typeCurrentTurn<< std::endl; break;
                        case 2: file << i << " " << "EEE" <<  " " << "EEE"  << " " << "EOE" << " "<< "FFF" << " " << typeCurrentTurn<< std::endl; break;
                        case 3: file << i << " " << "EEE" <<  " " << "EEE"  << " " << "OEE" << " "<< "FFF" << " " << typeCurrentTurn<< std::endl; break;
                        case 4: file << i << " " << "EEE" <<  " " << "EEE"  << " " << "OOE" << " "<< "FFF" << " " << typeCurrentTurn<< std::endl; break;
                        case 5: file << i << " " << "EEE" <<  " " << "EEE"  << " " << "EOO" << " "<< "FFF" << " " << typeCurrentTurn<< std::endl; break;
                        case 6: file << i << " " << "OOO" <<  " " << "OOO"  << " " << "OEO" << " "<< "FFF" << " " << typeCurrentTurn<< std::endl; break;
                        case 7: file << i << " " << "OEO" <<  " " << "OEO"  << " " << "OOO" << " "<< "FFF" << " " << typeCurrentTurn<< std::endl; break;
                        case 8: file << i << " " << "EEE" <<  " " << "EEE"  << " " << "OOO" << " "<< "FFF" << " " << typeCurrentTurn<< std::endl; break;
                    }
                    lastObst = i;
                }
                else
                    file << i << " " << "EEE" <<  " " << "EEE"  << " " << "EEE" << " "<< niv4[0]<< niv4[1]<< niv4[2] << " " << typeCurrentTurn<< std::endl;
            }
            else if (randomInt == 2 ){
                if (i-lastObst >= 5){
                    randomInt2 = uniformInt18Distribution(generator);
                    switch (randomInt2) {
                        case 1: file << i << " " << "EEE" <<  " " << "EEE"  << " " << "EEH" << " "<< "FFF" << " " << typeCurrentTurn<< std::endl; break;
                        case 2: file << i << " " << "EEE" <<  " " << "EEE"  << " " << "EHE" << " "<< "FFF" << " " << typeCurrentTurn<< std::endl; break;
                        case 3: file << i << " " << "EEE" <<  " " << "EEE"  << " " << "HEE" << " "<< "FFF" << " " << typeCurrentTurn<< std::endl; break;
                        case 4: file << i << " " << "EEE" <<  " " << "EEE"  << " " << "HHE" << " "<< "FFF" << " " << typeCurrentTurn<< std::endl; break;
                        case 5: file << i << " " << "EEE" <<  " " << "EEE"  << " " << "EHH" << " "<< "FFF" << " " << typeCurrentTurn<< std::endl; break;
                    }
                    lastObst = i;
                }
                else
                    file << i << " " << "EEE" <<  " " << "EEE"  << " " << "EEE" << " "<< niv4[0]<< niv4[1]<< niv4[2] << " " << typeCurrentTurn<< std::endl;
            }
            else if (randomInt == 3){ /* COINS */
                randomInt2 = uniformInt18Distribution(generator);
                switch (randomInt2) {
                    case 1: file << i << " " << "EEE" <<  " " << "EEE"  << " " << "EEC" << " "<< niv4[0]<< niv4[1]<< niv4[2] << " " << typeCurrentTurn<< std::endl; break;
                    case 2: file << i << " " << "EEE" <<  " " << "EEE"  << " " << "CEE" << " "<< niv4[0]<< niv4[1]<< niv4[2] << " " << typeCurrentTurn<< std::endl; break;
                    case 3: file << i << " " << "EEE" <<  " " << "EEE"  << " " << "ECE" << " "<< niv4[0]<< niv4[1]<< niv4[2] << " " << typeCurrentTurn<< std::endl; break;
                    case 4: file << i << " " << "EEE" <<  " " << "EEC"  << " " << "EEE" << " "<< niv4[0]<< niv4[1]<< niv4[2] << " " << typeCurrentTurn<< std::endl; break;
                    case 5: file << i << " " << "EEE" <<  " " << "ECE"  << " " << "EEE" << " "<< niv4[0]<< niv4[1]<< niv4[2] << " " << typeCurrentTurn<< std::endl; break;
                    case 6: file << i << " " << "EEE" <<  " " << "CEE"  << " " << "EEE" << " "<< niv4[0]<< niv4[1]<< niv4[2] << " " << typeCurrentTurn<< std::endl; break;
                    case 7: file << i << " " << "CEE" <<  " " << "CEE"  << " " << "EEE" << " "<< niv4[0]<< niv4[1]<< niv4[2] << " " << typeCurrentTurn<< std::endl; break;
                    case 8: file << i << " " << "ECE" <<  " " << "CEE"  << " " << "EEE" << " "<< niv4[0]<< niv4[1]<< niv4[2] << " " << typeCurrentTurn<< std::endl; break;
                    case 9: file << i << " " << "EEC" <<  " " << "CEE"  << " " << "EEE" << " "<< niv4[0]<< niv4[1]<< niv4[2] << " " << typeCurrentTurn<< std::endl; break;
                }
            }
            else{
                randomInt2 = uniformInt19Distribution(generator);
                switch (randomInt2) {
                    case 1: file << i << " " << "EEE" <<  " " << "EEE"  << " " << "EEB" << " "<< niv4[0]<< niv4[1]<< niv4[2] << " " << typeCurrentTurn<< std::endl; break;
                    case 2: file << i << " " << "EEE" <<  " " << "EEE"  << " " << "BEE" << " "<< niv4[0]<< niv4[1]<< niv4[2] << " " << typeCurrentTurn<< std::endl; break;
                    case 3: file << i << " " << "EEE" <<  " " << "EEE"  << " " << "EBE" << " "<< niv4[0]<< niv4[1]<< niv4[2] << " " << typeCurrentTurn<< std::endl; break;
                    case 4: file << i << " " << "EEE" <<  " " << "EEB"  << " " << "EEE" << " "<< niv4[0]<< niv4[1]<< niv4[2] << " " << typeCurrentTurn<< std::endl; break;
                    case 5: file << i << " " << "EEE" <<  " " << "EBE"  << " " << "EEE" << " "<< niv4[0]<< niv4[1]<< niv4[2] << " " << typeCurrentTurn<< std::endl; break;
                    case 6: file << i << " " << "EEE" <<  " " << "BEE"  << " " << "EEE" << " "<< niv4[0]<< niv4[1]<< niv4[2] << " " << typeCurrentTurn<< std::endl; break;
                    case 7: file << i << " " << "BEE" <<  " " << "BEE"  << " " << "EEE" << " "<< niv4[0]<< niv4[1]<< niv4[2] << " " << typeCurrentTurn<< std::endl; break;
                    case 8: file << i << " " << "EBE" <<  " " << "BEE"  << " " << "EEE" << " "<< niv4[0]<< niv4[1]<< niv4[2] << " " << typeCurrentTurn<< std::endl; break;
                    case 9: file << i << " " << "EEB" <<  " " << "BEE"  << " " << "EEE" << " "<< niv4[0]<< niv4[1]<< niv4[2] << " " << typeCurrentTurn<< std::endl; break;
                }
            }
        }
        file.close();
    }
    else{
        std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
    }
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
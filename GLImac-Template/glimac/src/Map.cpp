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
		m_listEnemies[i] = listEnemies[i];
}

void Map::initialiseListBlocFromFile(const char* filename){
	ifstream file(filename, ios::in);

	if(file){
		std::string contenu;
		int nbBlocks = 0;
		while(file.ignore(std::numeric_limits<int>::max(), '\n')){
			++nbBlocks;
		}		
	}
	std::cout << "nb blocks : " << nbBlocks << std::endl;

	// if(file){
	// 	char 
	// }

	// char ch;
	// int nbLines = 0;

	// nbLines = fgetc(file);

	// for(int i = 0; i<nbLines; i++){
		
	// }
if(fichier)  // si l'ouverture a fonctionné

        {

                string contenu;  // déclaration d'une chaîne qui contiendra la ligne lue

                getline(fichier, contenu);  // on met dans "contenu" la ligne

                cout << contenu;  // on affiche la ligne

 

                fichier.close();

        }

if(fichier)

{
    string ligne;

    while(getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "contenu"

    {

        cout << ligne << endl;  // on l'affiche

    }

}

if(fichier)

        {

                char caractere;  // notre variable où sera stocké le caractère

                fichier.get(caractere);  // on lit un caractère et on le stocke dans caractere

                cout << caractere;  // on l'affiche

 

                fichier.close();

        }




}


Map::~Map(){}
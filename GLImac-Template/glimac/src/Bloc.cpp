/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Bloc.cpp 
 */

#include <iostream>
#include <glimac/Bloc.hpp>
#include <stdio.h>



Bloc::Bloc()
:m_direction('T'), m_index(0)
{
	for (int i = 0; i < ROWS; i++){
		std::vector<char> vectTmp;
		for (int j = 0; j < COLS; j++)
			vectTmp.push_back('V');
		m_matrixTypes.push_back(vectTmp);
	}
}

Bloc::Bloc(const std::vector<std::vector<char>> &matrixTypes, const char &direction, const int &index)
:m_direction(direction), m_index(index)
{
	for (int i = 0; i < ROWS; i++){
		std::vector<char> vectTmp;
		for (int j = 0; j < COLS; j++)
			vectTmp.push_back(matrixTypes[i][j]);
		m_matrixTypes.push_back(vectTmp);
	}
}


void Bloc::printBlock(){
	for(int i = 0; i < ROWS; i++){	
		for(int j = 0; j < COLS; j++)
			std::cout << m_matrixTypes[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << "Type: " << m_direction << " Index: " << m_index << std::endl;
}

Bloc::~Bloc(){}
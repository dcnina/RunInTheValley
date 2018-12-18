/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Bloc.cpp 
 */


#include <glimac/Bloc.hpp>
#include <stdio.h>



Bloc::Bloc()
:m_direction('T'), m_index(0)
{
	for (int i = 0; i < m_rows; i++){
		for (int j = 0; j < m_cols; j++)
			m_matrixTypes[i][j] = 'V';
	}
}

Bloc::Bloc(const std::vector<std::vector<char>> &matrixTypes, const char &direction, const int &index)
:m_direction(direction), m_index(index)
{
	for (int i = 0; i < m_rows; i++){
		for (int j = 0; j < m_cols; j++)
			m_matrixTypes[i][j] = matrixTypes[i][j];
	}
}

Bloc Bloc::createBloc(FILE* &file){
	Bloc blocType;

	fscanf(file, "%d %c%c%c %c%c%c %c%c%c %c%c%c %c", blocType.m_index, blocType.m_matrixTypes[0][0], blocType.m_matrixTypes[0][1], blocType.m_matrixTypes[0][2], blocType.m_matrixTypes[1][0], blocType.m_matrixTypes[1][1], blocType.m_matrixTypes[1][2], blocType.m_matrixTypes[2][0], blocType.m_matrixTypes[2][1], blocType.m_matrixTypes[2][2], blocType.m_direction);

	return blocType;
}


Bloc::~Bloc(){}
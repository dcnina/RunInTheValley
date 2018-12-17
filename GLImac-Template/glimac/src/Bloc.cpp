/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Bloc.cpp 
 */


#include <glimac/Bloc.hpp>


Bloc::Bloc(){
	for (int i = 0; i < m_rows; i++){
		for (int j = 0; j < m_cols; j++)
			m_matriceTypes[i][j] = 'V';
	}
}

Bloc::Bloc(const std::vector<std::vector<char>> &matriceTypes){
	for (int i = 0; i < m_rows; i++){
		for (int j = 0; j < m_cols; j++)
			m_matriceTypes[i][j] = matriceTypes[i][j];
	}
}

Bloc::~Bloc(){}
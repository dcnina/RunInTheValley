/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Bloc.cpp 
 */

#include <iostream>
#include <glimac/Bloc.hpp>
#include <stdio.h>
#define SIZEX 0.33333333
#define SIZEY 1.0


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

void Bloc::drawBlock(std::vector<Model> &listModel, glm::mat4 viewMatrix, Render render,glm::mat4 MVMatrix){

    glm::mat4 newMVMatrix;
    MVMatrix = glm::scale(MVMatrix,glm::vec3(0.333,1.0,1.0));
    for(int i = ROWS-1; i>=0; i--){
    	for(int j = 0; j<COLS;j++){
    		MVMatrix = glm::translate(MVMatrix, glm::vec3(j*SIZEX, (ROWS-(i+1))*SIZEY, 0));
        	
        	render.sendMatrix(MVMatrix);
        	switch(m_matrixTypes[i][j]){
        		case 'B': 	//Bonus
    				listModel[2].draw();
        			break;
        		case 'F': 	//Full
    				listModel[1].draw();
        			break;
        		case '0':	//Obstacle
    				listModel[1].draw();
        			break;
        		case 'C':	//Coins
    				newMVMatrix = glm::rotate(MVMatrix, float(M_PI/2.0), glm::vec3(0, M_PI/2.0, 0));
        			render.sendMatrix(newMVMatrix);
    				listModel[3].draw();
        			break;
        		default: 	//Empty
        			break;
        	}
    	}
    }
}

Bloc::~Bloc(){}
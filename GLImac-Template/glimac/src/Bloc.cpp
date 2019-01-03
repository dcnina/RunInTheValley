/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Bloc.cpp 
 */

#include <iostream>
#include <glimac/Bloc.hpp>
#include <stdio.h>
#define SIZEX 0.33333
#define SIZEY 1.0


Bloc::Bloc()
:m_direction('S'), m_index(0)
{
	for (int i = 0; i < ROWS; i++){
		std::vector<char> vectTmp;
		for (int j = 0; j < COLS; j++)
			vectTmp.push_back('E');
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

void Bloc::drawBlock(std::vector<Model> &listModel, glm::mat4 viewMatrix, Render render,glm::mat4 MVMatrix, double time){

    glm::mat4 newMVMatrix, tmpMVMatrix;
    MVMatrix = glm::scale(MVMatrix,glm::vec3(SIZEX,1.0,1.0));
    MVMatrix = glm::translate(MVMatrix, glm::vec3(-1.0, 0.0, 0));
    render.sendMatrix(MVMatrix);

    for(int i = ROWS-1; i>=0; i--){
        if(i == ROWS-1)
            MVMatrix = glm::translate(MVMatrix,glm::vec3(0, SIZEY, 0));
        else{
            MVMatrix = glm::translate(MVMatrix,glm::vec3(0, SIZEY/3.0, 0));    
        }
        tmpMVMatrix = MVMatrix; 
    	for(int j = 0; j<COLS;j++){
        	switch(m_matrixTypes[i][j]){
        		case 'B': 	//Bonus
                    newMVMatrix = glm::scale(tmpMVMatrix,glm::vec3(3.0,1.0,1.0));
                    newMVMatrix = glm::rotate(newMVMatrix, float(time*0.5f),glm::vec3(0.0,1.0,0.0));
                    render.sendMatrix(newMVMatrix);
    				listModel[2].draw();
        			break;
        		case 'F': 	//Full
                    render.sendMatrix(tmpMVMatrix);
    				listModel[1].draw();
        			break;
        		case 'O':	//Obstacle
                    if(i != ROWS-1){
                        newMVMatrix = glm::scale(tmpMVMatrix,glm::vec3(1.0,SIZEY/3.0,1.0));
                        newMVMatrix = glm::translate(newMVMatrix,glm::vec3(0, SIZEY, 0)); 
                        render.sendMatrix(newMVMatrix);
                    }
                    else{
                        render.sendMatrix(tmpMVMatrix);
                    }
    				listModel[4].draw();
        			break;
        		case 'C':	//Coins
                    newMVMatrix = glm::scale(tmpMVMatrix,glm::vec3(3.0,1.0,1.0));
                    newMVMatrix = glm::rotate(newMVMatrix, float(time*0.5f),glm::vec3(0.0,1.0,0.0));
                    render.sendMatrix(newMVMatrix);
    				listModel[3].draw();
        			break;
        		default: 	//Empty
        			break;
        	}
            tmpMVMatrix = glm::translate(tmpMVMatrix, glm::vec3(1.0, 0.0/*(ROWS-(i+1))*SIZEY*/, 0));
    	}
    }
}

Bloc::~Bloc(){}
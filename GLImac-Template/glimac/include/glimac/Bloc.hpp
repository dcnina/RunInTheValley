/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Bloc.hpp 
 */

/**
 *\file Bloc.hpp
 *\author  {Audrey.C, Nina.DC, Lucas.L}
 *\date 17 december 2018
 *\brief class Bloc
*/

/**
 *\class Bloc
 *\brief
 *  
 */


#ifndef __BLOC__
#define __BLOC__

#include <vector>
#include <glimac/Object.hpp>
#include <glimac/Model.hpp>
#include <glimac/Render.hpp>
#include <stdio.h>
#define ROWS 4 
#define COLS 3 

class Bloc {
	private:
		std::vector< std::vector<char> > m_matrixTypes; /*!< Matrix of blocks' types */
		char m_direction; /*!< Direction of the block (L, R or S) */
		int m_index; /*!< Index of the block */

	public:
		///CONSTRUCTOR
		/**
		*\brief Default constructor   
		*\details Constructor by default of Bloc
		*/
		Bloc();

		/**
		*\brief Bloc Constructor
		*\details Constructor of Bloc
		*/
		Bloc(const std::vector<std::vector<char>> &matrixTypes, const char &direction, const int &index);

		///GETTER
		/**
		*\brief Get matrix of the block   
		*\return current matrix of types of block
		*/
		inline std::vector<std::vector<char>> getMatrixTypes() const { return m_matrixTypes;}

		/**
		*\brief Get a specific element of block's matrix
		*\params index i and j to select the position of the element in the matrix   
		*\return an element of the matrix of types of block
		*/
		inline char getMatrixTypesElement(const int &i, const int &j) const{return m_matrixTypes[i][j];}
		
		/**
		*\brief Get direction of the block   
		*\return current direction
		*/
		inline char getDirection() const { return m_direction;}
		
		/**
		*\brief Get index of the block   
		*\return current index
		*/
		inline int getIndex() const { return m_index;};
		

		///SETTER
		/**
		*\brief Set an element of the matrix of type
		*/
		inline void setMatrixTypesElement(const char &type, const int &i, const int &j) { 
			m_matrixTypes[i][j] = type;
		}

		/**
		*\brief Set direction of the block
		*/
		inline void setDirection(const char &direction) { m_direction = direction; }


		///METHODS
		/**
		*\brief Print the type and index of all elements of the block's matrix
		*/
		void printBlock();

		/**
		*\brief redefinition of virtual function draw 
		*/
		void draw(Render &render, double &sizeBlock);

		/**
		*\brief draw the blocks
		*\params list of models, viewMatrix, render, MVMatrix   
		*/
		void drawBlock(std::vector<Model>  &listModel, glm::mat4 viewMatrix, Render render,glm::mat4 MVMatrix, double time);

		///DESTRUCTOR
		/**
		*\brief Default destructor   
		*\details Destructor by default of Bloc
		*/
		~Bloc();
};

#endif
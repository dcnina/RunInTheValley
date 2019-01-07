/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Menu.hpp 
 */

/**
 *\file Menu.hpp
 *\author  {Audrey.C, Nina.DC, Lucas.L}
 *\date 17 december 2018
 *\brief class Menu
*/

/**
 *\class Menu
 *\brief Menu
 *  
 */

#include <string>
#include <iostream>
#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <GL/gl.h>
#include <vector>
#include <glimac/Program.hpp>
#include <glimac/Texture2D.hpp>
#include <glimac/Button.hpp>

#ifndef __MENU__
#define __MENU__


class Menu{
	private:
		Texture2D *m_menuTexture; /*!< menu Texture */
		std::vector<Button*> m_buttons; /*!< list of buttons of the menu */

	public:
		///CONSTRUCTOR
		/**
		*\brief Default constructor   
		*\details Constructor by default of Menu
		*/
		Menu(Texture2D *texture);


		///GETTERS
		/**
		*\brief get the buttons' list of the menu
		*\return current list of buttons
		*/
		inline std::vector<Button*> getButtons(){
			return m_buttons;
		}


		///METHODS
		/**
		*\brief initialize the texture 
		*\params image filename
		*/
		void initializeMenu(const std::string bgImage);

		/**
		*\brief create and bind the menu vao 
		*/
		void createMenu();

		/**
		*\brief add a button
		*\params button to add
		*/
		inline void addButton(Button *button){
			m_buttons.push_back(button);
		}

		/**
		*\brief redefinition of virtual function draw
		*/
		void drawMenu();
		

		///DESTRUCTOR
		/**
		*\brief Default destructor   
		*\details Destructor by default of Menu
		*/
		~Menu();
	
};


#endif
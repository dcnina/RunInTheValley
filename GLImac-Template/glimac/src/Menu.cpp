/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Menu.cpp 
 */


#include <glimac/Menu.hpp>
#include <glimac/Image.hpp>
#include <glimac/glm.hpp>
#include <algorithm>

using namespace glimac;



Menu::Menu(Texture2D *texture)
 :m_menuTexture(texture){}

void Menu::drawMenu(){
	glUniformMatrix3fv(m_menuTexture->getUModelMatrix(), 1, GL_FALSE, glm::value_ptr(glm::mat3()));
    
    m_menuTexture->drawTexture2D();
    auto drawButton = [](Button& button) { button.drawButton(); };
    for_each(m_buttons.begin(), m_buttons.end(), drawButton);
   // m_menuTexture.drawTexture2D();
    //glUniformMatrix3fv(m_menuTexture.getUModelMatrix(), 1, GL_FALSE, glm::value_ptr(glm::mat3()));
   
    //m_buttons[2].drawButton();
	//glUniformMatrix3fv(m_menuTexture.getUModelMatrix(), 1, GL_FALSE, glm::value_ptr(glm::mat3()));
    
}


Menu::~Menu(){}


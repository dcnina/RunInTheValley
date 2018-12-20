/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Menu.cpp 
 */


#include <glimac/Menu.hpp>
#include <glimac/Image.hpp>
#include <glimac/glm.hpp>

using namespace glimac;



Menu::Menu(const Texture2D &texture)
 :m_menuTexture(Texture2D(texture)){}

GLuint Menu::initializeMenu(const std::string bgImage){
    GLuint vboMenu = m_menuTexture.initializeTexture2D(bgImage);
    return vboMenu;
}
GLuint Menu::createMenu(const GLuint &vbo){
    GLuint vaoMenu = m_menuTexture.createAndBindVao(vbo);    
    return vaoMenu;
}

void Menu::drawBackground(const GLuint &vao){
    m_menuTexture.drawTexture2D(vao);
}

void Menu::freeMenuTexture(const GLuint &vao, const GLuint &vbo){
    m_menuTexture.freeTexture2D(vao, vbo);
}

Menu::~Menu(){}


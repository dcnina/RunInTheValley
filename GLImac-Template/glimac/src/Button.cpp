/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Button.cpp 
 */


#include <glimac/Button.hpp>
#include <glimac/Image.hpp>
#include <glimac/glm.hpp>

using namespace glimac;

Button::Button(const float posX, const float posY, std::string bgImage)
:m_buttonTexture(Texture2D(bgImage)), m_posX(posX), m_posY(posY){}
 
GLuint Button::initializeButton(std::string vShader, std::string fShader){
    GLuint vboButton = m_buttonTexture.initializeTexture2D(vShader, fShader);
    return vboButton;
}

GLuint Button::createButton(const GLuint &vbo){
    GLuint vaoButton = m_buttonTexture.createAndBindVao(vbo);    
    return vaoButton;
}

void Button::drawButton(const GLuint &vao, const float &posX, const float &posY){
    glBindVertexArray(vao);
    glUniform1i(m_buttonTexture.getUTexture(),0);

    glUniformMatrix3fv(m_buttonTexture.getUModelMatrix(), 1, GL_FALSE, glm::value_ptr(m_buttonTexture.translate(0.25f, 0.25f)*m_buttonTexture.scale(0.5f, 0.5f)));

    glBindTexture(GL_TEXTURE_2D,m_buttonTexture.getIdText());

    glDrawArrays(GL_TRIANGLES,0,6);
    glBindTexture(GL_TEXTURE_2D,0);

    glBindVertexArray(0);
}

void Button::freeButtonTexture(const GLuint &vao, const GLuint &vbo){
    m_buttonTexture.freeTexture2D(vao, vbo);
}


Button::~Button(){}
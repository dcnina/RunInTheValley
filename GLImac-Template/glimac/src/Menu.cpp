/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Menu.cpp 
 */


#include <glimac/Menu.hpp>
#include <glimac/Image.hpp>
#include <glimac/glm.hpp>

using namespace glimac;

Menu::Menu(std::string bgImage)
 :m_backgroundImage(bgImage){}

void Menu::initializeMenu(std::string vShader, std::string fShader){
    m_prog = loadProgram(vShader, fShader);
    std::unique_ptr<Image> texture = loadImage(m_backgroundImage);
    

    glGenTextures(1,&m_idText);
    glBindTexture(GL_TEXTURE_2D,m_idText);
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,texture->getWidth(),texture->getHeight(),0, GL_RGBA,GL_FLOAT,texture->getPixels());
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D,0);

    GLuint vbo;
    glGenBuffers(1,&vbo);
    glBindBuffer(GL_ARRAY_BUFFER,vbo);

    Vertex2DUV verts[] = {
        Vertex2DUV(glm::vec2(-1.0f,-1.0f),glm::vec2(0.0f,1.0f)),
        Vertex2DUV(glm::vec2(1.0f,-1.0f),glm::vec2(1.0f,1.0f)),
        Vertex2DUV(glm::vec2(1.0f,1.0f),glm::vec2(1.0f,0.0f)),
        Vertex2DUV(glm::vec2(-1.0f,1.0f),glm::vec2(0.0f,0.0f))
    };
    glBufferData(GL_ARRAY_BUFFER,4*sizeof(Vertex2DUV),verts,GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER,0);

    GLuint vao;
    glGenVertexArrays(1,&vao);
    glBindVertexArray(vao);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER,vbo);
    glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,sizeof(Vertex2DUV),(const GLvoid*)(offsetof(Vertex2DUV,position)));
    glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,sizeof(Vertex2DUV),(const GLvoid*)(offsetof(Vertex2DUV,texture)));
    glBindBuffer(GL_ARRAY_BUFFER,0);

    glBindVertexArray(0);
    this->drawBackground(vao);
}

void Menu::drawMenu(std::string vShader, std::string fShader){
    this->initializeMenu(vShader,fShader);
    
}

void Menu::drawBackground(GLuint &vao){
    glBindTexture(GL_TEXTURE_2D,m_idText);
    glUniform1i(uTexture,0);
    glBindVertexArray(vao);
    glUniform1f(uModelMatrix, 1.0);
    glDrawArrays(GL_TRIANGLES,0,4);
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D,0);
}

Menu::~Menu(){}
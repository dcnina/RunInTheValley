/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Texture2D.cpp 
 */


#include <glimac/Texture2D.hpp>
#include <glimac/Image.hpp>
#include <glimac/glm.hpp>

using namespace glimac;


glm::mat3 scale(float sx, float sy){
    return glm::mat3(glm::vec3(sx, 0, 0), glm::vec3(0, sy, 0), glm::vec3(0, 0, 1));
}

// Texture2D::Texture2D(std::string bgImage)
//  :m_textureImage(bgImage){}

Texture2D::Texture2D(glimac::Program *prog,glimac::FilePath path)
    :m_textureImage(path), m_prog(prog)
 {  
    m_uModelMatrix = glGetUniformLocation(m_prog->getGLId(), "uModelMatrix");
    m_uTexture = glGetUniformLocation(m_prog->getGLId(), "uTexture"); 

    //m_prog->use();
 }


std::unique_ptr<glimac::Image> Texture2D::loadImg()
{
    std::unique_ptr<glimac::Image> image = loadImage(m_textureImage);
    if(image == NULL){
        //Error mess
    }
    return image;
}
void Texture2D::initializeTexture2D(std::unique_ptr<glimac::Image> &texture){


    glGenTextures(1,&m_idText);
    glBindTexture(GL_TEXTURE_2D,m_idText);
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,texture->getWidth(),texture->getHeight(),0, GL_RGBA,GL_FLOAT,texture->getPixels());
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D,0);

    createAndBindVao();
}

void Texture2D::createAndBindVao(){

    glGenBuffers(1,&m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER,m_vbo);

    Vertex2DUV verts[] = {
        Vertex2DUV(glm::vec2(-1.f, -1.f), glm::vec2(0.f, 1.f)),
        Vertex2DUV(glm::vec2(-1.f, 1.f), glm::vec2(0.f, 0.f)),
        Vertex2DUV(glm::vec2(1.f, 1.f), glm::vec2(1.f, 0.f)),
        Vertex2DUV(glm::vec2(1.f, 1.f), glm::vec2(1.f, 0.f)),
        Vertex2DUV(glm::vec2(1.f, -1.f), glm::vec2(1.f, 1.f)),
        Vertex2DUV(glm::vec2(-1.f, -1.f), glm::vec2(0.f, 1.f))
    };
    glBufferData(GL_ARRAY_BUFFER,6*sizeof(Vertex2DUV),verts,GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER,0);
    glGenVertexArrays(1,&m_vao);
    glBindVertexArray(m_vao);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER,m_vbo);

    glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,sizeof(Vertex2DUV),(const GLvoid*)(offsetof(Vertex2DUV,position)));
    glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,sizeof(Vertex2DUV),(const GLvoid*)(offsetof(Vertex2DUV,texture)));
    glBindBuffer(GL_ARRAY_BUFFER,0);

    glBindVertexArray(0);
}

void Texture2D::drawTexture2D(){
    glBindVertexArray(m_vao);
    glBindTexture(GL_TEXTURE_2D,m_idText);
    glUniform1i(m_uTexture,0);

    //glUniformMatrix3fv(m_uModelMatrix, 1, GL_FALSE, glm::value_ptr(scale(1.0f, 1.0f)));


    glDrawArrays(GL_TRIANGLES,0,6);

    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D,0);
}


Texture2D::~Texture2D(){
    glDeleteBuffers(1, &m_vbo);
    glDeleteVertexArrays(1, &m_vao);
    glDeleteTextures(1, &m_idText);
}

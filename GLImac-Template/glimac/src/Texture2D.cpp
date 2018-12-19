/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Texture2D.cpp 
 */


#include <glimac/Texture2D.hpp>
#include <glimac/Image.hpp>
#include <glimac/glm.hpp>

using namespace glimac;



Texture2D::Texture2D(std::string bgImage)
 :m_textureImage(bgImage){}

Texture2D::Texture2D(const Texture2D &texture)
 :m_idText(texture.m_idText), m_textureImage(texture.m_textureImage), uModelMatrix(texture.uModelMatrix), uTexture(texture.uTexture)
 {}

glm::mat3 Texture2D::translate(float tx, float ty)const {
    return glm::mat3(glm::vec3(1, 0, 0), glm::vec3(0, 1, 0), glm::vec3(tx, ty, 1));
}

glm::mat3 Texture2D::scale(float sx, float sy)const {
    return glm::mat3(glm::vec3(sx, 0, 0), glm::vec3(0, sy, 0), glm::vec3(0, 0, 1));
}

GLuint Texture2D::initializeTexture2D(std::string vShader, std::string fShader){

    m_prog = loadProgram(vShader, fShader);
    m_prog.use();
    std::unique_ptr<Image> texture = loadImage(m_textureImage);

    if(texture == NULL)
        std::cout << "erreur chargement image menu "<<std::endl;

    glGenTextures(1,&m_idText);
    glBindTexture(GL_TEXTURE_2D,m_idText);
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,texture->getWidth(),texture->getHeight(),0, GL_RGBA,GL_FLOAT,texture->getPixels());
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D,0);

    uModelMatrix = glGetUniformLocation(m_prog.getGLId(), "uModelMatrix");
    uTexture = glGetUniformLocation(m_prog.getGLId(), "uTexture"); 

    GLuint vbo;
    glGenBuffers(1,&vbo);
    glBindBuffer(GL_ARRAY_BUFFER,vbo);

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

    return vbo;
}

GLuint Texture2D::createAndBindVao(const GLuint &vbo){
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

    return vao;
}

void Texture2D::drawTexture2D(const GLuint &vao){
    glBindVertexArray(vao);
    glUniform1i(uTexture,0);

    glUniformMatrix3fv(uModelMatrix, 1, GL_FALSE, glm::value_ptr(scale(1.0f, 1.0f)));

    glBindTexture(GL_TEXTURE_2D,m_idText);

    glDrawArrays(GL_TRIANGLES,0,6);
    glBindTexture(GL_TEXTURE_2D,0);

    glBindVertexArray(0);
}

void Texture2D::freeTexture2D(const GLuint &vao, const GLuint &vbo){
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
    glDeleteTextures(1, &m_idText);
}

Texture2D::~Texture2D(){}


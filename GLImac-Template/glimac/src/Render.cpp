/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Render.cpp 
 */


#include <glimac/Render.hpp>

Render::Render(std::string vShader, std::string fShader){
	m_prog = glimac::loadProgram(vShader, fShader);

	// Set uniform variables

    m_uMVPMatrix = glGetUniformLocation(m_prog.getGLId(),"uMVPMatrix");
    m_uMVMatrix = glGetUniformLocation(m_prog.getGLId(),"uMVMatrix");
    m_uNormalMatrix = glGetUniformLocation(m_prog.getGLId(),"uNormalMatrix");

    m_uKd = glGetUniformLocation(m_prog.getGLId(),"uKd");
    m_uKs = glGetUniformLocation(m_prog.getGLId(),"uKs");
    m_uShininess = glGetUniformLocation(m_prog.getGLId(),"uShininess");
    m_uLightDir_vs = glGetUniformLocation(m_prog.getGLId(),"uLightDir_vs");
    m_uLightIntensity = glGetUniformLocation(m_prog.getGLId(),"uLightIntensity");
    m_uTexture = glGetUniformLocation(m_prog.getGLId(), "uTexture");

    m_prog.use();
}

void Render::reset() const {
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
}
void Render::sendLight(glm::mat4 viewMatrix) const {
    glUniform3fv(m_uKd,1,glm::value_ptr(m_Kd));
    glUniform3fv(m_uKs,1,glm::value_ptr(m_Ks));
    glUniform1f(m_uShininess,m_Shininess);
    glUniform3fv(m_uLightDir_vs,1,glm::value_ptr(viewMatrix*m_LightDir_vs));
    glUniform3fv(m_uLightIntensity,1,glm::value_ptr(m_LightIntensity));
}
void Render::sendMatrix(glm::mat4 MVMatrix) const {
	glUniformMatrix4fv(m_uMVPMatrix,1,GL_FALSE,glm::value_ptr(m_projMatrix*MVMatrix));
	glUniformMatrix4fv(m_uMVMatrix,1,GL_FALSE,glm::value_ptr(MVMatrix));
	glUniformMatrix4fv(m_uNormalMatrix,1,GL_FALSE,glm::value_ptr(glm::transpose(glm::inverse(MVMatrix))));
}

Render::~Render(){}
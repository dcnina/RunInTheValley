/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Button.cpp 
 */


#include <glimac/Button.hpp>
#include <glimac/Image.hpp>
#include <glimac/glm.hpp>

using namespace glimac;

Button::Button(float posX,float posY, float scaleX, float scaleY, Texture2D *texture)
:m_buttonTexture(texture), m_posX(posX), m_posY(posY), m_scaleX(scaleX), m_scaleY(scaleY){}
 
void Button::initializeButton(std::unique_ptr<glimac::Image> &bgImage){
    m_buttonTexture->initializeTexture2D(bgImage);
}
void Button::createButton(){
    m_buttonTexture->createAndBindVao();    
}

glm::mat3 translateMat(float tx, float ty) {
    return glm::mat3(glm::vec3(1, 0, 0), glm::vec3(0, 1, 0), glm::vec3(tx, ty, 1));
}

glm::mat3 scaleMat(float sx, float sy){
    return glm::mat3(glm::vec3(sx, 0, 0), glm::vec3(0, sy, 0), glm::vec3(0, 0, 1));
}
void Button::drawButton(){
    float width = 1.0/float(WINDOW_WIDTH)*float(m_scaleX);
    float height = 1.0/float(WINDOW_HEIGHT)*float(m_scaleY);

    float transX = (float(m_posX+m_scaleX/2.0)/float(WINDOW_WIDTH)*2.0)-1.0;
    float transY = 1.0-float(m_posY+m_scaleY/2.0)/float(WINDOW_HEIGHT)*2.0;

    glUniformMatrix3fv(m_buttonTexture->getUModelMatrix(), 1, GL_FALSE, glm::value_ptr(translateMat(transX,transY)*scaleMat(width,height)));
    m_buttonTexture->drawTexture2D();
}

bool Button::mouseHover(const glm::ivec2 &mousePos) const{

	if(mousePos.x >= m_posX && mousePos.x <= m_posX + m_scaleX){
		if(mousePos.y >= m_posY && mousePos.y <= m_posY + m_scaleY){
			return true;
		}
	}
	return false;
}
Button::~Button(){}
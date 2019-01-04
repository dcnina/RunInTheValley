/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Button.hpp 
 */

/**
 *\file Button.hpp
 *\author  {Audrey.C, Nina.DC, Lucas.L}
 *\date 17 december 2018
 *\brief class Button
*/

/**
 *\class Button
 *\brief Button
 *  
 */

#include <glimac/Texture2D.hpp>
#include <glimac/FilePath.hpp>
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

#ifndef __BUTTON__
#define __BUTTON__


class Button{
private:
	Texture2D *m_buttonTexture;
	float m_posX;
	float m_posY;
	float m_scaleX;
	float m_scaleY;
	bool m_isActive = false;
public:
	///CONSTRUCTOR
	/**
	*\brief Button constructor   
	*/
	Button(float posX,float posY, float scaleX, float scaleY,Texture2D *texture);

	
	///METHODS
	/**
	*\brief initialize the texture 
	*\params bgImage
	*/
	void initializeButton(std::unique_ptr<glimac::Image> &bgImage);
	
	inline bool isActive(){return m_isActive;};

	inline void activeButton(bool state){m_isActive = state;};
	inline float getPosX(){return m_posX;};
	/**
	*\brief create and bind the button vao 
	*/
	void createButton();

	/**
	*\brief draw the background button texture 
	*/
	void drawButton();

	/**
	*\brief detect the mouseHover
	*\params mouseX, mouseY
	*\return bool : true if hover / false if not hover
	*/
	bool mouseHover(const glm::ivec2 &mousePos) const;

	///DESTRUCTOR
	/**
	*\brief Default destructor   
	*\details Destructor by default of Button
	*/
	~Button();
};

#endif
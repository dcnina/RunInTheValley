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
public:
	///CONSTRUCTOR
	/**
	*\brief Button constructor   
	*/
	Button(float posX,float posY, float scaleX, float scaleY,Texture2D *texture);


	
	///METHODS
	/**
	*\brief initialize the texture 
	*\params vShaders and fShader
	*\return gluint : vbo 
	*/
	
	void initializeButton(std::unique_ptr<glimac::Image> &bgImage);
	
	/**
	*\brief create and bind the button vao 
	*\params gluint vbo
	*\return gluint : vao 
	*/
	void createButton();

	/**
	*\brief draw the background button texture 
	*\params gluint vao 
	*/
	void drawButton();

	bool mouseHover(const int posX, const int posY) const;

	///DESTRUCTOR
	/**
	*\brief Default destructor   
	*\details Destructor by default of Button
	*/
	~Button();
};

#endif
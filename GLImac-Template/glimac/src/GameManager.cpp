/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - GameManager.cpp 
 */


#include <glimac/GameManager.hpp>
#include <glimac/SDLWindowManager.hpp>
#include <glimac/FilePath.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/Menu.hpp>

GameManager::GameManager()
 :m_gameState(0), m_windowDimension(800){}


void GameManager::launchGame(int argc, char** argv){
	//create the SDL window + GLEW
	glimac::SDLWindowManager windowManager = this->initializeGame();

    // glimac::FilePath appPath(argv[0]);
    // Menu menu(appPath.dirPath()+"assets/textures/menu.png");
    // menu.initializeMenu(appPath.dirPath()+"shaders/tex2D.vs.glsl",
    //                             appPath.dirPath()+"shaders/tex2D.fs.glsl");

	// Application loop:
    bool done = false;
    while(!done) {
        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
        }

        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/


        // Update the display
        windowManager.swapBuffers();
    }
}

glimac::SDLWindowManager GameManager::initializeGame(){
	// Initialize SDL and open a window
    glimac::SDLWindowManager windowManager(m_windowDimension, m_windowDimension, "GLImac");

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
       std::cerr << glewGetErrorString(glewInitError) << std::endl;
    }

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    return windowManager;
}
GameManager::~GameManager(){}
#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/glm.hpp>
#include <glimac/Image.hpp>
#include <glimac/Sphere.hpp>
#include <glimac/TrackballCamera.hpp>
#include <glm/gtc/random.hpp>


#include <glimac/Model.hpp>
#include <glimac/Render.hpp>
#include <glimac/Map.hpp>
#include <glimac/Bonus.hpp>
#include <glimac/Princess.hpp>
#include <glimac/Player.hpp>
#include <glimac/World.hpp>
#include <glimac/Menu.hpp>
#include <glimac/Button.hpp>
#include <glimac/Texture2D.hpp>

using namespace glimac;

GLenum glCheckError_(const char *file, int line)
{
    GLenum errorCode;
    while ((errorCode = glGetError()) != GL_NO_ERROR)
    {
        std::string error;
        switch (errorCode)
        {
            case GL_INVALID_ENUM:                  error = "INVALID_ENUM"; break;
            case GL_INVALID_VALUE:                 error = "INVALID_VALUE"; break;
            case GL_INVALID_OPERATION:             error = "INVALID_OPERATION"; break;
            case GL_STACK_OVERFLOW:                error = "STACK_OVERFLOW"; break;
            case GL_STACK_UNDERFLOW:               error = "STACK_UNDERFLOW"; break;
            case GL_OUT_OF_MEMORY:                 error = "OUT_OF_MEMORY"; break;
            case GL_INVALID_FRAMEBUFFER_OPERATION: error = "INVALID_FRAMEBUFFER_OPERATION"; break;
        }
        std::cout << error << " | " << file << " (" << line << ")" << std::endl;
    }
    return errorCode;
}
#define glCheckError() glCheckError_(__FILE__, __LINE__) 



int main(int argc, char** argv) {

   // glCheckError();

    // Initialize SDL and open a window
    SDLWindowManager windowManager(800, 800, "GLImac");

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }
    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/
    const GLuint VERTEX_ATTR_POS = 0;
    const GLuint VERTEX_ATTR_NORM = 1;

    const float BTN_SCORE_POS_X = 0.35f;
    const float BTN_SCORE_POS_Y = -0.28f;
    const float BTN_SCORE_SCALE_X = 0.25f;
    const float BTN_SCORE_SCALE_Y = 0.25f;

    const float BTN_PLAY_POS_X = -0.35f;
    const float BTN_PLAY_POS_Y = -0.28f;
    const float BTN_PLAY_SCALE_X = 0.25f;
    const float BTN_PLAY_SCALE_Y = 0.25f;

    const float BTN_QUIT_POS_X = 0.8f;
    const float BTN_QUIT_POS_Y = 0.87f;
    const float BTN_QUIT_SCALE_X = 0.15f;
    const float BTN_QUIT_SCALE_Y = 0.15f;
    

    FilePath appPath(argv[0]);

    glimac::Program progMenu = glimac::loadProgram(appPath.dirPath() + "shaders/tex2D.vs.glsl", appPath.dirPath() + "shaders/tex2D.fs.glsl");
    progMenu.use();

    Texture2D backgroundMainText(&progMenu,appPath.dirPath()+"assets/textures/menu.png");
    std::unique_ptr<glimac::Image> backgroundMenuImg = backgroundMainText.loadImg();
    backgroundMainText.initializeTexture2D(backgroundMenuImg);
    
    Texture2D textureScore(&progMenu,appPath.dirPath()+"assets/textures/score.png");
    std::unique_ptr<glimac::Image> backgroundScore = textureScore.loadImg();
    
    Texture2D texturePlay(&progMenu,appPath.dirPath()+"assets/textures/play.png");
    std::unique_ptr<glimac::Image> backgroundPlay = texturePlay.loadImg();
    
    Texture2D textureQuit(&progMenu,appPath.dirPath()+"assets/textures/quit.png");
    std::unique_ptr<glimac::Image> backgroundQuit = textureQuit.loadImg();
    
    Button buttonScore(430, 410, 200, 200, &textureScore);
    buttonScore.initializeButton(backgroundScore);
    buttonScore.createButton();

    Button buttonPlay(170, 410, 200, 200, &texturePlay);
    buttonPlay.initializeButton(backgroundPlay);
    buttonPlay.createButton();

    Button buttonQuit(700, 0, 100, 100, &textureQuit);
    buttonQuit.initializeButton(backgroundQuit);
    buttonQuit.createButton();
   
    Menu menuBackground(&backgroundMainText);

    //Adding button to menu
    menuBackground.addButton(buttonScore);
    menuBackground.addButton(buttonPlay);
    menuBackground.addButton(buttonQuit);

    glm::mat4 MVMatrix;
    glm::mat4 viewMatrix;


    //DEPTH Test of the GPU
    //glEnable(GL_DEPTH_TEST);

    //Create a new Camera


    // Application loop:
    bool done = false;

    while(!done) {
       
       // viewMatrix = trackCamera.getViewMatrix();
        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
            else if(e.type == SDL_MOUSEMOTION) {
                int mouse_x, mouse_y;
                SDL_GetMouseState(&mouse_x, &mouse_y);
                menuBackground.getButtons()[0].mouseHover(mouse_x,mouse_y);
                if(menuBackground.getButtons()[0].mouseHover(mouse_x,mouse_y)){
                    //std::cout << "Hover button Score"<<std::endl;
                }
                else if(menuBackground.getButtons()[1].mouseHover(mouse_x,mouse_y)){
                    //std::cout << "Hover button Play"<<std::endl;
                }
                else if(menuBackground.getButtons()[2].mouseHover(mouse_x,mouse_y)){
                    //std::cout << "Hover button Leave"<<std::endl;
                }
            }
        }


        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/
        //glClear(GL_COLOR_BUFFER_BIT);
        menuBackground.drawMenu();

        // Update the display
        windowManager.swapBuffers();

    }
    /*buttonScore.freeButtonTexture(vaoButtonScore, vboButtonScore);
    buttonPlay.freeButtonTexture(vaoButtonPlay, vboButtonPlay);
    buttonPlay.freeButtonTexture(vaoButtonQuit, vboButtonQuit);*/

    return EXIT_SUCCESS;
}
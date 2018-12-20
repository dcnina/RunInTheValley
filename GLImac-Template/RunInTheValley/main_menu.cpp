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
    glimac::Program prog = glimac::loadProgram(appPath.dirPath() + "shaders/3D.vs.glsl",appPath.dirPath() + "shaders/pointlight.fs.glsl"); 
    Render render(&prog);

    glimac::Program progMenu = glimac::loadProgram(appPath.dirPath() + "shaders/tex2D.vs.glsl", appPath.dirPath() + "shaders/tex2D.fs.glsl");
    Texture2D texture2D(&progMenu);

    Button buttonScore(BTN_SCORE_POS_X, BTN_SCORE_POS_Y, BTN_SCORE_SCALE_X, BTN_SCORE_SCALE_Y, texture2D);
    GLuint vboButtonScore = buttonScore.initializeButton(appPath.dirPath() + "assets/textures/score.png");
    GLuint vaoButtonScore = buttonScore.createButton(vboButtonScore);

    Button buttonPlay(BTN_PLAY_POS_X, BTN_PLAY_POS_Y, BTN_PLAY_SCALE_X, BTN_PLAY_SCALE_Y, texture2D);
    GLuint vboButtonPlay = buttonPlay.initializeButton(appPath.dirPath() + "assets/textures/play.png");
    GLuint vaoButtonPlay = buttonPlay.createButton(vboButtonPlay);

    Button buttonQuit(BTN_QUIT_POS_X, BTN_QUIT_POS_Y, BTN_QUIT_SCALE_X, BTN_QUIT_SCALE_Y, texture2D);
    GLuint vboButtonQuit = buttonQuit.initializeButton(appPath.dirPath() + "assets/textures/quit.png");
    GLuint vaoButtonQuit = buttonQuit.createButton(vboButtonQuit);
   
    Menu menuBackground(texture2D);
    GLuint vboMenu = menuBackground.initializeMenu(appPath.dirPath() + "assets/textures/menu.png");
    GLuint vaoMenu = menuBackground.createMenu(vboMenu);

   // menuBackground.initializeMenu(appPath.dirPath() + "shaders/text2D.vs.glsl", appPath.dirPath() + "shaders/text2D.fs.glsl");


    //  Model princessModel("assets/obj/princess.obj");

   // Model bloc("assets/obj/bloc.obj");
   // Model bonus("assets/obj/bonus.obj");
   // Model coin("assets/obj/coin.obj");

    glm::mat4 MVMatrix;
    glm::mat4 viewMatrix;

   // Map map("./assets/map/level.txt");
    // map.printMap();
    // std::vector<Bonus> listBonus;
    // Princess princess;
    // Player player("pseudo",coin);
    // std::vector<Model> globalModel;

    // globalModel.push_back(princessModel);
    // globalModel.push_back(bloc);
    // globalModel.push_back(bonus);
    // globalModel.push_back(coin);
    
    // World world(map, 0, listBonus, princess, player, globalModel, render);


    //DEPTH Test of the GPU
    glEnable(GL_DEPTH_TEST);

    //Create a new Camera

    TrackballCamera trackCamera;
    int prevX = 0;
    int prevY = 0;

    // Application loop:
    bool done = false;

    while(!done) {
        buttonScore.drawButton(vaoButtonScore);
        buttonPlay.drawButton(vaoButtonPlay);
        buttonQuit.drawButton(vaoButtonQuit);
        menuBackground.drawBackground(vaoMenu);
       
       // viewMatrix = trackCamera.getViewMatrix();
        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
       //     else if(e.type == SDL_MOUSEMOTION){
        //         glm::ivec2 v = windowManager.getMousePosition();
        //         if(prevX-v.x>0){
        //             trackCamera.rotateLeft(5);
        //         }
        //         if(prevX-v.x<0){
        //             trackCamera.rotateLeft(-5);
        //         }
        //         if(prevY-v.y>0){
        //             trackCamera.rotateUp(5);
        //         }
        //         if(prevY-v.y<0){
        //             trackCamera.rotateUp(-5);
        //         }
        //         prevX = v.x;
        //         prevY=v.y;
        //     }
        //     else if(e.type == SDL_MOUSEBUTTONDOWN){
        //         if(e.button.button == SDL_BUTTON_WHEELUP) // scroll up
        //         {
        //             trackCamera.moveFront(1.0);
        //         }
        //         else if(e.button.button == SDL_BUTTON_WHEELDOWN) // scroll down
        //         {
        //             trackCamera.moveFront(-1.0);
        //         }

        //     }
         }
    
        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/
      //  glClear(GL_COLOR_BUFFER_BIT);

       

        /*render.reset();
        MVMatrix = glm::translate(glm::mat4(), glm::vec3(0, 0, 0)); 

        MVMatrix = viewMatrix*MVMatrix;
        render.sendMatrix(MVMatrix);

        render.sendLight(viewMatrix);
        bonus.draw();*/
     //   world.drawWorld();

        // Update the display
        windowManager.swapBuffers();
    }
    buttonScore.freeButtonTexture(vaoButtonScore, vboButtonScore);
    buttonPlay.freeButtonTexture(vaoButtonPlay, vboButtonPlay);
    buttonPlay.freeButtonTexture(vaoButtonQuit, vboButtonQuit);
    menuBackground.freeMenuTexture(vaoMenu, vboMenu);

    return EXIT_SUCCESS;
}
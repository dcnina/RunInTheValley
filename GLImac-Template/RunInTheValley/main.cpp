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

using namespace glimac;

int main(int argc, char** argv) {

    

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

    FilePath appPath(argv[0]);
    glimac::Program prog = glimac::loadProgram(appPath.dirPath() + "shaders/3D.vs.glsl",appPath.dirPath() + "shaders/directionallight.fs.glsl");
    Render render(&prog);
    Model princessModel("assets/obj/princess.obj");

    Model bloc("assets/obj/bloc.obj");
    Model bonus("assets/obj/bonus.obj");
    Model coin("assets/obj/coin.obj");
    Model obstacle("assets/obj/obstacle.obj");

    glm::mat4 MVMatrix;
    glm::mat4 viewMatrix;

    Map map("./assets/map/level.txt");
    map.printMap();
    std::vector<Bonus> listBonus;
    Princess princess;
    Player player("pseudo",coin);
    std::vector<Model> globalModel;

    globalModel.push_back(princessModel);
    globalModel.push_back(bloc);
    globalModel.push_back(bonus);
    globalModel.push_back(coin);
    globalModel.push_back(obstacle);
    
    World world(map, 0, listBonus, princess, player, globalModel, render);
    

    //DEPTH Test of the GPU
    glEnable(GL_DEPTH_TEST);

    //Create a new Camera

    /*TrackballCamera trackCamera;
    int prevX = 0;
    int prevY = 0;*/

    // Application loop:
    bool done = false;
    while(!done) {

       // glClearColor( 255, 255 ,255, 1.0 );
       /* viewMatrix = trackCamera.getViewMatrix();*/
        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
            else if(e.type == SDL_MOUSEMOTION){
               /* glm::ivec2 v = windowManager.getMousePosition();
                if(prevX-v.x>0){
                    trackCamera.rotateLeft(5);
                }
                if(prevX-v.x<0){
                    trackCamera.rotateLeft(-5);
                }
                if(prevY-v.y>0){
                    trackCamera.rotateUp(5);
                }
                if(prevY-v.y<0){
                    trackCamera.rotateUp(-5);
                }
                prevX = v.x;
                prevY=v.y;*/
            }
            else if(e.type == SDL_MOUSEBUTTONDOWN){
                /*if(e.button.button == SDL_BUTTON_WHEELUP) // scroll up
                {
                    trackCamera.moveFront(1.0);
                }
                else if(e.button.button == SDL_BUTTON_WHEELDOWN) // scroll down
                {
                    trackCamera.moveFront(-1.0);
                }*/

            }
        }
    

        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/

        /*render.reset();
        MVMatrix = glm::translate(glm::mat4(), glm::vec3(0, 0, 0)); 

        MVMatrix = viewMatrix*MVMatrix;
        render.sendMatrix(MVMatrix);

        render.sendLight(viewMatrix);
        bonus.draw();*/
        world.drawWorld();

        // Update the display
        windowManager.swapBuffers();
    }
    return EXIT_SUCCESS;
}
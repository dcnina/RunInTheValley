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
#include <glimac/Game.hpp>

using namespace glimac;

int main(int argc, char** argv) {
    /* Initialization of SDL 
    if(-1 == SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) {
        fprintf(stderr, "Impossible to initialize SDL. End of programme.\n");
        return EXIT_FAILURE;
    }*/

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

    //Sound initialization
    /*if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
       std::cout << Mix_GetError() << std::endl;
    Mix_Music *music; //creation of musique


    /*music = Mix_LoadMUS("assets/sound/music.mp3");
    Mix_PlayMusic(music, -1);
    Mix_VolumeMusic(MIX_MAX_VOLUME);*/

   
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
    Model fond("assets/obj/fond1.obj");    
    Model ennemy("assets/obj/ennemy-black.obj");  

    std::vector<Model> globalModel;

    globalModel.push_back(princessModel);
    globalModel.push_back(bloc);
    globalModel.push_back(bonus);
    globalModel.push_back(coin);
    globalModel.push_back(obstacle);
    globalModel.push_back(fond);
    globalModel.push_back(ennemy);
    
    Game game("./assets/map/level.txt", globalModel, render);

    //DEPTH Test of the GPU
    glEnable(GL_DEPTH_TEST);

    std::srand((int)time(0));;
    // Application loop:
    bool done = false;
    while(!done) {

       // glClearColor( 255, 255 ,255, 1.0 );
       /* viewMatrix = trackCamera.getViewMatrix();*/
        //Event loop: 
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
                if(e.type == SDL_QUIT) {
                    done= true; // Leave the loop after this iteration
                }
            	glm::ivec2 v = windowManager.getMousePosition();
        		game.eventManager(e,v);
            }

        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/
        
        game.playGame();
        game.drawAll();

        //if (game.endGame() == true)
          //  done = true;
        // Update the display
        windowManager.swapBuffers();
    }

/*    //Free music data
    Mix_FreeMusic(music);
    Mix_CloseAudio();*/
    return EXIT_SUCCESS;
}
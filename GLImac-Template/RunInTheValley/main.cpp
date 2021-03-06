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

#include <glimac/Menu.hpp>
#include <glimac/Button.hpp>
#include <glimac/Texture2D.hpp>
#include <glimac/Exception.hpp>

#include <SDL/SDL_mixer.h>

#define MAIN_MENU 0
#define PLAYING 1
#define PAUSE_MENU 2
#define SCORE_MENU 3
#define END_MENU 4
#define WINDOW_SIZE 800


using namespace glimac;

int main(int argc, char** argv) {
    std::srand((int)time(0));
    /* Initialization of SDL */
    if(-1 == SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) {
        fprintf(stderr, "Impossible to initialize SDL. End of programme.\n");
        return EXIT_FAILURE;
    }

    // Initialize SDL and open a window
    SDLWindowManager windowManager(WINDOW_SIZE, WINDOW_SIZE, "Run In The Valley");


    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    //Sound initialization
    if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
       std::cout << Mix_GetError() << std::endl;
    Mix_Music *music; //creation of musique


    music = Mix_LoadMUS("assets/sound/music.mp3");
    Mix_PlayMusic(music, -1);
    Mix_VolumeMusic(MIX_MAX_VOLUME);

    const GLuint VERTEX_ATTR_POS = 0;
    const GLuint VERTEX_ATTR_NORM = 1;

    FilePath appPath(argv[0]);
    //!< Prepare the render data (shaders) for the 3d parts
    glimac::Program progGame = glimac::loadProgram(appPath.dirPath() + "shaders/3D.vs.glsl",appPath.dirPath() + "shaders/directionallight.fs.glsl");
    Render render(&progGame);

    //!< Prepare the render data (shaders) for the 2d parts
    glimac::Program progMenu = glimac::loadProgram(appPath.dirPath() + "shaders/tex2D.vs.glsl", appPath.dirPath() + "shaders/tex2D.fs.glsl");
    //progMenu.use();

   	int gameState = MAIN_MENU;
    int enAttente = false;

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/

	//!< Loading of the 3D Models


    Model princessModel("assets/obj/princess-textured-2.obj");
    Model bloc("assets/obj/bloc-2.obj");
    Model bonus("assets/obj/bonus-2.obj");
    Model coin("assets/obj/coin-2.obj");
    Model obstacle("assets/obj/obstacle-2.obj");
    Model fond("assets/obj/fond-2.obj");
    Model enemy("assets/obj/enemy-textured.obj");

    std::vector<Model> globalModel;

    globalModel.push_back(princessModel);
    globalModel.push_back(bloc);
    globalModel.push_back(bonus);
    globalModel.push_back(coin);
    globalModel.push_back(obstacle);
    globalModel.push_back(fond);
    globalModel.push_back(enemy);

    //!< Creating a new game

    Game game("./assets/map/", globalModel, render);

		/*********************************
		 * 2D Initialisation - Textures
		 *********************************/


        // Background Main Menu Texture
        Texture2D backgroundMainText(&progMenu,appPath.dirPath()+"assets/textures/menu.png");
        std::unique_ptr<glimac::Image> backgroundMenuImg = backgroundMainText.loadImg();
        backgroundMainText.initializeTexture2D(backgroundMenuImg);

        // Background Menu Texture
        Texture2D backgroundPauseText(&progMenu,appPath.dirPath()+"assets/textures/pause.png");
        std::unique_ptr<glimac::Image> backgroundPauseImg = backgroundPauseText.loadImg();
        backgroundPauseText.initializeTexture2D(backgroundPauseImg);

        // Background Menu Texture
        Texture2D backgroundEndText(&progMenu,appPath.dirPath()+"assets/textures/end.png");
        std::unique_ptr<glimac::Image> backgroundEndImg = backgroundEndText.loadImg();
        backgroundEndText.initializeTexture2D(backgroundEndImg);

        // Button Score Texture
        Texture2D textureScore(&progMenu,appPath.dirPath()+"assets/textures/score.png");
        std::unique_ptr<glimac::Image> backgroundScore = textureScore.loadImg();

        // Button Play Texture
        Texture2D texturePlay(&progMenu,appPath.dirPath()+"assets/textures/play.png");
        std::unique_ptr<glimac::Image> backgroundPlay = texturePlay.loadImg();

        // Button Quit Texture
        Texture2D textureQuit(&progMenu,appPath.dirPath()+"assets/textures/quit.png");
        std::unique_ptr<glimac::Image> backgroundQuit = textureQuit.loadImg();



        /***** Buttons Creations *********/

        Button buttonScore(430, 410, 200, 200, &textureScore);
        buttonScore.initializeButton(backgroundScore);
        buttonScore.createButton();

        Button buttonPlay(170, 410, 200, 200, &texturePlay);
        buttonPlay.initializeButton(backgroundPlay);
        buttonPlay.createButton();

        Button buttonQuit(700, 0, 100, 100, &textureQuit);
        buttonQuit.initializeButton(backgroundQuit);
        buttonQuit.createButton();


    /******** Menu Creations ***********/

   	//Main Menu
    Menu menuBackground(&backgroundMainText);

    //Pause Menu
    Menu menuPause(&backgroundPauseText);

    //End Menu
    Menu menuEnd(&backgroundEndText);

    //Adding button to menu
    menuBackground.addButton(&buttonScore);
    menuBackground.addButton(&buttonPlay);
    menuBackground.addButton(&buttonQuit);

    menuPause.addButton(&buttonScore);
    menuPause.addButton(&buttonPlay);
    menuPause.addButton(&buttonQuit);


    menuEnd.addButton(&buttonQuit);

    //DEPTH Test of the GPU
    //glEnable(GL_DEPTH_TEST);

    // Application loop:
    bool done = false;
    while(!done) {
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
                if(e.type == SDL_QUIT) {
                    done= true; // Leave the loop after this iteration
                }
            	glm::ivec2 v = windowManager.getMousePosition();

            	if(gameState == MAIN_MENU){

            		if(e.type == SDL_MOUSEMOTION) {
		                Button *bScore = menuBackground.getButtons()[0];
			            Button *bPlay = menuBackground.getButtons()[1];
			            Button *bLeave = menuBackground.getButtons()[2];
			            if(bPlay->mouseHover(v)){
			                bPlay->activeButton(true);
			                bScore->activeButton(false);
			                bLeave->activeButton(false);
			            }
			            else if(bScore->mouseHover(v)){
			                bScore->activeButton(true);
			                bPlay->activeButton(false);
			                bLeave->activeButton(false);
			            }
			            else if(bLeave->mouseHover(v)){
			                bLeave->activeButton(true);
			                bPlay->activeButton(false);
			                bScore->activeButton(false);
			            }

		            }
		            else if(e.type == SDL_MOUSEBUTTONDOWN){

		                Button *bScore = menuBackground.getButtons()[0];
			            Button *bPlay = menuBackground.getButtons()[1];
			            Button *bLeave = menuBackground.getButtons()[2];
			            if(bScore->isActive()){
                            Game::displayBestScores();
			            }
			            else if(bPlay->isActive()){
			                gameState = PLAYING;
			            }
			            else if(bLeave->isActive()){
			            	done = true;
			            }

		            }

            	}
            	else if(gameState == PLAYING){
        			bool pauseGame = game.eventManager(e,v);
        			if(pauseGame)
			            gameState = PAUSE_MENU;
            	}
            	else if(gameState == PAUSE_MENU){
            		if(e.type == SDL_MOUSEMOTION) {
		                Button *bScore = menuPause.getButtons()[0];
			            Button *bPlay = menuPause.getButtons()[1];
			            Button *bLeave = menuPause.getButtons()[2];
			            if(bPlay->mouseHover(v)){
			                bPlay->activeButton(true);
			                bScore->activeButton(false);
			                bLeave->activeButton(false);
			            }
			            else if(bScore->mouseHover(v)){
			                bScore->activeButton(true);
			                bPlay->activeButton(false);
			                bLeave->activeButton(false);
			            }
			            else if(bLeave->mouseHover(v)){
			                bLeave->activeButton(true);
			                bPlay->activeButton(false);
			                bScore->activeButton(false);
			            }

		            }
		            else if(e.type == SDL_MOUSEBUTTONDOWN){

		                Button *bScore = menuPause.getButtons()[0];
			            Button *bPlay = menuPause.getButtons()[1];
			            Button *bLeave = menuPause.getButtons()[2];
			            if(bScore->isActive()){
                            Game::displayBestScores();
			            }
			            else if(bPlay->isActive()){
			                gameState = PLAYING;
			            }
			            else if(bLeave->isActive()){
			            	done = true;
			            }
		            }
            	}
            	else if(gameState == END_MENU){
                    if(e.type == SDL_MOUSEMOTION) {
                        Button *bLeave = menuEnd.getButtons()[0];
                        if(bLeave->mouseHover(v)){
                            bLeave->activeButton(true);
                        }
                        else{
                            bLeave->activeButton(false);
                        }

                    }
                    else if(e.type == SDL_MOUSEBUTTONDOWN){
                        Button *bLeave = menuEnd.getButtons()[0];
                        if(bLeave->isActive()){
                            gameState = MAIN_MENU;
                        }
                    }
            	}
            }

        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/
         if (game.isEnd() == true && gameState == PLAYING){
            gameState = END_MENU;
            progMenu.use();
            menuEnd.drawMenu();
            game.endGame();
        }

        if(gameState == MAIN_MENU){
        	progMenu.use();
    		menuBackground.drawMenu();
    	}
    	else if(gameState == PLAYING){
    		progGame.use();
	        game.playGame();
	        game.drawAll();
    	}
    	else if(gameState == PAUSE_MENU){
    		progMenu.use();
    		menuPause.drawMenu();
    	}
    	else if(gameState == END_MENU){
            progMenu.use();
            menuEnd.drawMenu();
    	}

        
        // Update the display
        windowManager.swapBuffers();
    }

    //Free music data
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    return EXIT_SUCCESS;
}

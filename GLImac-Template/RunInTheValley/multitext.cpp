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


#include <RITV/Model.hpp>

using namespace glimac;

struct EarthProgram {
    Program m_Program;

    GLint uMVPMatrix, uMVMatrix, uNormalMatrix, uKd, uKs, uShininess, uLightDir_vs, uLightIntensity,uTexture;

    EarthProgram(const FilePath& applicationPath):
        m_Program(loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl",
                              applicationPath.dirPath() + "shaders/directionallight.fs.glsl")) {
        uMVPMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVPMatrix");
        uMVMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVMatrix");
        uNormalMatrix = glGetUniformLocation(m_Program.getGLId(), "uNormalMatrix");
      	uKd = glGetUniformLocation(m_Program.getGLId(), "uKd");
      	uKs = glGetUniformLocation(m_Program.getGLId(), "uKs");
      	uShininess = glGetUniformLocation(m_Program.getGLId(), "uShininess");
      	uLightDir_vs = glGetUniformLocation(m_Program.getGLId(), "uLightDir_vs");
      	uLightIntensity = glGetUniformLocation(m_Program.getGLId(), "uLightIntensity");
		uTexture = glGetUniformLocation(m_Program.getGLId(), "uTexture");
    }
};

struct MoonProgram {
    Program m_Program;

   	GLint uMVPMatrix, uMVMatrix, uNormalMatrix, uKd, uKs, uShininess, uLightDir_vs, uLightIntensity;


    MoonProgram(const FilePath& applicationPath):
        m_Program(loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl",
                              applicationPath.dirPath() + "shaders/directionallight.fs.glsl")) {
        uMVPMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVPMatrix");
        uMVMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVMatrix");
        uNormalMatrix = glGetUniformLocation(m_Program.getGLId(), "uNormalMatrix");
      	uKd = glGetUniformLocation(m_Program.getGLId(), "uKd");
      	uKs = glGetUniformLocation(m_Program.getGLId(), "uKs");
      	uShininess = glGetUniformLocation(m_Program.getGLId(), "uShininess");
      	uLightDir_vs = glGetUniformLocation(m_Program.getGLId(), "uLightDir_vs");
      	uLightIntensity = glGetUniformLocation(m_Program.getGLId(), "uLightIntensity");
    }
};


int main(int argc, char** argv) {

	

    // Initialize SDL and open a window
    SDLWindowManager windowManager(800, 600, "GLImac");

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

	FilePath appPath(argv[0]);
    EarthProgram earthProgram(appPath);
    MoonProgram moonProgram(appPath);

	glm::mat4 ProjMatrix, MVMatrix, NormalMatrix;
	ProjMatrix = glm::perspective(glm::radians(70.f),8.0f/6.0f,0.1f,100.f);	
	MVMatrix = glm::translate(glm::mat4(),glm::vec3(0.0f, 0.0f, -5.0f));
	//NormalMatrix = glm::transpose(glm::inverse(MVMatrix));

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/
	const GLuint VERTEX_ATTR_POS = 0;
    const GLuint VERTEX_ATTR_NORM = 1;

    //CREATE FROM OBJ
  	Model model1(appPath.dirPath() + "assets/obj/dice.obj");

	


	//DEPTH Test of the GPU
	glEnable(GL_DEPTH_TEST);

	//Create a new Camera

	TrackballCamera trackCamera;
	int prevX = 0;
	int prevY = 0;

    // Application loop:
    bool done = false;
    while(!done) {


    	glm::mat4 viewMatrix = trackCamera.getViewMatrix();
        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
            else if(e.type == SDL_MOUSEMOTION){
            	glm::ivec2 v = windowManager.getMousePosition();
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
            	prevY=v.y;
            }
            else if(e.type == SDL_MOUSEBUTTONDOWN){
            	if(e.button.button == SDL_BUTTON_WHEELUP) // scroll up
		        {
		            trackCamera.moveFront(1.0);
		        }
		        else if(e.button.button == SDL_BUTTON_WHEELDOWN) // scroll down
		        {
		            trackCamera.moveFront(-1.0);
		        }

            }
        }
	

        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	earthProgram.m_Program.use();

	glm::mat4 MVMatrix = glm::translate(glm::mat4(), glm::vec3(0, 0, 0)); 
	MVMatrix = glm::rotate(viewMatrix*MVMatrix, windowManager.getTime(), glm::vec3(0, 1, 0));
	glUniformMatrix4fv(earthProgram.uMVPMatrix,1,GL_FALSE,glm::value_ptr(ProjMatrix*MVMatrix));
	glUniformMatrix4fv(earthProgram.uMVMatrix,1,GL_FALSE, glm::value_ptr(MVMatrix));
	glUniformMatrix4fv(earthProgram.uNormalMatrix,1,GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(MVMatrix))));
	
	glm::vec4 lightDir = glm::vec4(1, 1, 1, 0);
	lightDir = viewMatrix*lightDir;

	glUniform3f(earthProgram.uKd,0.5,0.5,0.5);
	glUniform3f(earthProgram.uKs,0.5,0.5,0.5);
	glUniform1f(earthProgram.uShininess,0.8);
	glUniform3f(earthProgram.uLightDir_vs,lightDir.x,lightDir.y,lightDir.z);
	glUniform3f(earthProgram.uLightIntensity,1,1,1);



        model1.draw();

        // Update the display
        windowManager.swapBuffers();
    }
    return EXIT_SUCCESS;
}

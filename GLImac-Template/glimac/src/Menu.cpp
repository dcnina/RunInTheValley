/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Menu.cpp 
 */


#include <glimac/Menu.hpp>

struct Vertex2DUV{
    glm::vec2 position;
    glm::vec2 texture;
    Vertex2DUV(const glm::vec2 &pos, const glm::vec2 &tex):position(pos), texture(tex){};
};


Menu::Menu(std::string backgroundImage)
 :m_backgroundImage(backgroundImage){}

void Menu::drawMenu(){
    FilePath appPath(argv[0]);
    Program prog = loadProgram(appPath.dirPath()+"shaders/tex2D.vs.glsl",
                                appPath.dirPath()+"shaders/tex2D.fs.glsl");

    this->drawBackground();

}

void drawBackground(){
    
}

Menu::~Menu(){}
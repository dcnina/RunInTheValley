#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/GameManager.hpp>

using namespace glimac;

int main(int argc, char** argv) {
    GameManager gameManager;
    gameManager.launchGame();
    return EXIT_SUCCESS;
}

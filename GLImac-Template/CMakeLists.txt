cmake_minimum_required(VERSION 2.8)

project(ImacGL)

add_definitions(-std=c++11)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake)

find_package(SDL REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(SDL_mixer REQUIRED)

# Pour gérer un bug a la fac, a supprimer sur machine perso:
# set(OPENGL_LIBRARIES /usr/lib/x86_64-linux-gnu/libGL.so.1)

include_directories(${SDL_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIR} ${SDL_MIXER_INCLUDE_DIRS} glimac/include third-party/include assimp/include)

set(ALL_LIBRARIES glimac assimp ${SDL_LIBRARY} ${OPENGL_LIBRARIES} ${GLEW_LIBRARY} ${SDL_MIXER_LIBRARIES})

add_subdirectory(glimac)
add_subdirectory(assimp)

file(GLOB RunInTheValley_DIRECTORIES "RunInTheValley*")

foreach(RunInTheValley ${RunInTheValley_DIRECTORIES})
    add_subdirectory(${RunInTheValley})
endforeach()

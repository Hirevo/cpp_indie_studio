cmake_minimum_required(VERSION 3.9)
project(bomberman)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
set(OpenGL_GL_PREFERENCE GLVND)
set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

find_package(OpenGL)
find_package(Irrlicht)

link_libraries(Irrlicht OpenGL)

include_directories(${IRRLICHT_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR})
include_directories(inc)

add_executable(bomberman
        src/main.cpp)

cmake_minimum_required(VERSION 3.9)
project(bomberman)

SET(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

set(CMAKE_CXX_STANDARD 11)

FIND_PACKAGE(OpenGL)
FIND_PACKAGE(Irrlicht)

INCLUDE_DIRECTORIES(${IRRLICHT_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR})

include_directories(inc)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)


add_executable(bomberman
        src/main.cpp)
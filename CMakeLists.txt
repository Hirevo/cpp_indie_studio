cmake_minimum_required(VERSION 3.9)
project(bomberman)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

include_directories(
        ${PROJECT_SOURCE_DIR}/include
)

add_executable(bomberman
        src/main.cpp)

if(UNIX)

set(IRRLICHT_LIBRARY
        -L./libraries/irrlicht/linux
        -lIrrlicht
        -lGL
        -lGLU
        -lXext
        -lX11
        -lXxf86vm
        )

find_package(Irrlicht)
link_libraries(Irrlicht)


elseif(WIN32)

add_library(Irrlicht STATIC IMPORTED)



endif(UNIX)

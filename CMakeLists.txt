cmake_minimum_required(VERSION 3.9)
project(bomberman)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(bomberman
        src/main.cpp)

set(IRRLICHT_SOURCE_DIR ./libs/irrlicht)
find_package(Irrlicht REQUIRED)
target_link_libraries(bomberman ${IRRLICHT_LIBRARY})
target_include_directories(bomberman PRIVATE ${IRRLICHT_INCLUDE_DIR})

add_custom_command(TARGET bomberman PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ../libs/irrlicht/bin/Win64-VisualStudio/Irrlicht.dll
        ../bin/Irrlicht.dll)
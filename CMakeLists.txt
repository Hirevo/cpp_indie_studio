cmake_minimum_required(VERSION 3.9)
project(bomberman)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

find_package(Irrlicht)


link_libraries(Irrlicht)

INCLUDE_DIRECTORIES(
        "/usr/include/irrlicht"
        ${PROJECT_SOURCE_DIR}/include
)
include_directories(inc)

add_executable(bomberman
        src/main.cpp)

cmake_minimum_required(VERSION 3.9)
project(bomberman)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

include_directories(
        src/interface
        src/classes
        srC/abstract)
set(HEADER_FILES
        src/interface/IScene.hpp
        src/interface/ICharacter.hpp
        src/interface/IMap.hpp
        src/interface/INpc.hpp
        src/interface/IObject.hpp
        src/abstract/APlayer.hpp
        src/classes/Camera.hpp
        src/classes/Device.hpp)

add_executable(bomberman
        src/main.cpp
        src/classes/Core.cpp
        src/classes/Options.cpp
        src/classes/Keymap.cpp
        src/abstract/AMenu.cpp
        src/abstract/AGame.cpp
        src/abstract/AComputer.cpp
        src/abstract/AMonster.cpp
        src/abstract/AWall.cpp
        src/abstract/ABomb.cpp
        src/abstract/ACollectible.cpp
        src/classes/Scene.cpp
        src/classes/Device.cpp
        src/classes/Camera.cpp
        src/abstract/APlayer.cpp
        ${HEADER_FILES})

set(IRRLICHT_SOURCE_DIR ./libs/irrlicht)
find_package(Irrlicht REQUIRED)
target_link_libraries(bomberman ${IRRLICHT_LIBRARY})
target_include_directories(bomberman PRIVATE ${IRRLICHT_INCLUDE_DIR})
message("${PROJECT_SOURCE_DIR}")
if(WIN32)
    if (CMAKE_CL_64)
        add_custom_command(TARGET bomberman PRE_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                ${PROJECT_SOURCE_DIR}/libs/irrlicht/bin/Win64-VisualStudio/Irrlicht.dll
                ${PROJECT_SOURCE_DIR}/bin/Irrlicht.dll)
    else ()
        add_custom_command(TARGET bomberman PRE_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                ${PROJECT_SOURCE_DIR}/libs/irrlicht/bin/Win32-VisualStudio/Irrlicht.dll
                ${PROJECT_SOURCE_DIR}/bin/Irrlicht.dll)
    endif ()
endif()
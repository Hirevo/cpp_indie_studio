cmake_minimum_required(VERSION 3.9)
project(bomberman)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(bomberman
        src/main.cpp
        src/classes/Core.cpp inc/classes/Core.hpp src/classes/Options.cpp inc/classes/Options.hpp src/classes/Keymap.cpp inc/classes/Keymap.hpp inc/interface/ICaracter.hpp inc/interface/IMap.hpp inc/interface/IObject.hpp inc/interface/INpc.hpp src/abstract/AMenu.cpp inc/abstract/AMenu.hpp src/abstract/AGame.cpp inc/abstract/AGame.hpp src/abstract/AComputer.cpp inc/abstract/AComputer.hpp src/abstract/AMonster.cpp inc/abstract/AMonster.hpp src/abstract/AWall.cpp inc/abstract/AWall.hpp src/abstract/ABomb.cpp inc/abstract/ABomb.hpp src/abstract/ACollectible.cpp inc/abstract/ACollectible.hpp)

include_directories(inc inc/interface)
set(IRRLICHT_SOURCE_DIR ./libs/irrlicht)
find_package(Irrlicht REQUIRED)
target_link_libraries(bomberman ${IRRLICHT_LIBRARY})
target_include_directories(bomberman PRIVATE ${IRRLICHT_INCLUDE_DIR})

if(WIN32)
    if (CMAKE_CL_64)
        message("Copy dll > 64")
        add_custom_command(TARGET bomberman PRE_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                ${PROJECT_SOURCE_DIR}/libs/irrlicht/bin/Win64-VisualStudio/Irrlicht.dll
                ${PROJECT_SOURCE_DIR}/bin/Irrlicht.dll)
    else ()
        message("Copy dll > 32")
        add_custom_command(TARGET bomberman PRE_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                ${PROJECT_SOURCE_DIR}/libs/irrlicht/bin/Win32-VisualStudio/Irrlicht.dll
                ${PROJECT_SOURCE_DIR}/bin/Irrlicht.dll)
    endif ()
endif()
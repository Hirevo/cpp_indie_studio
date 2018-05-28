cmake_minimum_required(VERSION 3.9)
project(bomberman)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
set(CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

include_directories(
        src/interfaces
        src/classes
        src/abstracts
        src
        libs/irrlicht/include
)

set(HEADER_FILES
        src/interfaces/IScene.hpp
        src/interfaces/ICharacter.hpp
        src/interfaces/IMap.hpp
        src/interfaces/INpc.hpp
        src/interfaces/IObject.hpp
        src/abstracts/ABomb.hpp
        src/abstracts/ACollectible.hpp
        src/abstracts/AGame.hpp
        src/abstracts/AMenu.hpp
        src/abstracts/AMonster.hpp
        src/abstracts/APlayer.hpp
        src/classes/Camera.hpp
        src/classes/Device.hpp
        src/classes/Map.cpp
        src/classes/JsonRead.hpp
        src/classes/MapWall.hpp
        src/classes/Debug.hpp
        src/classes/Wall.hpp
        src/classes/SceneHandler.hpp
        src/classes/Game.hpp)

add_executable(bomberman
        src/main.cpp
        src/classes/Core.cpp
        src/classes/Options.cpp
        src/classes/Keymap.cpp
        src/classes/Camera.cpp
        src/abstracts/AMenu.cpp
        src/abstracts/AGame.cpp
        src/abstracts/AComputer.cpp
        src/abstracts/AObject.cpp
        src/abstracts/AMovable.cpp
        src/abstracts/AMonster.cpp
        src/abstracts/ABomb.cpp
        src/abstracts/ACollectible.cpp
        src/classes/Game.cpp
        src/classes/Device.cpp
        src/classes/Camera.cpp
        src/classes/JsonRead.cpp
        src/abstracts/APlayer.cpp
        src/classes/Debug.cpp
        src/classes/Wall.cpp
        src/classes/SceneHandler.cpp
        ${HEADER_FILES})

set(IRRLICHT_SOURCE_DIR ./libs/irrlicht)
find_package(Irrlicht REQUIRED)
target_link_libraries(bomberman ${IRRLICHT_LIBRARY})
target_include_directories(bomberman PRIVATE ${IRRLICHT_INCLUDE_DIR})
message("${PROJECT_SOURCE_DIR}")

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost REQUIRED)

if(Boost_FOUND)
    message(status "** Boost Include: ${Boost_INCLUDE_DIR}")
    message(status "** Boost Libraries: ${Boost_LIBRARY_DIRS}")
    message(status "** Boost Libraries: ${Boost_LIBRARIES}")
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
    LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
    target_link_libraries(bomberman ${Boost_LIBRARIES})
else()
    message("J'ai PAS trouve BOOST")
endif()

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
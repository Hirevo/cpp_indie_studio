cmake_minimum_required(VERSION 3.9)
project(bomberman)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})

include_directories(
        src/interfaces
        src/classes
        src/abstracts
        src
        libs/irrlicht/include
)

set(HEADER_FILES
        src/abstracts/ACharacter.hpp
        src/abstracts/ACollectible.hpp
        src/abstracts/AMonster.hpp
        src/abstracts/APlayer.hpp
        src/abstracts/AScene.hpp
        src/classes/Bomb.hpp
        src/classes/Booster.hpp
        src/classes/Camera.hpp
        src/classes/Debug.hpp
        src/classes/Device.hpp
        src/classes/Event.hpp
        src/classes/Game.hpp
        src/classes/JsonRead.hpp
        src/classes/JsonWrite.hpp
        src/classes/Map.hpp
        src/classes/MapWall.hpp
        src/classes/menu/CreditsMenu.hpp
        src/classes/menu/GameMenu.hpp
        src/classes/menu/MainMenu.hpp
        src/classes/menu/PlayMenu.hpp
        src/classes/menu/SettingsMenu.hpp
        src/classes/Player.hpp
        src/classes/SceneHandler.hpp
        src/classes/SoundDevice.hpp
        src/classes/Wall.hpp
        src/interfaces/ICharacter.hpp
        src/interfaces/IMap.hpp
        src/interfaces/IObject.hpp
        src/interfaces/IScene.hpp
        src/Types.hpp
        )

add_executable(bomberman
        src/abstracts/ACollectible.cpp
        src/abstracts/AModel.cpp
        src/abstracts/AMonster.cpp
        src/abstracts/AMovable.cpp
        src/abstracts/AObject.cpp
        src/abstracts/APlayer.cpp
        src/abstracts/AScene.cpp
        src/abstracts/ACharacter.cpp
        src/classes/Bomb.cpp
        src/classes/Booster.cpp
        src/classes/Camera.cpp
        src/classes/Camera.cpp
        src/classes/Computer.cpp
        src/classes/Core.cpp
        src/classes/Debug.cpp
        src/classes/Device.cpp
        src/classes/Event.cpp
        src/classes/Flame.cpp
        src/classes/Floor.cpp
        src/classes/Game.cpp
        src/classes/JsonRead.cpp
        src/classes/JsonWrite.cpp
        src/classes/Keymap.cpp
        src/classes/Map.cpp
        src/classes/menu/CreditsMenu.cpp
        src/classes/menu/GameMenu.cpp
        src/classes/menu/MainMenu.cpp
        src/classes/menu/PlayMenu.cpp
        src/classes/menu/SettingsMenu.cpp
        src/classes/menu/SettingsMenu.cpp
        src/classes/Options.cpp
        src/classes/Player.cpp
        src/classes/SceneHandler.cpp
        src/classes/SoundDevice.cpp
        src/classes/Wall.cpp
        src/main.cpp
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

set(IRRKLANG_DIR ./libs/irrklang)
if(UNIX)
    set(IRRKLANG_LIBRARY ${PROJECT_SOURCE_DIR}/libs/irrklang/bin/Linux64/libIrrKlang.so)
    add_custom_command(TARGET bomberman PRE_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
            ${PROJECT_SOURCE_DIR}/libs/irrklang/bin/Linux64/ikpMP3.so
            ${PROJECT_SOURCE_DIR}/bin/ikpMP3.so)
endif(UNIX)
if(WIN32)
    if (CMAKE_CL_64)
        add_custom_command(TARGET bomberman PRE_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                ${PROJECT_SOURCE_DIR}/libs/irrlicht/bin/Win64-VisualStudio/Irrlicht.dll
                ${PROJECT_SOURCE_DIR}/bin/Irrlicht.dll)
        add_custom_command(TARGET bomberman PRE_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                ${PROJECT_SOURCE_DIR}/libs/irrklang/bin/Winx64/irrKlang.dll
                ${PROJECT_SOURCE_DIR}/bin/irrKlang.dll)
        add_custom_command(TARGET bomberman PRE_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                ${PROJECT_SOURCE_DIR}/libs/irrklang/bin/Winx64/ikpMP3.dll
                ${PROJECT_SOURCE_DIR}/bin/ikpMP3.dll)
        set(IRRKLANG_LIBRARY ${PROJECT_SOURCE_DIR}/libs/irrklang/lib/Winx64-visualStudio/irrKlang.lib)
    else ()
        add_custom_command(TARGET bomberman PRE_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                ${PROJECT_SOURCE_DIR}/libs/irrlicht/bin/Win32-VisualStudio/Irrlicht.dll
                ${PROJECT_SOURCE_DIR}/bin/Irrlicht.dll)
        add_custom_command(TARGET bomberman PRE_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                ${PROJECT_SOURCE_DIR}/libs/irrklang/bin/Winx32/irrKlang.dll
                ${PROJECT_SOURCE_DIR}/bin/irrKlang.dll)
        add_custom_command(TARGET bomberman PRE_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                ${PROJECT_SOURCE_DIR}/libs/irrklang/bin/Winx32/ikpMP3.dll
                ${PROJECT_SOURCE_DIR}/bin/ikpMP3.dll)
        set(IRRKLANG_LIBRARY ${PROJECT_SOURCE_DIR}/libs/irrklang/lib/Winx32-visualStudio/irrKlang.lib)
    endif ()
endif()

target_link_libraries(bomberman ${IRRKLANG_LIBRARY})
target_include_directories(bomberman PRIVATE ${IRRKLANG_DIR}/include)

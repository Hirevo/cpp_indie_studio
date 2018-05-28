/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** SceneHandler.hpp
*/

#ifndef BOMBERMAN_SCENEHANDLER_HPP
	#define BOMBERMAN_SCENEHANDLER_HPP

	#include <stack>
	#include <IScene.hpp>

class SceneHandler {
public:
	SceneHandler(Eo::IScene *scene);
	~SceneHandler();
	Eo::IScene *getCurrentScene();
	bool addScene(Eo::IScene *scene);
	bool endCurrentScene();
private:
	std::stack<Eo::IScene *> scenes;
};

#endif //BOMBERMAN_SCENEHANDLER_HPP

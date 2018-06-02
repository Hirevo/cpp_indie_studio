/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** SceneHandler.hpp
*/

#pragma once

#include <stack>
#include <IScene.hpp>
#include "Device.hpp"

namespace Eo {
	class SceneHandler {
	public:
		explicit SceneHandler(Eo::Device &device);
		~SceneHandler();
		Eo::IScene *getCurrentScene() const;
		bool loadScene(Eo::IScene *scene);
		bool unloadCurrentScene();
		int getNumberScenes();

	private:
		std::stack<Eo::IScene *> _scenes;
	};
}

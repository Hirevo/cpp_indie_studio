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
		bool addScene(Eo::IScene *scene);
		bool endCurrentScene();

	private:
		std::stack<Eo::IScene *> _scenes;
	};
}

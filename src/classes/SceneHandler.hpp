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
		explicit SceneHandler(Eo::Rc<Eo::Device> device);
		~SceneHandler();
		bool loadScene(Eo::Rc<Eo::IScene> scene);
		bool unloadCurrentScene();
		Eo::Rc<Eo::IScene> getCurrentScene() const;
		std::size_t getSceneCount() const;

	private:
		std::stack<Eo::Rc<Eo::IScene>> _scenes;
	};
}

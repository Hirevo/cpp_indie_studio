/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#ifndef BOMBERMAN_SCENE_HPP
#define BOMBERMAN_SCENE_HPP

#include <memory>
#include "irrlicht.h"
#include <stack>
#include <IMeshSceneNode.h>
#include "IScene.hpp"
#include "Core.hpp"

namespace Eo {
	class Scene : IScene {
	public:
		Scene(Eo::Core &core);
	private:
		irr::scene::ISceneManager* _sceneManager;
		std::stack<irr::scene::IMeshSceneNode*> _map;
	public:
		Scene();
		void addMapBlock();
	};
}
#endif

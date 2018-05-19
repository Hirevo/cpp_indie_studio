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
#include "IScene.hpp"

namespace Eo {
	class Core;
	class Scene : IScene {
	public:
		Scene(Eo::Core &core);
	private:
		Eo::Core &_core;
		irr::scene::ISceneManager* _sceneManager;
		std::stack<irr::scene::IMeshSceneNode*> _map;
	public:
		void addMapBlock(irr::f32 unitSize,
			const irr::core::vector3df &pos);
		irr::scene::ISceneManager *get_sceneManager() const;
	};
}
#endif

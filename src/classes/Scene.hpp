/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#ifndef BOMBERMAN_SCENE_HPP
#define BOMBERMAN_SCENE_HPP

#include "Device.hpp"
#include "IScene.hpp"
#include "irrlicht.h"
#include <memory>
#include <stack>

namespace Eo {
	class Scene : IScene {
	public:
		Scene(Eo::Device &device);

	private:
		Eo::Device &_device;
		irr::scene::ISceneManager *_sceneManager;
		std::stack<irr::scene::IMeshSceneNode *> _map;

	public:
		void addMapBlock(
			irr::f32 unitSize, const irr::core::vector3df &pos);
		void addMapBlock(irr::f32 x, irr::f32 y, irr::f32 z);
		irr::scene::ISceneManager *get_sceneManager() const;
	};
}
#endif

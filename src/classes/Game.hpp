/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#ifndef BOMBERMAN_SCENE_HPP
#define BOMBERMAN_SCENE_HPP

#include <memory>
#include <stack>
#include <AGame.hpp>
#include "Device.hpp"
#include "interfaces/IScene.hpp"
#include "irrlicht.h"

namespace Eo {
	class Game : public AGame {
	public:
		Game(Eo::Device &device);

		void addMapBlock(
			irr::f32 unitSize, const irr::core::vector3df &pos);
		void addMapFloor();
		void addMapBlock(irr::f32 x, irr::f32 y, irr::f32 z);
		irr::scene::ISceneManager *getSceneManager() const override;
	};
}
#endif

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
		virtual ~Game() = default;

		irr::scene::ISceneManager *getSceneManager() const override;
		irr::scene::ICameraSceneNode *getCamera() const override;
	};
}
#endif

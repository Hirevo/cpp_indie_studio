/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#pragma once

#include "IScene.hpp"
#include "Device.hpp"

namespace Eo {
	class AScene : public IScene {
	public:
		AScene(Eo::Device &_device);
		virtual ~AScene() = 0;
		irr::scene::ISceneManager *getSceneManager() const override;
		irr::scene::ICameraSceneNode *getCamera() const override;

	protected:
		Device _device;
 		irr::scene::ISceneManager *_sceneManager;
	};
};

/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#ifndef BOMBERMAN_AMENU_HPP
	#define BOMBERMAN_AMENU_HPP

	#include <Device.hpp>
	#include "IScene.hpp"

namespace Eo {
	class AMenu : public IScene {
	public:
		explicit AMenu(Eo::Device &_device);
		~AMenu();
		irr::scene::ISceneManager *getSceneManager() const override;
		irr::scene::ICameraSceneNode *getCamera() const override;
		bool clean() const override;
		bool draw() override;
	protected:
		Eo::Device &_device;
		irr::scene::ISceneManager *_sceneManager;
	};
};

#endif

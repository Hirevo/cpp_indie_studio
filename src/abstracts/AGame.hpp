/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#ifndef BOMBERMAN_AGAME_HPP
	#define BOMBERMAN_AGAME_HPP

#include <Device.hpp>
#include <string>
#include "IScene.hpp"

namespace Eo {
	class AGame : public IScene {
	public:
		explicit AGame(Eo::Device &_device);
		~AGame();
		irr::scene::ISceneManager *getSceneManager() const override;
		bool clean() const override;
		bool draw() override;
	protected:
		Eo::Device &_device;
		irr::scene::ISceneManager *_sceneManager;
	};
}

#endif

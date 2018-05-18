/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#ifndef BOMBERMAN_CORE_HPP
#define BOMBERMAN_CORE_HPP

#include <memory>
#include <stack>
#include <IrrlichtDevice.h>
#include "Scene.hpp"

namespace Eo {
	class Core {
	public:
	private:
		irr::IrrlichtDevice* _device;
		irr::video::IVideoDriver* _driver;
		std::stack<std::unique_ptr<Eo::Scene>> _stateMachine;
	};
}

#endif

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
#include "Options.hpp"

namespace Eo {
	class Core {
	public:
		Core();
		virtual ~Core();
		irr::IrrlichtDevice *get_device() const;
	private:
		Eo::Options _options;
		irr::IrrlichtDevice* _device;
		irr::video::IVideoDriver *_driver;
		//std::stack<std::unique_ptr<Eo::Scene>> _stateMachine;
	};
}

#endif

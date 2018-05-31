/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#ifndef BOMBERMAN_EOEVENT_HPP
#define BOMBERMAN_EOEVENT_HPP

#include <irrlicht.h>
#include <map>
#include <functional>
#include "Options.hpp"
#include "Device.hpp"

namespace Eo {
	class Event : public irr::IEventReceiver {
	public:
		Event(Eo::Options &, Eo::Device &device);
		virtual bool OnEvent(const irr::SEvent &event);
	private:
		Eo::Options &_options;
		Eo::Device &_device;
		void keyExit();
		void keyDebugToggle(const irr::SEvent &event);
	};
}

#endif

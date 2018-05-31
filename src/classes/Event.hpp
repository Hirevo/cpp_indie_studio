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

namespace Eo {
	class Event : public irr::IEventReceiver {
	public:
		Event(Eo::Options &);
		virtual bool OnEvent(const irr::SEvent &event);
	private:
		Eo::Options &_options;
	};
}
#endif

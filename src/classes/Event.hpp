/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#ifndef BOMBERMAN_EOEVENT_HPP
#define BOMBERMAN_EOEVENT_HPP

#include <irrlicht.h>
namespace Eo {
	class Event : public irr::IEventReceiver {
	public:
		Event();
		void majPosMesh();
		virtual bool OnEvent(const irr::SEvent &event);
	private:
		bool _leaveRequest;
	public:
		bool isleaveRequest() const;
	};
}

#endif

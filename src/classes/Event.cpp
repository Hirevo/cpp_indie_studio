/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "Event.hpp"

bool Eo::Event::OnEvent(const irr::SEvent &event)
{
	bool ret = false;
	if(event.EventType == irr::EET_KEY_INPUT_EVENT
		&& event.KeyInput.Key == irr::KEY_KEY_K)
	{
		_leaveRequest = event.KeyInput.PressedDown;
		ret = true;
	}
	return ret;
}

Eo::Event::Event() :
	_leaveRequest(false)
{
}

bool Eo::Event::isleaveRequest() const
{
	return _leaveRequest;
}

/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "EventGame.hpp"

bool Eo::EventGame::OnEvent(const irr::SEvent &event)
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

Eo::EventGame::EventGame() :
	_leaveRequest(false)
{
}

bool Eo::EventGame::isleaveRequest() const
{
	return _leaveRequest;
}

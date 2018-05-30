/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "AMenu.hpp"

Eo::AMenu::AMenu(Eo::Device &_device) : _device(_device),
	_sceneManager(_device.getDevice()->getSceneManager())
{
}

Eo::AMenu::~AMenu()
{

}

irr::scene::ISceneManager *Eo::AMenu::getSceneManager() const
{
	return this->_sceneManager;
}

irr::scene::ICameraSceneNode *Eo::AMenu::getCamera() const
{
	return nullptr;
}
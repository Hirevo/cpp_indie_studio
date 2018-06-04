
/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "AScene.hpp"

Eo::AScene::AScene(Eo::Device &device) : _device(device),
	_sceneManager(_device.getDevice()->getSceneManager())
{
}

Eo::AScene::~AScene() = default;

irr::scene::ISceneManager *Eo::AScene::getSceneManager() const
{
	return _sceneManager;
}

irr::scene::ICameraSceneNode *Eo::AScene::getCamera() const
{
	return nullptr;
}

bool Eo::AScene::clear()
{
	this->_sceneManager->clear();
	this->_device.getDevice()->getGUIEnvironment()->clear();
	return true;
}

bool Eo::AScene::draw()
{
	return false;
}

void Eo::AScene::update()
{
}
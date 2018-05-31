
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

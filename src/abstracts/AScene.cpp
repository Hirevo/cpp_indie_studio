
/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "AScene.hpp"

Eo::AScene::AScene(Eo::Rc<Eo::Event> event, Eo::Rc<Eo::Device> device,
	Eo::Rc<Eo::SceneHandler> sceneHandler, Eo::Rc<Eo::SoundDevice> sound) :
	_device(device), _event(event),
	_sceneManager(_device->getDevice()->getSceneManager()),
	_sceneHandler(sceneHandler), _sound(sound)
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
	_sceneManager->clear();
	_device->getDevice()->getGUIEnvironment()->clear();
	return true;
}

bool Eo::AScene::draw()
{
	return false;
}

void Eo::AScene::update()
{
}

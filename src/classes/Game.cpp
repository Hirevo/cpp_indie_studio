/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "Game.hpp"
#include "Floor.hpp"
#include "Player.hpp"
#include <iostream>

Eo::Game::Game(Eo::Event &event, Eo::Device &device,
	const std::string &mapPath
)
	: AScene(event, device),
	  _json(mapPath),
	  _map(_json),
	  _camera()
{
}

Eo::Game::~Game()
{
}

irr::scene::ICameraSceneNode *Eo::Game::getCamera() const
{
	return dynamic_cast<irr::scene::ICameraSceneNode *>(
		_camera.getSceneNode());
}

bool Eo::Game::draw()
{
	Eo::IObject *obj;
	irr::s32 wth = _map.getWidth();
	irr::s32 hgt = _map.getHeight();
	auto texture = _sceneManager->getVideoDriver()->getTexture(
		"../assets/img/red_silk.jpg");
	auto model = new Eo::Player();
	model->loadModel(this, "../assets/Bomberman/character.blend.x",
		"../assets/Bomberman/bomberboy_colors_white.png");
	model->animate(Eo::animType::EMAT_RUN);
	model->getAnimatedNode()->setScale(Eo::vec3(2.5));
	_event.addKeyHandler(Eo::keyCode::KEY_KEY_Z,
		[this, &model](bool &toRemove, const Eo::event &ev) {
		model->translateX(0.02);
		model->updateInScene(this);
	});
	_camera.insertStaticInScene(this);
	Eo::Floor floor((wth - 1) * (hgt - 1) - 10, Eo::vec3(0, -5, 0));
	floor.insertInScene(this);
	for (irr::s32 i = 0; i < hgt; i++)
		for (irr::s32 j = 0; j < wth; j++) {
			obj = _map.getObject(j, i);
			if (obj) {
				obj->setPosition((j - (wth / 2)) * 10, 0,
					(i - (hgt / 2)) * 10);
				obj->insertInScene(this);
				obj->getSceneNode()->setMaterialFlag(
					irr::video::EMF_LIGHTING, false);
				obj->getSceneNode()->setMaterialTexture(0,
					texture);
			}
		}
	return true;
}

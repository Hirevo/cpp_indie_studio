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
	const std::string &mapPath, Eo::Options &options)
	: AScene(event, device), _json(mapPath), _map(_json), _camera(),
	  _options(options)
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
	irr::s32 wth = _map.getWidth();
	irr::s32 hgt = _map.getHeight();
	auto texture = _sceneManager->getVideoDriver()->getTexture(
		"../assets/img/brick.png");
	_players.fill(nullptr);
	for (Eo::u32 i = 0; i < _options.getNbPlayer(); i++)
		_players.at(i) = new Eo::Player(*this, _event, _options);
	_camera.insertStaticInScene(this);
	auto floor = new Eo::Floor((wth - 1) - 1, Eo::vec3(0, -0.5, 0));
	floor->insertInScene(this);
	_objects.push_back(floor);
	Eo::Game::insertMap(texture, wth, hgt);
	Eo::Game::addEvents();
	return true;
}

void Eo::Game::insertMap(
	irr::video::ITexture *texture, irr::s32 wth, irr::s32 hgt)
{
	for (irr::s32 i = 0; i < hgt; i++)
		for (irr::s32 j = 0; j < wth; j++) {
			auto obj = _map.getObject(j, i);
			if (obj) {
				obj->setPosition(
					(j - wth / 2), 0, (i - hgt / 2));
				obj->insertInScene(this);
				obj->getSceneNode()->setMaterialFlag(
					irr::video::EMF_LIGHTING, false);
				obj->getSceneNode()->setMaterialTexture(
					0, texture);
			}
		}
}

Eo::keyHandler Eo::Game::getPlayerEventFunc(
	Eo::Player *player, Eo::Player::Motion flag)
{
	return [this, player, flag](bool &toRemove, const Eo::event &ev) {
		auto state = ev.KeyInput.PressedDown;
		auto func = (state ? &Eo::Player::setFlag :
				     &Eo::Player::unsetFlag);
		(player->*func)(flag);
	};
}

void Eo::Game::addPlayerEvents(Eo::Player *player)
{
	auto id = _options.getPlayerKeys().at(player->getPlayerId());

	_event.addKeyHandler(id._up,
		Eo::Game::getPlayerEventFunc(
			player, Eo::Player::Motion::Forward));
	_event.addKeyHandler(id._left,
		Eo::Game::getPlayerEventFunc(
			player, Eo::Player::Motion::Left));
	_event.addKeyHandler(id._down,
		Eo::Game::getPlayerEventFunc(
			player, Eo::Player::Motion::Backward));
	_event.addKeyHandler(id._right,
		Eo::Game::getPlayerEventFunc(
			player, Eo::Player::Motion::Right));
}

void Eo::Game::addEvents()
{
	std::for_each(
		_players.begin(), _players.end(), [this](Eo::Player *player) {
			if (player)
				Eo::Game::addPlayerEvents(player);
		});
	_event.addKeyHandler(_options.getKeyExit(),
		[this](bool &toRemove, const Eo::event &ev) {
			if (!ev.KeyInput.PressedDown)
				return;
			_options.setExit(true);
		});
}

void Eo::Game::update()
{
	std::for_each(
		_players.begin(), _players.end(), [this](Eo::Player *player) {
			if (player == nullptr)
				return;
			auto flags = player->getFlag();
			auto dir = Eo::vec3(0);
			auto fwd = ((flags & Eo::Player::Motion::Forward) != 0);
			auto bwd = ((flags & Eo::Player::Motion::Backward) != 0);
			auto rgt = ((flags & Eo::Player::Motion::Right) != 0);
			auto lft = ((flags & Eo::Player::Motion::Left) != 0);
			dir.Z += (fwd ? player->getSpeed() : 0);
			dir.Z += (bwd ? -player->getSpeed() : 0);
			dir.X += (rgt ? player->getSpeed() : 0);
			dir.X += (lft ? -player->getSpeed() : 0);
			if (isValidMove(player->getPosition() + dir, player->getPlayerId())) {
				player->translate(dir);
				player->updateInScene(this);
			}
		});
}

bool Eo::Game::isValidMove(Eo::vec3 newPos, irr::u64 id)
{
	auto posX = roundf(newPos.X) + _map.getWidth() / 2;
	auto posY = roundf(newPos.Z) + _map.getHeight() / 2;
	Eo::vec2 pos(posX, posY);
	auto object = _map.getObject(pos.X, pos.Y);
	if (!object)
		return true;
	auto type = object->getType();
	return !(type == IObject::WALL);
}

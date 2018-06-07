/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Booster.cpp
*/

#include "AObject.hpp"
#include <unordered_map>
#include "Booster.hpp"

const std::unordered_map<Eo::Booster::BoosterType, std::string> Eo::Booster::_textures{
	{Eo::Booster::BoosterType::SPEED, "../assets/img/roller.jpg"},
	{Eo::Booster::BoosterType::SUPERBOMB, "../assets/img/superbomb.jpg"},
	{Eo::Booster::BoosterType::NBBOMB, "../assets/img/bomb.png"}};

Eo::Booster::Booster(Eo::Booster::BoosterType boosterType, Eo::vec3 pos)
	: AObject(static_cast<Eo::IObject::Type>(boosterType)), _boosterType(boosterType)
{
}

#include <iostream>

void Eo::Booster::insertInScene(const Eo::IScene *scene)
{
	auto manager = scene->getSceneManager();
	irr::f32 unitSize = 1.0f;

	if (_placedInScene == true)
		return;
	std::cout << "HERE I AM" << std::endl;
	//_node = manager->addCubeSceneNode(unitSize, nullptr, -1, _pos);
	_node = manager->addBillboardSceneNode(nullptr, Eo::vec2(0.5));
	_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_node->setMaterialTexture(0, manager->getVideoDriver()->getTexture(_textures.at(_boosterType).c_str()));
	Eo::Booster::updateInScene(scene);
	_hasPositionChanged = false;
	_hasNode = true;
	_placedInScene = true;
}

void Eo::Booster::removeFromScene(const Eo::IScene *scene)
{
	(void)(scene);
	if (_placedInScene == false || _hasNode == false)
		return;
	_node->remove();
	_hasPositionChanged = false;
	_placedInScene = false;
}

void Eo::Booster::updateInScene(const Eo::IScene *scene)
{
	if (_placedInScene == false || _hasNode == false)
		return;
	_node->setPosition(_pos);
	_hasPositionChanged = false;
}
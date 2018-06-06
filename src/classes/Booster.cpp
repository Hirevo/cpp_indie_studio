/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Booster.cpp
*/

#include "Booster.hpp"

Eo::Booster::Booster(Eo::Booster::BoosterType boosterType, Eo::vec3 pos)
	: AObject(Eo::IObject::BOOSTER), _boosterType(boosterType)
{
}

void Eo::Booster::insertInScene(const Eo::IScene *scene)
{
	auto manager = scene->getSceneManager();
	irr::f32 unitSize = 1.0f;

	if (_placedInScene == true)
		return;
	_node = manager->addCubeSceneNode(unitSize, nullptr, -1, _pos);
	_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	Eo::Booster::updateInScene(scene);
	_hasPositionChanged = false;
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
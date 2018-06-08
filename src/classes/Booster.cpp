/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Booster.cpp
*/

#include <unordered_map>
#include "AObject.hpp"
#include "Booster.hpp"

const std::unordered_map<Eo::Booster::BoosterType, std::string> Eo::Booster::_mesh{
	{Eo::Booster::BoosterType::SPEED, "../assets/Bomberman/PowerUp.x"},
	{Eo::Booster::BoosterType::SUPERBOMB, "../assets/Bomberman/PowerUp.x"},
	{Eo::Booster::BoosterType::NBBOMB, "../assets/Bomberman/PowerUp.x"}};

const std::unordered_map<Eo::Booster::BoosterType, std::string> Eo::Booster::_textures{
	{Eo::Booster::BoosterType::SPEED, "../assets/img/roller.png"},
	{Eo::Booster::BoosterType::SUPERBOMB, "../assets/img/superbomb.png"},
	{Eo::Booster::BoosterType::NBBOMB, "../assets/img/bomb.png"}};

Eo::Booster::Booster(Eo::Booster::BoosterType boosterType, Eo::vec3 pos)
	: AObject(static_cast<Eo::IObject::Type>(boosterType)),
	  _boosterType(boosterType)
{
}

void Eo::Booster::insertInScene(const Eo::Rc<Eo::IScene> scene)
{
	auto manager = scene->getSceneManager();
	irr::f32 unitSize = 1.0f;
	irr::core::vector3df rotation(0.0f, 0.0f, 0.0f);
	irr::core::vector3df scale(0.2f, 0.2f, 0.2f);

	if (_placedInScene == true)
		return;
	_node =	manager->addAnimatedMeshSceneNode(manager->getMesh(_mesh.at(_boosterType).c_str()),
	                                                 nullptr, -1, _pos, rotation, scale);
	_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_node->setMaterialTexture(0, manager->getVideoDriver()->getTexture(_textures.at(_boosterType).c_str()));
	Eo::Booster::updateInScene();
	_hasPositionChanged = false;
	_hasNode = true;
	_placedInScene = true;
}

void Eo::Booster::removeFromScene()
{
	if (_placedInScene == false || _hasNode == false)
		return;
	_node->remove();
	_hasPositionChanged = false;
	_placedInScene = false;
}

void Eo::Booster::updateInScene()
{
	if (_placedInScene == false || _hasNode == false)
		return;
	_node->setPosition(_pos);
	_hasPositionChanged = false;
}

Eo::Booster::BoosterType Eo::Booster::getBoosterType() const
{
	return _boosterType;
}

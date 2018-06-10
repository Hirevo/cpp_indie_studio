/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Booster.cpp
*/

#include <unordered_map>
#include "AObject.hpp"
#include "Booster.hpp"

Eo::Booster::Booster(Eo::Booster::BoosterType boosterType, Eo::vec3 pos)
	: AObject(static_cast<Eo::IObject::Type>(boosterType), nullptr, pos),
	_boosterType(boosterType)
{
	_mesh = {
	{Eo::Booster::BoosterType::SPEED,
		currPath + "assets/Bomberman/PowerUp.x"},
	{Eo::Booster::BoosterType::SUPERBOMB,
		currPath + "assets/Bomberman/PowerUp.x"},
	{Eo::Booster::BoosterType::NBBOMB,
		currPath + "assets/Bomberman/PowerUp.x"},
	{Eo::Booster::BoosterType::WALLPASS,
		currPath + "assets/Bomberman/PowerUp.x"}};
	_textures = {
	{Eo::Booster::BoosterType::SPEED,
		currPath + "assets/img/roller.png"},
	{Eo::Booster::BoosterType::SUPERBOMB,
		currPath + "assets/img/superbomb.png"},
	{Eo::Booster::BoosterType::NBBOMB,
		currPath + "assets/img/bomb.png"},
	{Eo::Booster::BoosterType::WALLPASS,
		currPath + "assets/img/wall_pass.png"}};

}

void Eo::Booster::insertInScene(const Eo::Rc<Eo::IScene> scene)
{
	auto manager = scene->getSceneManager();
	irr::f32 unitSize = 1.0f;
	irr::core::vector3df rotation(0.0f, 0.0f, 0.0f);
	irr::core::vector3df scale(0.2f, 0.2f, 0.2f);
	_node = manager->addAnimatedMeshSceneNode(manager->getMesh(
		_mesh.at(_boosterType).c_str()), nullptr, -1, _pos,
		rotation, scale);
	_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_node->setMaterialTexture(0, manager->getVideoDriver()->getTexture(
		_textures.at(_boosterType).c_str()));
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

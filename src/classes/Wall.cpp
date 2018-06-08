/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Wall
*/

#include "Wall.hpp"

const std::unordered_map<Eo::Wall::WallType, std::string> Eo::Wall::_textures{
	{Eo::Wall::WallType::DESTRUCTIBLE, "../assets/img/brick.png"},
	{Eo::Wall::WallType::INDESTRUCTIBLE, "../assets/img/block.png"}};

Eo::Wall::Wall(Eo::Wall::WallType wallType, Eo::vec3 pos)
	: AObject(static_cast<Eo::IObject::Type>(wallType)),
	  _wallType(wallType)
{
}

Eo::Wall::~Wall()
{
}

void Eo::Wall::insertInScene(const Eo::Rc<Eo::IScene> scene)
{
	auto manager = scene->getSceneManager();
	irr::f32 unitSize = 1.0f;

	if (_placedInScene == true)
		return;
	_node = manager->addCubeSceneNode(unitSize, nullptr, -1, _pos);
	_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_node->setMaterialTexture(0,
		manager->getVideoDriver()->getTexture(
			_textures.at(_wallType).c_str()));
	Eo::Wall::updateInScene();
	_hasPositionChanged = false;
	_hasNode = true;
	_placedInScene = true;
}

void Eo::Wall::updateInScene()
{
	if (_placedInScene == false || _hasNode == false)
		return;
	_node->setPosition(_pos);
	_hasPositionChanged = false;
}

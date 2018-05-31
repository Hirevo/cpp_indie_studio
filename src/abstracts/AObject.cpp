/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** AObject
*/

#include "AObject.hpp"
#include <stdexcept>

Eo::AObject::AObject(
	Eo::IObject::Type type, irr::scene::ISceneNode *node, Eo::vec3 pos)
	: AMovable(pos), _type(type), _node(node), _placedInScene(false),
	  _hasNode(node != nullptr)
{
}

Eo::AObject::~AObject() = default;

Eo::IObject::Type Eo::AObject::getType() const
{
	return _type;
}

irr::scene::ISceneNode *Eo::AObject::getSceneNode() const
{
	return _node;
}

void Eo::AObject::setSceneNode(irr::scene::ISceneNode *node)
{
	_node = node;
}

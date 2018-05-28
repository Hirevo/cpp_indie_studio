/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** AObject
*/

#include <stdexcept>
#include "AObject.hpp"

Eo::AObject::AObject(Eo::IObject::Type type, irr::scene::IMeshSceneNode *node)
	: _type(type), _node(node), _placedInScene(false)
{
}

Eo::IObject::Type Eo::AObject::getType() const
{
	return _type;
}

irr::scene::IMeshSceneNode *Eo::AObject::getSceneNode()
{
	return _node;
}

void Eo::AObject::setSceneNode(irr::scene::IMeshSceneNode *node)
{
	_node = node;
}

void Eo::AObject::insertInScene(Eo::IScene *scene)
{
	throw std::runtime_error("Method non implemented");
}

void Eo::AObject::removeFromScene(Eo::IScene *scene)
{
	throw std::runtime_error("Method non implemented");
}

void Eo::AObject::updateInScene(Eo::IScene *scene)
{
	throw std::runtime_error("Method non implemented");
}

/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** AObject
*/

#include "AObject.hpp"
#include <stdexcept>

Eo::AObject::AObject(Eo::IObject::Type type, irr::scene::ISceneNode *node, irr::core::vector3df pos)
	: AMovable(pos), _type(type), _node(node), _placedInScene(false),
	  _isInstanciated(node != nullptr)
{
}

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

void Eo::AObject::insertFPSInScene(Eo::IScene *scene)
{
	throw std::runtime_error("Method non implemented");
}

void Eo::AObject::insertStaticInScene(Eo::IScene *scene)
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


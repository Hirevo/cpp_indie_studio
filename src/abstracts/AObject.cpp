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

void Eo::AObject::deleteNode(const Eo::IScene *scene)
{
	this->removeFromScene(scene);
	if (_hasNode) {
		delete _node;
		_node = 0;
		_hasNode = 0;
	}
}

void Eo::AObject::insertInScene(const Eo::IScene *scene)
{
	this->removeFromScene(scene);
	if (_hasNode)
		delete _node;
	_hasNode = false;
}

void Eo::AObject::removeFromScene(const Eo::IScene *scene)
{
	throw std::runtime_error("Method non implemented");
}

void Eo::AObject::updateInScene(const Eo::IScene *scene)
{
	throw std::runtime_error("Method non implemented");
}

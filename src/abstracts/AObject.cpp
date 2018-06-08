/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** AObject
*/

#include "AObject.hpp"
#include <stdexcept>

Eo::AObject::AObject(
	Eo::IObject::Type type, Eo::node *node, Eo::vec3 pos)
	: AMovable(pos), _type(type), _node(node), _placedInScene(false),
	  _hasNode(node != nullptr)
{
}

Eo::AObject::~AObject() {
	this->removeFromScene();
}

Eo::IObject::Type Eo::AObject::getType() const
{
	return _type;
}

Eo::node *Eo::AObject::getSceneNode() const
{
	return _node;
}

void Eo::AObject::setSceneNode(Eo::node *node)
{
	_node = node;
	_hasNode = true;
}

void Eo::AObject::insertInScene(const Eo::Rc<Eo::IScene> scene)
{
	_hasNode = false;
}

void Eo::AObject::removeFromScene()
{
	if (_hasNode && _node && _node->getParent())
		_node->remove();
	_hasNode = false;
	_placedInScene = false;
}

void Eo::AObject::updateInScene()
{
	throw std::runtime_error("Method not implemented");
}

bool Eo::AObject::update()
{
	return true;
}

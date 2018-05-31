/*
** EPITECH PROJECT, 2018
** indie_studio
** File description:
** AModel
*/

#include "AModel.hpp"

Eo::AModel::AModel(Eo::IObject::Type type, vec3 pos)
	: AObject(type, 0, pos), _mesh(0), _hasMesh(false)
{
}

Eo::AModel::~AModel() = default;

Eo::AModel::AModel(Eo::IObject::Type type, const Eo::IScene *scene,
	const std::string &path, vec3 pos)
	: Eo::AModel::AModel(type, pos)
{
	Eo::AModel::loadModel(scene, path);
}

void Eo::AModel::insertInScene(const Eo::IScene *scene)
{
	if (_placedInScene)
		return;
	if (_hasNode == false) {
		_node = scene->getSceneManager()->addAnimatedMeshSceneNode(
			_mesh);
		_hasNode = true;
	}
	else
		scene->getSceneManager()->addCameraSceneNodeFPS(_node);
	Eo::AModel::updateInScene(scene);
	_placedInScene = true;
}

void Eo::AModel::removeFromScene(const Eo::IScene *scene)
{
	if (_placedInScene)
		_node->remove();
}

void Eo::AModel::updateInScene(const Eo::IScene *scene)
{
	if (_hasNode) {
		_node->setPosition(_pos);
		_hasPositionChanged = false;
	}
}

void Eo::AModel::loadModel(const Eo::IScene *scene, const std::string &path)
{
	if (_hasMesh) {
		Eo::AModel::removeFromScene(scene);
		delete _mesh;
	}
	_mesh = scene->getSceneManager()->getMesh(path.c_str());
	_node = scene->getSceneManager()->addAnimatedMeshSceneNode(_mesh);
	_node->setPosition(_pos);
	_hasMesh = true;
}

irr::scene::IAnimatedMesh *Eo::AModel::getMesh() const
{
	return _mesh;
}

void Eo::AModel::setMesh(irr::scene::IAnimatedMesh *model)
{
	if (_hasMesh)
		delete _mesh;
	_mesh = model;
	_hasMesh = true;
}
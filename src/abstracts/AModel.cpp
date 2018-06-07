/*
** EPITECH PROJECT, 2018
** indie_studio
** File description:
** AModel
*/

#include "AModel.hpp"

Eo::AModel::AModel(Eo::IObject::Type type, Eo::vec3 pos)
	: AObject(type, 0, pos), _mesh(0), _hasMesh(false)
{
}

Eo::AModel::~AModel() = default;

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
		_node->setRotation(vec3(0, _rotation, 0));
		_hasPositionChanged = false;
	}
}

void Eo::AModel::deleteNode(const Eo::IScene *scene)
{
	Eo::AObject::deleteNode(scene);
	if (_hasMesh)
		delete _mesh;
	_hasMesh = false;
}

void Eo::AModel::loadModel(const Eo::IScene *scene,
	const std::string &modelPath, const std::string &texPath)
{
	this->deleteNode(scene);
	auto sceneManager = scene->getSceneManager();
	auto driver = sceneManager->getVideoDriver();
	_mesh = sceneManager->getMesh(modelPath.c_str());
	_animatedNode = sceneManager->addAnimatedMeshSceneNode(_mesh);
	_node = _animatedNode;
	_animatedNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_animatedNode->setMaterialTexture(
		0, driver->getTexture(texPath.c_str()));
	_animatedNode->setFrameLoop(0, 0);
	_animatedNode->setPosition(_pos);
	_hasMesh = true;
	_hasNode = true;
	_placedInScene = true;
}

Eo::animatedMesh *Eo::AModel::getMesh() const
{
	return _mesh;
}

void Eo::AModel::setMesh(Eo::animatedMesh *model)
{
	if (_hasMesh)
		delete _mesh;
	_mesh = model;
	_hasMesh = true;
}

Eo::animatedNode *Eo::AModel::getAnimatedNode() const
{
	return _animatedNode;
}

void Eo::AModel::animate(Eo::animType type) const
{
	//todo comment because it doesn't work
	//if (_hasNode)
	//	_animatedNode->setMD2Animation();
}

const Eo::vec3 &Eo::AModel::getScale() const
{
	return _scale;
}

void Eo::AModel::setScale(const Eo::vec3 &_scale)
{
	AModel::_scale = _scale;
}

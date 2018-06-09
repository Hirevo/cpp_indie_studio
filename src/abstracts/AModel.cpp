/*
** EPITECH PROJECT, 2018
** indie_studio
** File description:
** AModel
*/

#include "AModel.hpp"

Eo::AModel::AModel(Eo::IObject::Type type, Eo::vec3 pos)
	: AObject(type, nullptr, pos), _mesh(0), _animatedNode(0),
	  _hasMesh(false)
{
}

Eo::AModel::~AModel() {
}

void Eo::AModel::insertInScene(const Eo::Rc<Eo::IScene> scene)
{
	if (_placedInScene)
		return;
	if (_hasNode == false) {
		_node = scene->getSceneManager()->addAnimatedMeshSceneNode(
			_mesh);
	}
	else
		scene->getSceneManager()->addAnimatedMeshSceneNode(nullptr,
			_node);
	Eo::AModel::updateInScene();
	_hasNode = true;
	_placedInScene = true;
}

void Eo::AModel::updateInScene()
{
	if (_hasNode) {
		_node->setPosition(_pos);
		_node->setRotation(vec3(0, _rotation, 0));
		_hasPositionChanged = false;
	}
}

void Eo::AModel::loadModel(const Eo::Rc<Eo::IScene> scene,
	const std::string &modelPath, const std::string &texPath)
{
	removeFromScene();
	auto sceneManager = scene->getSceneManager();
	auto driver = sceneManager->getVideoDriver();
	_mesh = sceneManager->getMesh(modelPath.c_str());
	_animatedNode = sceneManager->addAnimatedMeshSceneNode(_mesh);
	_node = _animatedNode;
	_animatedNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_animatedNode->setMaterialTexture(
		0, driver->getTexture(texPath.c_str()));
	_animatedNode->setPosition(_pos);
	_animatedNode->setAnimationSpeed(42.f);
	_hasMesh = true;
	_hasNode = true;
	_placedInScene = true;
}

void Eo::AModel::loadModel(const Eo::Rc<Eo::IScene> scene,
	const std::string &modelPath)
{
	removeFromScene();
	auto sceneManager = scene->getSceneManager();
	auto driver = sceneManager->getVideoDriver();
	_mesh = sceneManager->getMesh(modelPath.c_str());
	_animatedNode = sceneManager->addAnimatedMeshSceneNode(_mesh);
	_node = _animatedNode;
	_animatedNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_animatedNode->setPosition(_pos);
	_animatedNode->setAnimationSpeed(42.f);
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

void Eo::AModel::setScale(const Eo::vec3 &scale)
{
	_scale = scale;
}

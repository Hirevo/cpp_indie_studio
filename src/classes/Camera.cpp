/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "Camera.hpp"
#include <iostream>

Eo::Camera::Camera(int mapSize, vec3 pos) :
	AObject(Eo::IObject::Type::CAMERA, nullptr, pos), mapSize(mapSize)
{
}

Eo::Camera::~Camera()
{
	_hasNode = false;
}

void Eo::Camera::insertFPSInScene(Eo::Rc<Eo::IScene> scene)
{
	_camType = FPS;
	if (_placedInScene)
		return;
	if (!_hasNode) {
		_keyMap[0].Action = irr::EKA_MOVE_FORWARD;
		_keyMap[0].KeyCode = irr::KEY_KEY_Z;
		_keyMap[1].Action = irr::EKA_MOVE_BACKWARD;
		_keyMap[1].KeyCode = irr::KEY_KEY_S;
		_keyMap[2].Action = irr::EKA_STRAFE_LEFT;
		_keyMap[2].KeyCode = irr::KEY_KEY_Q;
		_keyMap[3].Action = irr::EKA_STRAFE_RIGHT;
		_keyMap[3].KeyCode = irr::KEY_KEY_D;
		_keyMap[4].Action = irr::EKA_JUMP_UP;
		_keyMap[4].KeyCode = irr::KEY_SPACE;

		_camera = scene->getSceneManager()->addCameraSceneNodeFPS(
			nullptr, 200.0f, 0.1f, -1, _keyMap, 5);
		_node = _camera;
	} else
		scene->getSceneManager()->addCameraSceneNodeFPS(_node);
	Eo::Camera::updateInScene();
	_hasNode = true;
	_placedInScene = true;
}

void Eo::Camera::insertStaticInScene(Eo::Rc<Eo::IScene> scene)
{
	irr::core::vector3df position(0, this->mapSize * 4, -25);
	irr::core::vector3df lookat = irr::core::vector3df(0,
		this->mapSize / 10 * -1, 0);
	_camType = STATIC;
	_camera = scene->getSceneManager()->addCameraSceneNode(
		nullptr, position, lookat, -1, true);
	_camera->setFOV(0.25f);
	_node = _camera;
	_pos = position;
	Eo::Camera::updateInScene();
	_hasNode = true;
	_placedInScene = true;
}

void Eo::Camera::insertInScene(const Eo::Rc<Eo::IScene> scene)
{
	Eo::Camera::insertStaticInScene(scene);
}

void Eo::Camera::removeFromScene()
{
}

void Eo::Camera::updateInScene()
{
	if (_hasNode) {
		_node->setPosition(_pos);
		_hasPositionChanged = false;
	}
}

irr::scene::ICameraSceneNode *Eo::Camera::getCameraHandle() const
{
	return _camera;
}

Eo::Camera::cameraType Eo::Camera::getCamType() const
{
	return _camType;
}

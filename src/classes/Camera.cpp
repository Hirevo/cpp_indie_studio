/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "Camera.hpp"

Eo::Camera::Camera(irr::core::vector3df pos)
	: AObject(Eo::IObject::Type::CAMERA, nullptr, pos)
{
}

void Eo::Camera::insertInScene(Eo::IScene *scene)
{
	if (_placedInScene)
		return;
	if (!_isInstanciated) {
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
		// _camera = scene->getSceneManager()->addCameraSceneNodeMaya(
		// 	nullptr, 200.0f, 0.1f, 200.0f, -1);
		_camera = scene->getSceneManager()->addCameraSceneNodeFPS(
			nullptr, 200.0f, 0.1f, -1, _keyMap, 5);
		_node = _camera;
		_isInstanciated = true;
	}
	else
		// scene->getSceneManager()->addCameraSceneNodeMaya(_node);
		scene->getSceneManager()->addCameraSceneNodeFPS(_node);
	Eo::Camera::updateInScene(scene);
	_placedInScene = true;
}

void Eo::Camera::removeFromScene(Eo::IScene *scene)
{
	if (_placedInScene)
		_node->remove();
}

void Eo::Camera::updateInScene(Eo::IScene *scene)
{
	if (_isInstanciated) {
		_node->setPosition(_pos);
		_hasPositionChanged = false;
	}
}

irr::scene::ICameraSceneNode *Eo::Camera::getCameraHandle() const
{
	return _camera;
}

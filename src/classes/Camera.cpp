/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "Camera.hpp"

Eo::Camera::Camera(Eo::IScene *scene) : _scene(scene)
{
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
	_camera = _scene->getSceneManager()->addCameraSceneNodeFPS(
		nullptr, 100.0f, 0.1f, -1, _keyMap, 5);
	irr::core::vector3df pos;
	pos.X = 0;
	pos.Y = 50;
	pos.Z = 0;
	_camera->setPosition(pos);
	_scene->getSceneManager()->setActiveCamera(_camera);
}

irr::scene::ICameraSceneNode *Eo::Camera::getCameraHandle() const
{
	return _camera;
}

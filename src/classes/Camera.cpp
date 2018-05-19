/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "Camera.hpp"

Eo::Camera::Camera(Eo::Scene &scene) :
	_scene(scene)
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

	_scene.get_sceneManager()->addCameraSceneNodeFPS(
		0, 100.0f, 0.1f, -1, _keyMap, 5);
}

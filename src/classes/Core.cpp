/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "Core.hpp"

Eo::Core::~Core()
{
}

Eo::Core::Core() :
	_options(),
	_device(_options),
	_scene(_device)
{
	irr::f32 unitSize = 10.0f;
	irr::core::vector3df pos;
	pos.X = 0;
	pos.Y = 0;
	pos.Z = 20;
	irr::SKeyMap keyMap[5];
	keyMap[0].Action = irr::EKA_MOVE_FORWARD;
	keyMap[0].KeyCode = irr::KEY_KEY_Z;
	keyMap[1].Action = irr::EKA_MOVE_BACKWARD;
	keyMap[1].KeyCode = irr::KEY_KEY_S;
	keyMap[2].Action = irr::EKA_STRAFE_LEFT;
	keyMap[2].KeyCode = irr::KEY_KEY_Q;
	keyMap[3].Action = irr::EKA_STRAFE_RIGHT;
	keyMap[3].KeyCode = irr::KEY_KEY_D;
	keyMap[4].Action = irr::EKA_JUMP_UP;
	keyMap[4].KeyCode = irr::KEY_SPACE;
	_scene.get_sceneManager()->addCameraSceneNodeFPS(nullptr, 100.0f, 0.1f, -1, keyMap, 5);

	_scene.addMapBlock(unitSize, pos);
	_scene.addMapBlock(20, 0, 20);
	irr::video::SColor color(255, 255, 255, 255);

	while (_device.get_device()->run()) {
		_device.get_driver()->beginScene(true, true, color);
		_scene.get_sceneManager()->drawAll ();
		_device.get_driver()->endScene ();
	}

	_device.get_device()->drop ();
}
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

Eo::Core::Core()
	: _options(), _device(_options), _scene(_device), _camera(_scene)
{
	irr::f32 unitSize = 10.0f;
	irr::core::vector3df pos;
	pos.X = 0;
	pos.Y = 0;
	pos.Z = 20;

	_scene.addMapBlock(0, 0, 20);
	_scene.addMapBlock(0, 0, 30);
	_scene.addMapBlock(0, 0, 40);
	_scene.addMapBlock(0, 0, 50);
	_scene.addMapBlock(0, 0, 60);
	_scene.addMapBlock(10, 0, 40);
	_scene.addMapBlock(-10, 0, 40);
	_scene.addMapBlock(20, 0, 40);
	_scene.addMapBlock(-20, 0, 40);
	_scene.addMapBlock(-20, 0, 50);
	_scene.addMapBlock(-20, 0, 60);
	_scene.addMapBlock(20, 0, 30);
	_scene.addMapBlock(20, 0, 20);
	_scene.addMapBlock(-10, 0, 20);
	_scene.addMapBlock(-20, 0, 20);
	_scene.addMapBlock(10, 0, 60);
	_scene.addMapBlock(20, 0, 60);






	irr::video::SColor color(255, 255, 255, 255);

	while (_device.get_device()->run()) {
		_device.get_driver()->beginScene(true, true, color);
		_scene.get_sceneManager()->drawAll();
		_device.get_driver()->endScene();
	}

	_device.get_device()->drop();
}
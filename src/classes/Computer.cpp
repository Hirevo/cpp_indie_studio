/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#include "Computer.hpp"

Eo::Computer::Computer(Eo::Rc<Eo::IScene> game, const Eo::vec3 &pos) 
	: AModel(Eo::IObject::Type::CHARACTER, pos)
{
	this->loadModel(game, "../assets/model-test/sydney.md2",
		"../assets/model-test/sydney.bmp");
	this->getAnimatedNode()->setScale(Eo::vec3(0.020f));
}
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

}
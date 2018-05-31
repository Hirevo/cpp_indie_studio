/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** ACharacter
*/

#include "ACharacter.hpp"
#include <irrlicht.h>

Eo::ACharacter::ACharacter(vec3 pos)
	: AModel(Eo::IObject::Type::CHARACTER, pos), _model(0)
{
}

Eo::ACharacter::~ACharacter() = default;

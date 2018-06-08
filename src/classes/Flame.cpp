/*
** EPITECH PROJECT, 2018
** indie-studio
** File description:
** Flame
*/

#include "Flame.hpp"
#include "Types.hpp"
#include <iostream>

Eo::Flame::Flame(Eo::vec3 pos)
	: AModel(Eo::IObject::Type::FLAME, pos),
	  _clock(std::chrono::high_resolution_clock::now())
{
}

bool Eo::Flame::update()
{
	std::chrono::milliseconds diff =
		std::chrono::duration_cast<std::chrono::milliseconds>(
			std::chrono::high_resolution_clock::now() - _clock);
	std::cout << "Flame <" << _pos.X << "," << _pos.Y << "," << _pos.Z;
	std::cout << "> Diff: " << diff.count() << std::endl;
	using namespace std::chrono_literals;
	return (diff <= BURN_TIME);
}

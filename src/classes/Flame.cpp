/*
** EPITECH PROJECT, 2018
** indie-studio
** File description:
** Flame
*/

#include "Flame.hpp"
#include "Types.hpp"

Eo::Flame::Flame(Eo::Rc<Eo::IScene> scene, Eo::vec3 pos)
	: AModel(Eo::IObject::Type::FLAME, pos),
	  _clock(std::chrono::high_resolution_clock::now())
{
	Eo::Flame::insertInScene(scene);
}

void Eo::Flame::insertInScene(const Eo::Rc<Eo::IScene> scene)
{
	Eo::AModel::loadModel(scene, currPath + "../assets/Bomberman/Flame.x");
	_node->setScale(Eo::vec3(0.25, 0.25, 0.25));
}

bool Eo::Flame::update()
{
	std::chrono::milliseconds diff =
		std::chrono::duration_cast<std::chrono::milliseconds>(
			std::chrono::high_resolution_clock::now() - _clock);
	using namespace std::chrono_literals;
	return (diff <= BURN_TIME);
}

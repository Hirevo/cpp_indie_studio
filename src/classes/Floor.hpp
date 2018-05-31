/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Floor
*/

#pragma once

#include "AMovable.hpp"
#include "AObject.hpp"

namespace Eo {
	class Floor : public AObject {
	public:
		Floor(size_t size, vec3 pos = vec3(0, 0, 0));
		~Floor() = default;
		void insertInScene(const Eo::IScene *scene) override;
		void removeFromScene(const Eo::IScene *scene) override;
		void updateInScene(const Eo::IScene *scene) override;

	private:
		size_t _size;
	};
}

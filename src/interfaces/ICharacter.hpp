/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#pragma once

#include "AObject.hpp"
#include <string>

namespace Eo {
	class ICharacter {
	public:
		virtual ~ICharacter() = default;
		virtual void loadModel(const std::string &path) = 0;
		virtual irr::scene::IAnimatedMesh *getModel() const = 0;

	private:
	};
}

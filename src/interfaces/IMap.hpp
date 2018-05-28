/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#pragma once

#include "IObject.hpp"
#include <vector>

namespace Eo {
	class IMap {
	public:
		virtual ~IMap() = default;
		virtual Eo::IObject *getObject(size_t x, size_t y) = 0;
		virtual Eo::IObject *putObject(
			Eo::IObject *object, size_t x, size_t y) = 0;
		virtual std::vector<Eo::IObject *> &getObjects() = 0;

	private:
	};
}

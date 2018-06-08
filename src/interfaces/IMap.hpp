/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#pragma once

#include "IObject.hpp"
#include "Types.hpp"
#include <vector>

namespace Eo {
	class IMap {
	public:
		virtual ~IMap() = default;
		virtual Eo::Rc<Eo::IObject> getObject(
			Eo::u32 x, Eo::u32 y) = 0;
		virtual Eo::Rc<Eo::IObject> putObject(
			const Eo::Rc<Eo::IObject> &object, Eo::u32 x,
			Eo::u32 y) = 0;
		virtual Eo::Rc<Eo::IObject> putObject(
			Eo::IObject *object, Eo::u32 x, Eo::u32 y) = 0;
		virtual std::vector<Eo::Rc<Eo::IObject>> &getObjects() = 0;
		virtual bool update(Eo::Rc<Eo::IScene> scene) = 0;

	private:
	};
}

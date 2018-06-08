/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#pragma once

#include "JsonRead.hpp"
#include "interfaces/IMap.hpp"
#include <string>

namespace Eo {
	class Map : public IMap {
	public:
		Map(Eo::u32 w, Eo::u32 h);
		Map(Eo::JsonRead &);
		~Map() = default;
		Eo::u32 getWidth() const;
		Eo::u32 getHeight() const;
		Eo::Rc<Eo::IObject> getObject(Eo::u32 x, Eo::u32 y) override;
		Eo::Rc<Eo::IObject> putObject(
			const Eo::Rc<Eo::IObject> &object, Eo::u32 x,
			Eo::u32 y) override;
		Eo::Rc<Eo::IObject> putObject(
			Eo::IObject *object, Eo::u32 x, Eo::u32 y);
		std::vector<Eo::Rc<Eo::IObject>> &getObjects() override;
		void generateMap(const std::string &mapPath);
		bool update() override;

	private:
		Eo::u32 _w;
		Eo::u32 _h;
		std::vector<Eo::Rc<Eo::IObject>> _map;
	};
}

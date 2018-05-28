/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#pragma once

#include <string>
#include "JsonRead.hpp"
#include "interfaces/IMap.hpp"

namespace Eo {
	class Map : public IMap {
	public:
		Map(size_t w, size_t h);
		Map(Eo::JsonRead &);
		~Map() = default;
		size_t getWidth() const;
		size_t getHeight() const;
		Eo::IObject *getObject(size_t x, size_t y) override;
		Eo::IObject *putObject(
			Eo::IObject *object, size_t x, size_t y) override;
		std::vector<Eo::IObject *> &getObjects() override;
		void generateMap(const std::string &mapPath);

	private:
		size_t _w;
		size_t _h;
		std::vector<Eo::IObject *> _map;
	};
}

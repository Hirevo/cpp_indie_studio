/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#pragma once

#include "interfaces/IMap.hpp"

namespace Eo {
	class Map : public IMap {
	public:
		Map(size_t w, size_t h);
		~Map() = default;
		Eo::IObject *getObject(size_t x, size_t y) override;
		Eo::IObject *putObject(
			Eo::IObject *object, size_t x, size_t y) override;
		std::vector<Eo::IObject *> &getObjects() override;

	private:
		size_t _w;
		size_t _h;
		std::vector<Eo::IObject *> _map;
		void generateMap(const std::string &mapPath);
	};
}

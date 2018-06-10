//
// EPITECH PROJECT, 2018
// IndieStudio
// File description:
// JsonRead
//

#include <iostream>
#include "JsonRead.hpp"
#include "Map.hpp"

const std::vector<std::vector<Eo::f32>> Eo::JsonRead::_defaultPlayerPos = {
	{1, 1, 1},
	{static_cast<Eo::f32>(Eo::Map::_defaultSize.first) - 2,
		static_cast<Eo::f32>(Eo::Map::_defaultSize.second) - 2, 1},
	{1, static_cast<Eo::f32>(Eo::Map::_defaultSize.second) - 2, 1},
	{static_cast<Eo::f32>(Eo::Map::_defaultSize.first) - 2, 1, 1}
};

Eo::JsonRead::JsonRead(std::string const &filename)
{
	std::ifstream file(filename);
	_good = file.good();
	if (_good)
		boost::property_tree::read_json(filename, this->_root);
}

Eo::JsonRead::~JsonRead()
{
}

bool Eo::JsonRead::good()
{
	return _good;
}

std::string Eo::JsonRead::readSingleValue(std::string const &name) const
{
	return this->_root.get<std::string>(name);
}

std::vector<std::vector<Eo::i32>> Eo::JsonRead::readMatrix(
	std::string const &name)
{
	std::vector<std::vector<Eo::i32>> matrix;
	int x = 0;

	for (auto &row : this->_root.get_child(name)) {
		int y = 0;

		matrix.emplace_back();
		for (auto &cell : row.second) {
			matrix.at(x).emplace_back(static_cast<Eo::i32>(
				cell.second.get_value<int>()));
			y++;
		}
		x++;
	}
	return matrix;
}



std::vector<std::vector<Eo::f32>> Eo::JsonRead::readPlayersPos(std::string
const &name)
{
	std::vector<std::vector<Eo::f32>> matrix;
	int x = 0;

	if (!this->good()) {
		matrix = this->_defaultPlayerPos;
		return matrix;
	}
	for (auto &row : this->_root.get_child(name)) {
		int y = 0;

		matrix.emplace_back();
		for (auto &cell : row.second) {
			matrix.at(x).emplace_back(static_cast<Eo::f32>(
				cell.second.get_value<float>()));
			y++;
		}
		x++;
	}
	return matrix;
}
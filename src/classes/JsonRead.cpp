//
// EPITECH PROJECT, 2018
// IndieStudio
// File description:
// JsonRead
//

#include <iostream>
#include "JsonRead.hpp"

Eo::JsonRead::JsonRead(std::string const &filename)
{
	boost::property_tree::read_json(filename, this->_root);
}

Eo::JsonRead::~JsonRead()
{
}

std::string Eo::JsonRead::readSingleValue(std::string const &name) const
{
	return this->_root.get<std::string>(name);
}

std::vector<std::vector<Eo::MapWall>> Eo::JsonRead::readMatrix(
	std::string const &name)
{
	std::vector<std::vector<Eo::MapWall>> matrix;
	int x = 0;

	for (auto &row : this->_root.get_child(name)) {
		int y = 0;

		matrix.emplace_back();
		for (auto &cell : row.second) {
			matrix.at(x).emplace_back(static_cast<Eo::MapWall>(
				cell.second.get_value<int>()));
			y++;
		}
		x++;
	}
	return matrix;
}

std::vector<std::vector<float>> Eo::JsonRead::readPlayersPos(std::string const &name)
{
	std::vector<std::vector<float>> matrix;
	int x = 0;

	for (auto &row : this->_root.get_child(name)) {
		int y = 0;

		matrix.emplace_back();
		for (auto &cell : row.second) {
			matrix.at(x).emplace_back(static_cast<float>(
				cell.second.get_value<float>()));
			y++;
		}
		x++;
	}
	return matrix;
}
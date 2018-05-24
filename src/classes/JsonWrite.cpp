//
// EPITECH PROJECT, 2018
// IndieStudio
// File description:
// JsonWrite
//

#include "JsonWrite.hpp"

Eo::JsonWrite::JsonWrite()
{
}

Eo::JsonWrite::~JsonWrite()
{
}

void Eo::JsonWrite::writeSingleValue(std::string const &name,
				     std::string const &value)
{
	this->_root.put(name, value);
}

void Eo::JsonWrite::writeMatrix(std::string const &name,
				std::vector<std::vector<Eo::MapWall>>
				const &value)
{
	boost::property_tree::ptree matrix_node;

	for (int i = 0; i < value.size(); i++) {
		boost::property_tree::ptree row;

		for (int j = 0; j < value.at(i).size(); j++) {
			boost::property_tree::ptree cell;

			cell.put_value(value.at(i).at(j));
			row.push_back(std::make_pair("", cell));
		}
		matrix_node.push_back(std::make_pair("", row));
	}
	this->_root.add_child(name, matrix_node);
}

void Eo::JsonWrite::generateJson(std::string const &filename)
{
	std::ofstream file(filename, std::ios::out);

	if (file) {
		boost::property_tree::write_json(file, this->_root);
	}
}

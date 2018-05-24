//
// EPITECH PROJECT, 2018
// IndieStudio
// File description:
// JsonWrite
//

#ifndef JSONWRITE_HPP
#define JSONWRITE_HPP

#include "MapWall.hpp"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <string>
#include <fstream>
#include <vector>

namespace Eo
{
	class JsonWrite
	{
	public:
		JsonWrite();
		~JsonWrite();
		void writeSingleValue(std::string const &name,
				      std::string const &value);
		void writeMatrix(std::string const &name,
				 std::vector<std::vector<Eo::MapWall>>
				 const &value);
		void generateJson(std::string const &filename);

	private:
		boost::property_tree::ptree _root;
	};
}

#endif

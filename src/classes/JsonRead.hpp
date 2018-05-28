//
// EPITECH PROJECT, 2018
// IndieStudio
// File description:
// JsonRead
//

#ifndef JSONREAD_HPP
#define JSONREAD_HPP

#include "MapWall.hpp"
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <string>
#include <vector>

namespace Eo {
	class JsonRead {
	public:
		JsonRead(std::string const &filename);
		~JsonRead();
		std::string readSingleValue(std::string const &name) const;
		std::vector<std::vector<Eo::MapWall>> readMatrix(
			std::string const &name);

	private:
		boost::property_tree::ptree _root;
	};
}

#endif

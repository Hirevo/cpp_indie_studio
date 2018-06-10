//
// EPITECH PROJECT, 2018
// IndieStudio
// File description:
// JsonRead
//

#ifndef JSONREAD_HPP
#define JSONREAD_HPP

#include "Types.hpp"
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <string>
#include <vector>

namespace Eo {
	class JsonRead {
	public:
		JsonRead(std::string const &filename);
		~JsonRead();
		bool good();
		std::string readSingleValue(std::string const &name) const;
		std::vector<std::vector<Eo::i32>> readMatrix(std::string const &name);
		std::vector<std::vector<Eo::f32>> readPlayersPos(std::string const &);

	private:
		boost::property_tree::ptree _root;
		bool _good;
		static const std::vector<std::vector<Eo::f32>> _defaultPlayerPos;
	};
}

#endif

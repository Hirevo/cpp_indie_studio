/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Booster.hpp
*/

#ifndef BOMBERMAN_BOOSTER_HPP
#define BOMBERMAN_BOOSTER_HPP

#include <unordered_map>
#include "AObject.hpp"

namespace Eo {
	class Booster : public AObject {
	public:
		enum BoosterType {SPEED, SUPERBOMB, NBBOMB, NONE};
		Booster(Booster::BoosterType type, vec3 pos = vec3(0, 0, 0));
		~Booster() = default;
		void insertInScene(const Eo::IScene *scene) override;
		void removeFromScene(const Eo::IScene *scene) override;
		void updateInScene(const Eo::IScene *scene) override;
		BoosterType getBoosterType() const;
	private:
		BoosterType _boosterType;
	private:
		static const std::unordered_map<BoosterType, std::string>
			_textures;
		static const std::unordered_map<BoosterType, std::string>
			_mesh;
	};
}


#endif /* !BOMBERMAN_BOOSTER_HPP */

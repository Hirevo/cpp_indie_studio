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

#define NB_BOOSTERS 4

namespace Eo {
	class Booster : public AObject {
	public:
		enum BoosterType : Eo::u8 {NONE =
			Eo::IObject::Type::BOOSTER_NONE, SPEED, SUPERBOMB,
			NBBOMB, WALLPASS};
		Booster(Booster::BoosterType type, vec3 pos = vec3(0, 0, 0));
		~Booster() = default;
		void insertInScene(const Eo::Rc<Eo::IScene> scene) override;
		void removeFromScene() override;
		void updateInScene() override;
		BoosterType getBoosterType() const;
	private:
		BoosterType _boosterType;
		std::unordered_map<BoosterType, std::string>
			_textures;
		std::unordered_map<BoosterType, std::string>
			_mesh;
	};
}


#endif /* !BOMBERMAN_BOOSTER_HPP */

/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Booster.hpp
*/

#ifndef BOMBERMAN_BOOSTER_HPP
#define BOMBERMAN_BOOSTER_HPP

#include "AObject.hpp"

namespace Eo {
	class Booster : public AObject {
	public:
		enum BoosterType {ROLLER, SUPERBOMB, NBBOMB};
		Booster(Booster::BoosterType type, vec3 pos = vec3(0, 0, 0));
		~Booster() = default;
		void insertInScene(const Eo::IScene *scene) override;
		void removeFromScene(const Eo::IScene *scene) override;
		void updateInScene(const Eo::IScene *scene) override;

	private:
		BoosterType _boosterType;
	};
}


#endif /* !BOMBERMAN_BOOSTER_HPP */

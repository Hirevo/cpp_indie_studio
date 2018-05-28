/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Created by Benjamin
*/

#ifndef BOMBERMAN_ABOMB_HPP
#define BOMBERMAN_ABOMB_HPP

#include "IObject.hpp"

namespace Eo {
	class ABomb : public IObject {
	public:
		ABomb();
		~ABomb() = default;
		Eo::IObject::Type getType() const override;
		irr::scene::IMeshSceneNode *getSceneNode() override;
		void setSceneNode(irr::scene::IMeshSceneNode *node) override;

	private:
		
	};
}

#endif

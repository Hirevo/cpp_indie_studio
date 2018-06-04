/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** CreditsMenu.hpp
*/

#ifndef BOMBERMAN_CREDITSMENU_HPP
	#define BOMBERMAN_CREDITSMENU_HPP

	#include <AScene.hpp>

namespace Eo {
	class CreditsMenu : public Eo::AScene {
	public:
		CreditsMenu(Eo::Device &_device);
		~CreditsMenu();
		bool draw() override;

		enum ButtonType {
			Return
		};
	private:
		void putBackgroundImage();
		void putReturnButton();
	};
}


#endif //BOMBERMAN_CREDITSMENU_HPP

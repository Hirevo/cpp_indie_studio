/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** SettingsMenu.hpp
*/

#ifndef BOMBERMAN_SETTINGSMENU_HPP
	#define BOMBERMAN_SETTINGSMENU_HPP

	#include <AScene.hpp>

namespace Eo {
	class SettingsMenu : public Eo::AScene {
	public:
		SettingsMenu(Eo::Device &_device);
		~SettingsMenu();
		bool draw() override;

		enum ButtonType {
			Return
		};
	private:
		void putBackgroundImage();
		void putReturnButton();
	};
}

#endif //BOMBERMAN_SETTINGSMENU_HPP

/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** MainMenu.hpp
*/

#pragma once

#include "AScene.hpp"

namespace Eo {
	class MainMenu : public AScene {
	public:
		MainMenu(Eo::Device &_device);
		~MainMenu() override;

		enum ButtonType {
			GUI_ID_MAIN_PLAY_BUTTON = 1900,
			GUI_ID_MAIN_SETTINGS_BUTTON,
			GUI_ID_MAIN_EXIT_BUTTON
		};

	private:
		void putPlayButton();
		void putSettingsButton();
		void putExitButton();
	};
}

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
		bool draw() override;

		enum ButtonType { Play = 1900, Settings, Exit };

	private:
		void putPlayButton();
		void putSettingsButton();
		void putExitButton();
		void putBackgroundImage();
		void putTitle();
	};
}

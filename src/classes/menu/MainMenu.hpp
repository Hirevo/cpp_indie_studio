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
		MainMenu(Eo::Event &event, Eo::Device &device);
		~MainMenu() override;
		bool draw() override;

		enum ButtonType { Play = 1900, PlayGamePlayer, PlayGamePlayers, Settings, Credits, Exit };

	private:
		void putPlayButton();
		void putSettingsButton();
		void putCreditsButton();
		void putExitButton();
		void putBackgroundImage();
		void putTitle();
	};
}

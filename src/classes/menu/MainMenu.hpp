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
		explicit MainMenu(Eo::Device &_device);
		~MainMenu() override;

		enum {
			GUI_ID_QUIT_BUTTON = 101,
			GUI_ID_NEW_WINDOW_BUTTON,
			GUI_ID_FILE_OPEN_BUTTON,
			GUI_ID_TRANSPARENCY_SCROLL_BAR
		};

	private:
	};
}

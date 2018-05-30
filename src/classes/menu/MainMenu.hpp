/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** MainMenu.hpp
*/

#ifndef BOMBERMAN_MAINMENU_HPP
	#define BOMBERMAN_MAINMENU_HPP

	#include "AMenu.hpp"

namespace Eo {
	class MainMenu : public AMenu {
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


#endif //BOMBERMAN_MAINMENU_HPP

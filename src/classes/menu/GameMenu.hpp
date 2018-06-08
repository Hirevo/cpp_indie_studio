/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** GameMenu.hpp
*/

#ifndef BOMBERMAN_GAMEMENU_HPP
	#define BOMBERMAN_GAMEMENU_HPP

	#include "AScene.hpp"

namespace Eo {
	class GameMenu : public AScene {
	public:
		GameMenu(Eo::Rc<Eo::Event> &event, Eo::Rc<Eo::Device> &device);
		~GameMenu() override;
		bool draw() override;

		enum ButtonType { Resume = 150, Settings, Quit };

	private:
		void putBackgroundImage();
		void putResumeButton();
		void putQuitButton();
		void putSaveButton();
	};
}

#endif //BOMBERMAN_GAMEMENU_HPP

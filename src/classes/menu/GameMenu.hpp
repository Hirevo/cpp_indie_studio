/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** GameMenu.hpp
*/

#pragma once

#include "AScene.hpp"

namespace Eo {
	class GameMenu : public AScene {
	public:
		GameMenu(Eo::Rc<Eo::Event> event, Eo::Rc<Eo::Device> device, Eo::Rc<Eo::SceneHandler> sceneHandler);
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

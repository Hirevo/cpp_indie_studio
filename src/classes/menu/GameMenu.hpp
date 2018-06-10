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
		GameMenu(Eo::Rc<Eo::Event> event, Eo::Rc<Eo::Device> device, Eo::Rc<Eo::SceneHandler> sceneHandler, Eo::Rc<Eo::SoundDevice> sound);
		~GameMenu() override;
		bool draw() override;
		enum EventType { Resume = 167, Settings, Quit, Save };

	private:
		void putBackgroundImage();
		void putResumeButton();
		void putQuitButton();
		void putSettingsMenu();
		void addEvents(Eo::Rc<Eo::Event> event);
	};
}

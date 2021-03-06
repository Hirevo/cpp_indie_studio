/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** MainMenu.hpp
*/

#pragma once

#include "SoundDevice.hpp"
#include "AScene.hpp"
#include "Types.hpp"

namespace Eo {
	class MainMenu : public AScene {
	public:
		MainMenu(Eo::Rc<Eo::Event> event, Eo::Rc<Eo::Device> device, Eo::Rc<Eo::SceneHandler> sceneHandler, Eo::Rc<Eo::SoundDevice> sound);
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
		void addEvents(Eo::Rc<Eo::Event> event);
	};
}

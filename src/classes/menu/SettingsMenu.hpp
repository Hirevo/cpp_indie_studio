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
		SettingsMenu(Eo::Rc<Eo::Event> event, Eo::Rc<Eo::Device> device, Eo::Rc<Eo::SceneHandler> sceneHandler, Eo::Rc<Eo::SoundDevice> sound);
		~SettingsMenu();
		bool draw() override;

		enum ButtonType {
			Return = 120,
			SoundMore,
			SoundLess,
			SoundMoreMus,
			SoundLessMus,
			SoundMoreEffect,
			SoundLessEffect
		};
	private:
		void putSetVolumeSound();
		void putBackgroundImage();
		void putReturnButton();
		void putSetVolumeSoundMus();
		void putSetVolumeSoundEffect();
		void addEvents(Eo::Rc<Eo::Event> event);
	};
}

#endif //BOMBERMAN_SETTINGSMENU_HPP

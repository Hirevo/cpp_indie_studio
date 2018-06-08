/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** PlayMenu.hpp
*/

#ifndef BOMBERMAN_PLAYMENU_HPP
#define BOMBERMAN_PLAYMENU_HPP

#include <AScene.hpp>

namespace Eo {
	class PlayMenu : public Eo::AScene {
	public:
		PlayMenu(Eo::Event &event, Eo::Device &device);
		~PlayMenu();
		bool draw() override;

		enum ButtonType {
			Return = 120
		};
	private:
		void putPlayButton();
		void putPlayButtonSecond();
		void putBackgroundImage();
		void putReturnButton();
		void putTitle();
	};
}


#endif /* !BOMBERMAN_PLAYMENU_HPP */

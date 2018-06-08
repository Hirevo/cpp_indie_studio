//
// EPITECH Project, 2018
// bomberman
// File description:
// SoundDevice.hpp
//

#pragma once

#include <irrKlang.h>
#include <string>
#include <unordered_map>

namespace Eo {
	class SoundDevice {
	public:
		enum SoundPath {
			NONE,
			MENUBGM,
			GAMEBGM,
			PAUSE,
			CONFIRM,
			RESET,
			SELECT,
			BOMBS,
			BOMBM,
			BOMBL,
			PLAY,
			SETBOMB,
			DEATH,
			GETITEM,
			HURRY
		};
		SoundDevice();
		~SoundDevice();
		void play(const std::string &path, bool loop = false);
		// Get Sound volume in percentage.
		int getVolume() const;
		// Set Sound Volume in percentage.
		void setVolume(const int volume);
		void stop();
		static const std::unordered_map<SoundPath, std::string> _soundPath;
	private:
		irrklang::ISoundEngine *_device;
	};
}



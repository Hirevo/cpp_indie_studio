//
// EPITECH Project, 2018
// bomberman
// File description:
// SoundDevice.hpp
//

#pragma once

#include <irrKlang.h>
#include <string>

namespace Eo {
	class SoundDevice {
	public:
		SoundDevice();
		~SoundDevice();
		void play(const std::string &path, bool loop = false);
		// Get Sound volume in percentage.
		int getVolume() const;
		// Set Sound Volume in percentage.
		void setVolume(const int volume);
	private:
		irrklang::ISoundEngine *_device;
	};
}



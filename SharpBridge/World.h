#pragma once

#include "apiWorld.h"

namespace SharpBridge {
	public ref class World
	{
	private:
		apiWorld::virtualWorld* world;

	public:
		void setWeather(unsigned int weather);
		void setTime(unsigned int hour, unsigned int minutes);
		void setMinuteDuration(unsigned int duration);
		void streamWorldChanges();

		void getTime(unsigned int^ hour, unsigned int^ minutes);
		unsigned int getWeather();
		unsigned int getMinuteDuration();
	};
}


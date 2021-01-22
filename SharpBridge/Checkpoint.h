#pragma once

#include "Math.h"

using namespace System;

namespace SharpBridge {
	public ref class Checkpoint 
	{
	private:
		int id;

	public:
		Checkpoint(int id);

		Vector3^ getPos();
		float getRadius();
		int getType();
		unsigned int getWorld();
		unsigned int getColor();
		int getBlip();

		void setStreamDistance(float d);
		float getStreamDistance();
	};
}
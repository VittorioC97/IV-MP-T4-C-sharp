#pragma once

#include "Math.h"

using namespace System;

namespace SharpBridge {
	public ref class Blip
	{
	private:
		int id;

	public:
		Blip(int id);

		void setName(System::String^ name);
		int getId();
	};
}

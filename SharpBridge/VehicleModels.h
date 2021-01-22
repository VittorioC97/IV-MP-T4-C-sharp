#pragma once

using namespace System;

namespace SharpBridge
{
	public ref class VehicleModels abstract sealed
	{
	public:
		static bool isValidModel(int id);
		static int getModelByName(String^ carName);
		static String^ getModelName(int id);
	};
}


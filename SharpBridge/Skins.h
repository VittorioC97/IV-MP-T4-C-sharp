#pragma once

using namespace System;

namespace SharpBridge{
	public ref class Skins abstract sealed
	{
	public:
		static bool isValidModel(int id);
		static unsigned long getModel(int id);
		static int getIdByName(String^ carName);
		static int getIdByHash(unsigned int hash);
		static String^ getModelName(int id);
	};
}
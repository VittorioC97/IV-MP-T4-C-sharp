#pragma once

#include "ServerEvents.h"

using namespace System;
using namespace System::Collections::Generic;

namespace SharpBridge {
	public ref class bridgeServer abstract sealed
	{
	private:
		static int pulseRate;
		static int running;

	public:
		static void startIVMPServer(int port, String^ serverName, String^ serverLocation, String^ serverSite, bool masterList, bool gtaIV);

		static void controlServerNow();
		static void registerModuleEvents(String^ id, ServerEvents^ e);
	};
}

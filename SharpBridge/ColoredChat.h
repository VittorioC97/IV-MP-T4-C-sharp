#pragma once
#include "apiColoredChat.h"

namespace SharpBridge {
	public ref class Chat abstract sealed
	{
	public:
		static void createMultiColored(int id);
		static void disposeMultiColored(int id);
		static bool isValidMultiColored(int id);

		static void addMsg(int id, System::String^ msg, unsigned int ARGB);

		static void sendMsgToAll(System::String^ msg, unsigned int ARGB);
		static void sendColoredMsgToAll(int msgId);
	};
}

#include <msclr/marshal.h>
#include "apiPlayer.h"
#include "ColoredChat.h"

void SharpBridge::Chat::createMultiColored(int id)
{
	apiColoredChat::create(id);
}

void SharpBridge::Chat::disposeMultiColored(int id)
{
	apiColoredChat::dispose(id);
}

bool SharpBridge::Chat::isValidMultiColored(int id)
{
	return apiColoredChat::isValid(id);
}

void SharpBridge::Chat::addMsg(int id, System::String^ msg, unsigned int ARGB)
{
	msclr::interop::marshal_context ctx;
	const char* converted = ctx.marshal_as<const char*>(msg);
	apiColoredChat::addMsg(id, converted, ARGB);
}

void SharpBridge::Chat::sendMsgToAll(System::String^ msg, unsigned int ARGB)
{
	msclr::interop::marshal_context ctx;
	const char* converted = ctx.marshal_as<const char*>(msg);
	apiPlayer::sendMsgToAll(converted, ARGB);
}

void SharpBridge::Chat::sendColoredMsgToAll(int msgId)
{
	apiPlayer::sendColoredMsgToAll(msgId);
}
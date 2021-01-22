#include <msclr/marshal.h>
#include "playerList.h"
#include "Skins.h"


bool SharpBridge::Skins::isValidModel(int i)
{
	return playerList::isValidModel(i);
}

unsigned long SharpBridge::Skins::getModel(int i)
{
	return playerList::getModel(i);
}

int SharpBridge::Skins::getIdByName(String^ carName)
{
	msclr::interop::marshal_context ctx;
	const char* converted = ctx.marshal_as<const char*>(carName);

	return playerList::getIdByName(converted);
}

int SharpBridge::Skins::getIdByHash(unsigned int hash)
{
	return playerList::getIdByHash(hash);
}

String^ SharpBridge::Skins::getModelName(int i)
{
	return gcnew String(playerList::getModelName(i));
}
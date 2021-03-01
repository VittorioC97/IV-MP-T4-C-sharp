#include <msclr/marshal.h>
#include "BridgeEvents.h"
#include "ServerEvents.h"
#include "apiPlayerEvents.h"
#include "apiPlayerInputs.h"
#include "apiVehicleEvents.h"

bool onPlayerConnect(int playerid)
{
	try
	{
		for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents)
		{
			if(!i.Value->onPlayerConnect(playerid)) return false;
		}
	}
	catch(std::exception&){}
	return true;
}

bool onPlayerCredentials(int playerid)
{
	try
	{
		for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents)
		{
			if(!i.Value->onPlayerCredentials(playerid)) return false;
		}
	}
	catch(std::exception&){}
	return true;
}

void onPlayerDisconnect(int playerid, int reason)
{
	try
	{
		for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents) i.Value->onPlayerDisconnect(playerid, reason);
	}
	catch(std::exception&){}
}

void onPlayerAfk(int playerid, bool status)
{
	try
	{
		for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents) i.Value->onPlayerAfk(playerid, status);
	}
	catch(std::exception&){}
}

bool onPlayerTeamSpeak(int playerid, int status, int channel)
{
	try
	{
		for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents)
		{
			if(!i.Value->onPlayerTeamSpeak(playerid, status, channel)) return false;
		}
	}
	catch(std::exception&){}
	return true;
}

void onPlayerChat(int playerid, const char* txt)
{
	try
	{
		String^ s = gcnew String(txt);
		if(txt[0] == '/')
		{
			for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents) i.Value->onPlayerCommand(playerid, s);
		}
		else
		{
			for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents) i.Value->onPlayerChat(playerid, s);
		}
	}
	catch(std::exception&){}
}

void onPlayerDeath(int playerid, int agentType, int agentId)
{
	try
	{
		for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents)
		{
			i.Value->onPlayerDeath(playerid, agentType, agentId);
		}
	}
	catch(std::exception&){}
}

void onPlayerHealthChange(int playerid, int agentType, int agentId, int boneId)
{
	try
	{
		for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents)
		{
			i.Value->onPlayerHealthChange(playerid, agentType, agentId, boneId);
		}
	}
	catch(std::exception&){}
	}

void onPlayerArmorChange(int playerid, int agentType, int agentId, int boneId)
{
	try
	{
		for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents)
		{
			i.Value->onPlayerArmorChange(playerid, agentType, agentId, boneId);
		}
	}
	catch(std::exception&){}
}

void onPlayerEnteringVehicle(int playerid, int vehicleId, int seatId, bool carjack)
{
	try
	{
		for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents)
		{
			i.Value->onPlayerEnteringVehicle(playerid, vehicleId, seatId, carjack);
		}
	}
	catch(std::exception&){}
}

void onPlayerEnteredVehicle(int playerid, int vehicleId, int seatId)
{
	try
	{
		for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents)
		{
			i.Value->onPlayerEnteredVehicle(playerid, vehicleId, seatId);
		}
	}
	catch(std::exception&){}
}

void onPlayerExitVehicle(int playerid, int vehicleId, int seatId)
{
	try
	{
	for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents)
	{
		i.Value->onPlayerExitVehicle(playerid, vehicleId, seatId);
	}
	}
	catch(std::exception&){}
}

bool onPlayerWeaponChange(int playerid, int weapon, int ammo)
{
	try
	{
		for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents)
		{
			if(!i.Value->onPlayerWeaponChange(playerid, weapon, ammo)) return false;
		}
	}
	catch(std::exception&){}
	return true;
}

bool onPlayerWeaponsArrive(int playerid)
{
	try
	{
		for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents)
		{
			if(!i.Value->onPlayerWeaponsArrive(playerid)) return false;
		}
	}
	catch(std::exception&){}
	return true;
}

void onPlayerEnterCheckpoint(int playerid, int checkPointId)
{
	try
	{
		for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents)
		{
			i.Value->onPlayerEnterCheckpoint(playerid, checkPointId);
		}
	}
	catch(std::exception&){}
}

void onPlayerExitCheckpoint(int playerid, int checkPointId)
{
	try
	{
		for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents)
		{
			i.Value->onPlayerExitCheckpoint(playerid, checkPointId);
		}
	}
	catch(std::exception&){}
}

bool onPlayerRespawn(int playerid)
{
	try
	{
		for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents)
		{
			if(!i.Value->onPlayerRespawn(playerid)) return false;
		}
	}
	catch(std::exception&){}
	return true;
}

void onPlayerSpawnEntity(int playerid, int agentType, int agentId, int boneId)
{
	try
	{
		for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents)
		{
			i.Value->onPlayerSpawnEntity(playerid, agentType, agentId, boneId);
		}
	}
	catch(std::exception&){}
}

void onPlayerDialogResponse(int playerid, unsigned int dialogId, int buttonId, int rowId, int customId)
{
	try
	{
		for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents)
		{
			i.Value->onPlayerDialogResponse(playerid, dialogId, buttonId, rowId, customId);
		}
	}
	catch(std::exception&){}
}

void onVehicleChangeHp(int vehicleId, int health)
{
	try
	{
		for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents) i.Value->onVehicleChangeHp(vehicleId, health);
	}
	catch(std::exception&){}
}

void onVehicleTyreBurst(int vehicleId, unsigned int tyre)
{
	try
	{
		for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents) i.Value->onVehicleTyreBurst(vehicleId, tyre);
	}
	catch(std::exception&){}
}

void onPlayerKey(apiPlayer::player& p, unsigned int virtualKey, bool keyUp)
{
	try
	{
		for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents)
		{
			i.Value->onPlayerKey(p.getID(), virtualKey, keyUp);
		}
	}
	catch(std::exception&){}
}

void BridgeEvents::initContainer()
{
	moduleEvents = gcnew Dictionary<String^, SharpBridge::ServerEvents^>();
	printf("Registering internal events\n");

	apiPlayerEvents::registerPlayerJoin(onPlayerConnect);
	apiPlayerEvents::registerPlayerCredentials(onPlayerCredentials);
	apiPlayerEvents::registerPlayerLeft(onPlayerDisconnect);
	apiPlayerEvents::registerPlayerAfk(onPlayerAfk);
	apiPlayerEvents::registerTeamSpeak(onPlayerTeamSpeak);
	apiPlayerEvents::registerPlayerChat(onPlayerChat);
	apiPlayerEvents::registerPlayerDeath(onPlayerDeath);
	apiPlayerEvents::registerPlayerHpChange(onPlayerHealthChange);
	apiPlayerEvents::registerPlayerArmor(onPlayerArmorChange);
	apiPlayerEvents::registerEnteringVehicle(onPlayerEnteringVehicle);
	apiPlayerEvents::registerEnteredVehicle(onPlayerEnteredVehicle);
	apiPlayerEvents::registerLeftVehicle(onPlayerExitVehicle);
	apiPlayerEvents::registerPlayerWeaponChanged(onPlayerWeaponChange);
	apiPlayerEvents::registerPlayerWeaponsArrived(onPlayerWeaponsArrive);
	apiPlayerEvents::registerPlayerEnterCP(onPlayerEnterCheckpoint);
	apiPlayerEvents::registerPlayerExitCP(onPlayerExitCheckpoint);
	apiPlayerEvents::registerPlayerRespawn(onPlayerRespawn);
	apiPlayerEvents::registerPlayerSpawnEntity(onPlayerSpawnEntity);
	apiPlayerEvents::registerPlayerDialogListResponse(onPlayerDialogResponse);
	apiVehicleEvents::registerHealthChange(onVehicleChangeHp);
	apiVehicleEvents::registerTyrePop(onVehicleTyreBurst);
	apiPlayerInputs::registerKeyInputs(onPlayerKey);
}

void BridgeEvents::addEventsClass(String^ id, SharpBridge::ServerEvents^ e)
{
	msclr::interop::marshal_context ctx;
	const char* converted = ctx.marshal_as<const char*>(id);

	printf("Adding events for module: %s\n", converted);
	moduleEvents->Add(id, e);
}
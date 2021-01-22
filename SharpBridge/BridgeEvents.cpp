#include <msclr/marshal.h>
#include "BridgeEvents.h"
#include "ServerEvents.h"
#include "apiPlayerEvents.h"
#include "apiPlayerInputs.h"
#include "apiVehicleEvents.h"

bool onPlayerConnect(int playerid)
{
	for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents)
	{
		if(!i.Value->onPlayerConnect(playerid)) return false;
	}
	return true;
}

bool onPlayerCredentials(int playerid)
{
	for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents)
	{
		if(!i.Value->onPlayerCredentials(playerid)) return false;
	}
	return true;
}

void onPlayerDisconnect(int playerid, int reason)
{
	for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents) i.Value->onPlayerDisconnect(playerid, reason);
}

void onPlayerAfk(int playerid, bool status)
{
	for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents) i.Value->onPlayerAfk(playerid, status);
}

bool onPlayerTeamSpeak(int playerid, int status, int channel)
{
	for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents)
	{
		if(!i.Value->onPlayerTeamSpeak(playerid, status, channel)) return false;
	}
	return true;
}

void onPlayerChat(int playerid, const char* txt)
{
	String^ s = gcnew String(txt);
	for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents) i.Value->onPlayerChat(playerid, s);
}

void onPlayerDeath(int playerid, int agentType, int agentId)
{
	for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents) i.Value->onPlayerDeath(playerid, agentType, agentId);
}

void onPlayerHealthChange(int playerid, int agentType, int agentId, int boneId)
{
	for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents) {
		i.Value->onPlayerHealthChange(playerid, agentType, agentId, boneId);
	}
}

void onPlayerArmorChange(int playerid, int agentType, int agentId, int boneId)
{
	for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents) {
		i.Value->onPlayerArmorChange(playerid, agentType, agentId, boneId);
	}
}

void onPlayerEnteringVehicle(int playerid, int vehicleId, int seatId, bool carjack)
{
	for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents) {
		i.Value->onPlayerEnteringVehicle(playerid, vehicleId, seatId, carjack);
	}
}

void onPlayerEnteredVehicle(int playerid, int vehicleId, int seatId)
{
	for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents) {
		i.Value->onPlayerEnteredVehicle(playerid, vehicleId, seatId);
	}
}

void onPlayerExitVehicle(int playerid, int vehicleId, int seatId)
{
	for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents) {
		i.Value->onPlayerExitVehicle(playerid, vehicleId, seatId);
	}
}

bool onPlayerWeaponChange(int playerid, int weapon, int ammo)
{
	for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents)
	{
		if(!i.Value->onPlayerWeaponChange(playerid, weapon, ammo)) return false;
	}
	return true;
}

bool onPlayerWeaponsArrive(int playerid)
{
	for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents)
	{
		if(!i.Value->onPlayerWeaponsArrive(playerid)) return false;
	}
	return true;
}

void onPlayerEnterCheckpoint(int playerid, int checkPointId)
{
	for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents) {
		i.Value->onPlayerEnterCheckpoint(playerid, checkPointId);
	}
}

void onPlayerExitCheckpoint(int playerid, int checkPointId)
{
	for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents) {
		i.Value->onPlayerExitCheckpoint(playerid, checkPointId);
	}
}

bool onPlayerRespawn(int playerid)
{
	for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents)
	{
		if(!i.Value->onPlayerRespawn(playerid)) return false;
	}
	return true;
}

void onPlayerSpawnEntity(int playerid, int agentType, int agentId, int boneId)
{
	for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents) {
		i.Value->onPlayerSpawnEntity(playerid, agentType, agentId, boneId);
	}
}

void onPlayerDialogResponse(int playerid, unsigned int dialogId, int buttonId, int rowId, int customId)
{
	for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents) {
		i.Value->onPlayerDialogResponse(playerid, dialogId, buttonId, rowId, customId);
	}
}

void onVehicleChangeHp(int vehicleId, int health)
{
	for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents) i.Value->onVehicleChangeHp(vehicleId, health);
}

void onVehicleTyreBurst(int vehicleId, unsigned int tyre)
{
	for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents) i.Value->onVehicleTyreBurst(vehicleId, tyre);
}

void onPlayerKey(apiPlayer::player& p, unsigned int virtualKey, bool keyUp)
{
	for each(KeyValuePair<String^, SharpBridge::ServerEvents^> i in BridgeEvents::moduleEvents) i.Value->onPlayerKey(p.getID(), virtualKey, keyUp);
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
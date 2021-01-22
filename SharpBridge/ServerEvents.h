#include "SharpBridge.h"

#ifndef PLAYER_EVENTS_H
#define PLAYER_EVENTS_H

using namespace System;

namespace SharpBridge {

	public ref class ServerEvents {
	public:

		virtual bool onPlayerConnect(int playerid){return true;}
		virtual bool onPlayerCredentials(int playerid){return true;}
		virtual void onPlayerDisconnect(int playerid, int reason){}
		virtual void onPlayerAfk(int playerid, bool status){}
		virtual bool onPlayerTeamSpeak(int playerid, int status, int channel){ return true; }

		virtual void onPlayerChat(int playerid, String^ txt){}

		virtual void onPlayerDeath(int playerid, int agentType, int agentId){}
		virtual void onPlayerHealthChange(int playerid, int agentType, int agentId, int boneId){}
		virtual void onPlayerArmorChange(int playerid, int agentType, int agentId, int boneId){}

		virtual void onPlayerEnteringVehicle(int playerid, int vehicleId, int seatId, bool carjack){}
		virtual void onPlayerEnteredVehicle(int playerid, int vehicleId, int seatId){}
		virtual void onPlayerExitVehicle(int playerid, int vehicleId, int seatId){}

		virtual bool onPlayerWeaponChange(int playerid, int weapon, int ammo){ return true; }
		virtual bool onPlayerWeaponsArrive(int playerid){ return true; }

		virtual void onPlayerEnterCheckpoint(int playerid, int checkPointId){}
		virtual void onPlayerExitCheckpoint(int playerid, int checkPointId){}

		virtual bool onPlayerRespawn(int playerid){ return true; }
		virtual void onPlayerSpawnEntity(int playerid, int agentType, int agentId, int boneId){}

		virtual void onPlayerDialogResponse(int playerid, unsigned int dialogId, int buttonId, int rowId, int customId){}

		virtual void onVehicleChangeHp(int vehicleId, int health){}
		virtual void onVehicleTyreBurst(int vehicleId, unsigned int tyre){}

		virtual void onPlayerKey(int playerid, unsigned int virtualKey, bool keyUp){}
	};
}
#endif
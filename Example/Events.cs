using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using SharpBridge;

namespace Example
{
    class Events : SharpBridge.ServerEvents
    {
		override public bool onPlayerConnect(int playerid)
		{
			return Services.PlayerConnect.onPlayerConnect(playerid);
		}

		override public bool onPlayerCredentials(int playerid)
		{
			return Services.PlayerConnect.onPlayerCredentials(playerid);
		}

		override public void onPlayerDisconnect(int playerid, int reason)
		{
			Services.PlayerDisconnect.handleDisconnect(playerid, reason);
		}

		override public void onPlayerAfk(int playerid, bool status) { }
		override public bool onPlayerTeamSpeak(int playerid, int status, int channel) { return true; }

		override public void onPlayerChat(int playerid, string txt)
		{
			Player player = Entities.getPlayer(playerid);
			if (player == null) return;

			//Using multi colored chat msgs for the global chat
			//This will show the player name and id using then game color then append their text as white

			Chat.createMultiColored(1);
			uint rgba = player.getColor();
			uint argb = (rgba << 24) | (rgba >> 8);
			Chat.addMsg(1, player.getNick() + "(" + playerid + "):", argb);

			Chat.addMsg(1, " " + txt, 0xFFFFFFFF);

			Chat.sendColoredMsgToAll(1);
			Chat.disposeMultiColored(1);
		}

        public override void onPlayerCommand(int playerid, string txt)
        {
			Commands.CommandsProcessor.processCommand(playerid, ref txt);
        }

        override public void onPlayerDeath(int playerid, int agentType, int agentId) { }
		override public void onPlayerHealthChange(int playerid, int agentType, int agentId, int boneId) { }
		override public void onPlayerArmorChange(int playerid, int agentType, int agentId, int boneId) { }

		override public void onPlayerEnteringVehicle(int playerid, int vehicleId, int seatId, bool carjack) { }
		override public void onPlayerEnteredVehicle(int playerid, int vehicleId, int seatId) { }
		override public void onPlayerExitVehicle(int playerid, int vehicleId, int seatId) { }

		override public bool onPlayerWeaponChange(int playerid, int weapon, int ammo) { return true; }
		override public bool onPlayerWeaponsArrive(int playerid)
		{ 
			return Services.UpdateWeapons.onPlayerWeaponsArrive(playerid);
		}

		override public void onPlayerEnterCheckpoint(int playerid, int checkPointId) { }
		override public void onPlayerExitCheckpoint(int playerid, int checkPointId) { }

		override public bool onPlayerRespawn(int playerid) { return true; }
		override public void onPlayerSpawnEntity(int playerid, int agentType, int agentId, int boneId) { }

		override public void onPlayerDialogResponse(int playerid, uint dialogId, int buttonId, int rowId, int customId) { }

		override public void onVehicleChangeHp(int vehicleId, int health) { }
		override public void onVehicleTyreBurst(int vehicleId, uint tyre) { }

		override public void onPlayerKey(int playerid, uint key, bool keyUp) { }
	}
}

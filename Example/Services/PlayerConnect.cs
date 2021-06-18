using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using SharpBridge;

namespace Example.Services
{
    public static class PlayerConnect
    {
		static Vector3 spawnPos = new Vector3(1080.19f, 278.101f, 30.2316f);
		static Vector3 cameraPos = new Vector3(1080.19f, 278.101f, 35.2316f);
		static Vector3 cameraLookPos = new Vector3(1080.19f, 308.101f, 35.2316f);
		public static bool onPlayerConnect(int playerid)
		{
			Player player = Entities.getPlayer(playerid);
			if (player == null) return false;
			player.sendMsg("(1) Welcome online", 0xFF00FFFF);
			Chat.sendMsgToAll(player.getNick() + "(" + playerid + ") has joined the server", ChatColor.WHITE);
			return true;
		}
		public static bool onPlayerCredentials(int playerid)
		{
			Player player = Entities.getPlayer(playerid);
			if (player == null) return false;
			player.sendMsg("(2) Spawning", 0xFF00FFFF);
			player.spawn(spawnPos);
			player.setFrozen(true);

			//Add a timer to allow the player to spawn first and then set their camera position
			SharpBridge.Timer.TimerParams tParams = new SharpBridge.Timer.TimerParams();
			object buffer = playerid;
			tParams.@params.Add(buffer);
			SharpBridge.Timer.Manager.RegisterTimer(PositionCamera, 2000, 1, tParams);

			player.drawInfoText("Welcome " + player.getNick() + "~n~Use ~r~/register~w~ to create an account~n~Or ~b~/login~w~ to login", 500000);
			return true;
		}

		static void PositionCamera(SharpBridge.Timer.TimerParams param)
        {
			Player player = Entities.getPlayer((int)param.@params[0]);
			if(player != null)
            {
				player.cam_setPos(cameraPos, 0);
				player.cam_setLookAt(cameraLookPos);
            }
        }
	}
}

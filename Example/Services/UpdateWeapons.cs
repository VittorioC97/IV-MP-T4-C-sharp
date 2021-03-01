using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using SharpBridge;

namespace Example.Services
{
    static class UpdateWeapons
    {
        static void Run(SharpBridge.Timer.TimerParams param)
        {
            List<Player> players = Entities.getPlayers();
            foreach(Player player in players)
            {
                int pId = player.getID();
                if (!Game.AccountManager.IsOnline(pId)) continue;        
                player.requestWeapons();
            }
        }

        public static bool onPlayerWeaponsArrive(int playerid) 
        {
            Player player = Entities.getPlayer(playerid);
            if (player == null || !Game.AccountManager.IsOnline(playerid)) return true;

            Game.Account acc = Game.AccountManager.Get(playerid);
            uint size = player.getWeaponsSize();
            for (uint i = 0; i < size; i++)
            {
                int model = 0;
                int amount = 0;
                player.getWeaponData(i, ref model, ref amount);

                acc.updateWeapon((byte)model, (short)amount);
            }
            return true; 
        }

        public static void StartTimer()
        {
            SharpBridge.Timer.Manager.RegisterTimer(Run, 10000, 0, null);
        }
    }
}

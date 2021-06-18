using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using SharpBridge;

namespace Example.Services
{
    public static class PlayerDisconnect
    {
        public static void handleDisconnect(int playerid, int reason)
        {       
            if (!Game.AccountManager.IsOnline(playerid)) return;
            try
            {
                Game.Account user = Game.AccountManager.Get(playerid);

                Player player = Entities.getPlayer(playerid);
                if (player != null)
                {
                    user.updateHealth(player.getHealth(), player.getArmor());
                    user.updatePos(player.getPos());
                }

                user.save();
            }
            catch (Exception e) 
            {
                Console.WriteLine(e.ToString());
            }
            Game.AccountManager.Remove(playerid);
        }
    }
}

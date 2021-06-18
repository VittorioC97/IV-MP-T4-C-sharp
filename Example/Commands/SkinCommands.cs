using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Example.Commands
{
    public static class SkinCommands
    {
        public static void ChangeSkin(SharpBridge.Player player, object[] param)
        {
            uint id = (uint)param[0];
            if(id > 350)
            {
                player.sendMsg($"{id} is not a valid skin ID", ChatColor.ERROR);
                return;
            }
            player.setSkinId(id);
        }

        //Skins 1-2 have the most variations for this command
        public static void ChangeClothes(SharpBridge.Player player, object[] param)
        {
            uint id = (uint)param[0];
            if (id < 1 || id > 10)
            {
                player.sendMsg($"{id} is not a valid clothes part, use 1-10", ChatColor.ERROR);
                return;
            }

            uint variation = (uint)param[1];
            if (id < 1 || id > 100)
            {
                player.sendMsg($"{variation} is not a valid variation, use 1-100", ChatColor.ERROR);
                return;
            }
            player.setClothes(id - 1, variation - 1);
        }

        //Skins 1-2 have the most variations for this command
        public static void ChangeProperty(SharpBridge.Player player, object[] param)
        {
            uint id = (uint)param[0];
            if (id < 1 || id > 2)
            {
                player.sendMsg($"{id} is not a valid property, use 1-2", ChatColor.ERROR);
                return;
            }

            uint variation = (uint)param[1];
            if (id < 1 || id > 100)
            {
                player.sendMsg($"{variation} is not a valid variation, use 1-100", ChatColor.ERROR);
                return;
            }
            player.setProperty(id - 1, variation - 1);
        }

        public static void SaveSkin(SharpBridge.Player player, object[] param)
        {
            Game.AccountManager.Get(player.getID()).updateClothes(player);
            player.sendMsg("Saved!", ChatColor.SUCCESS);
        }
    }
}

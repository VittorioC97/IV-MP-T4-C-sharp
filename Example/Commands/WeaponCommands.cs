using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Example.Commands
{
    static class WeaponCommands
    {
        public static void Spawn(SharpBridge.Player player, object[] param)
        {
            uint weapon = (uint)param[0];
            if(weapon < 1 || weapon == 6|| weapon == 8 || weapon > 18)
            {
                player.sendMsg($"Weapon {weapon} is invalid. Use 1-5, 7, 9-18", ChatColor.ERROR);
                return;
            }

            player.giveWeapon(weapon, 2000);
        }

        public static void Disarm(SharpBridge.Player player, object[] param)
        {
            player.removeWeapon(0);
        }
    }
}

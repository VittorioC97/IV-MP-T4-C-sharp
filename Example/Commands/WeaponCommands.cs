using System;

namespace Example.Commands
{
    static class WeaponCommands
    {
        public static void Spawn(SharpBridge.Player player, object[] param)
        {
            uint weapon = (uint)param[0];
            if(weapon < 1 || weapon == 6 || weapon == 8 || weapon > 18)
            {
                player.sendMsg($"Weapon {weapon} is invalid. Use 1-5, 7, 9-18", ChatColor.ERROR);
                return;
            }

            Models.ItemTypesEF wClass = Game.ItemTypesManager.GetWeaponFromGameWeapon((byte)weapon);
            if(wClass == null)
            {
                player.sendMsg($"Not a database weapon", ChatColor.ERROR);
                return;
            }

            Game.Account acc = Game.AccountManager.Get(player.getID());
            acc.insertItem((short)weapon, 1, false);
            acc.insertItem(wClass.weapon.ammoItem, 200);

            Models.ItemEF bullets = acc.getItem(wClass.weapon.ammoItem);
            if (bullets == null) return; //Overkill almost
           
            player.giveWeapon(weapon, (uint)bullets.amount);
        }

        public static void Disarm(SharpBridge.Player player, object[] param)
        {
            player.removeWeapon(0);
        }
    }
}

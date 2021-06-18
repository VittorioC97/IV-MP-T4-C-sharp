using System;
using System.Collections.Generic;
using System.Linq;
using System.Data.Entity;
using SharpBridge;
using System.Data.SqlClient;
using System.Data.Entity.Infrastructure;
using Newtonsoft.Json;

namespace Example.Commands
{
    public static class AccoutCommands
    {
        public static void Register(SharpBridge.Player player, object[] param)
        {
            string pass = ((string)param[0]).ToLower();
            if(pass.Length < 3 || pass.Length > 22)
            {
                player.sendMsg("Your password must contain 3-22 characters", ChatColor.ERROR);
                return;
            }

            try
            {
                using (Repositories.UserRepository accs = new Repositories.UserRepository())
                {
                    Models.EntityEF uc = new Models.EntityEF
                    {
                        items = new List<Models.ItemEF>(),
                        user = new Models.UserEF
                        {
                            name = player.getNick(),
                            password = Services.Hashing.SHA2(ref pass),
                            clothes = "1",
                            hp = 100,
                            armor = 0,
                            moneyBank = 100
                        },
                        x = 1075.0f,
                        y = 278.0f,
                        z = 30.2f,
                        createDate = DateTime.Now
                    };
                    uc.user.entity = uc;

                    accs.entities.Add(uc);
                    accs.SaveChanges();

                    player.sendMsg($"Account created with pass '{pass}'. Use /login to proceed", ChatColor.SUCCESS);
                }
            }
            catch(DbUpdateException e)
            {
                if(e.ToString().Contains("Duplicate entry"))
                {
                    player.sendMsg($"Account '{player.getNick()}' already exists. Please use /login [password]", ChatColor.ERROR);
                    return;
                }
                Console.WriteLine(e.ToString());
            }
        }

        public static void Login(SharpBridge.Player player, object[] param)
        {
            try
            {
                string gameNick = player.getNick();
                if(Game.AccountManager.GetByName(ref gameNick) != null)
                {
                    player.sendMsg("This account is already being used", ChatColor.ERROR);
                    return;
                }

                string user = gameNick.ToLower();
                string pass = ((string)param[0]).ToLower();
                using (Repositories.UserRepository accs = new Repositories.UserRepository())
                {
                    Models.UserEF acc = accs.users.Where(i => i.name == user).
                        Include(i => i.entity).Include(i => i.entity.items).FirstOrDefault();

                    if(acc == null)
                    {
                        player.sendMsg($"Account '{player.getNick()}' doesn't exist", ChatColor.ERROR);
                        return;
                    }
                    else if(acc.password.ToLower() != Services.Hashing.SHA2(ref pass))
                    {
                        player.sendMsg("Wrong password", ChatColor.ERROR);
                        return;
                    }

                    Console.WriteLine(JsonConvert.SerializeObject(acc));

                    Game.Account playerAccount = new Game.Account(acc);
                    Game.AccountManager.Add(player.getID(), playerAccount);

                    playerAccount.setClothesFromString(player);
                    player.setPos(playerAccount.getPos());
                    player.setHealth(acc.hp);
                    player.setArmor(acc.armor);
                    player.setFrozen(false);
                    player.cam_setPos(null, 1);
                    player.cam_attachOnPlayer(-1);
                    player.setWorld(1);
                    player.drawInfoText("~g~Welcome back!", 5000);

                    List<short> givenAmmoTypes = new List<short>();
                    foreach(var item in acc.entity.items)
                    {
                        Models.ItemTypesEF typ = Game.ItemTypesManager.GetItemTypeByItem(item);
                        if (typ.weapon != null)
                        {
                            Console.WriteLine($"{item.type} is a weapon");
                            Models.ItemEF ammo = acc.entity.items.Where(j => j.type == typ.weapon.ammoItem).FirstOrDefault();
                            if (ammo == null || givenAmmoTypes.Count(j => j == ammo.type) != 0) continue;
                            Console.WriteLine("Ammo found");
                            givenAmmoTypes.Add(ammo.type);
                            player.giveWeapon((uint)item.type, (uint)ammo.amount);
                        }
                    }
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.Entity;
using SharpBridge;
using System.Data.SqlClient;
using System.Data.Entity.Infrastructure;
using System.Text.Json;
using System.Text.Json.Serialization;

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
                    Models.UserContainer uc = new Models.UserContainer
                    {
                        type = 0,
                        items = new List<Models.UserItem>(),
                        user = new List<Models.User>()
                    };
                    uc.user.Add(new Models.User
                    {
                        name = player.getNick(),
                        password = Services.Hashing.SHA2(ref pass),
                        container = uc,
                        clothes = "1",
                        x = 1075.0f,
                        y = 278.0f,
                        z = 30.2f,
                        hp = 100,
                        armor = 0,
                        moneyBank = 100
                    });
                    accs.containers.Add(uc);
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
                    Models.User acc = accs.users.Where(i => i.name == user).
                        Include(i => i.container).Include(i => i.container.items).FirstOrDefault();

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

                    Console.WriteLine(JsonSerializer.Serialize(acc));

                    Game.Account playerAccount = new Game.Account(acc);
                    Game.AccountManager.Add(player.getID(), playerAccount);

                    playerAccount.setClothesFromString(player);
                    player.setPos(playerAccount.getPos());
                    player.setHealth(acc.hp);
                    player.setArmor(acc.armor);
                    player.setFrozen(false);
                    player.cam_attachOnPlayer(-1);
                    player.drawInfoText("~g~Welcome back!", 5000);

                    foreach(Models.UserItem item in acc.container.items)
                    {
                        if(item.type > 0 && item.type < 19)
                        {
                            player.giveWeapon((uint)item.type, (uint)item.amount);
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

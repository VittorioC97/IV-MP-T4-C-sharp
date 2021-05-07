using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Example.Commands
{
    public static class CommandsProcessor
    {
        public static void processCommand(int playerid, ref string cmd)
        {
            SharpBridge.Player player = SharpBridge.Entities.getPlayer(playerid);
            if (player == null) return;

            string[] s = cmd.ToLower().Split(' ');
            if (!CommandsManager.commands.ContainsKey(s[0]))
            {
                player.sendMsg($"'{s[0]}' is an invalid command", ChatColor.ERROR);
                return;
            }

            Command command = CommandsManager.commands[s[0]];
            if(command.loggedIn != Game.AccountManager.IsOnline(playerid))
            {
                player.sendMsg(command.loggedIn ? "You must /login first" : "You are already logged in", ChatColor.ERROR);
                return;
            }

            if (command.args == null)
            {
                command.command(player, null); //No need to check
                return;
            }

            object[] obj = new object[command.args.Length];
            try
            {
                for (int i = 0; i < command.args.Length; i++)
                {
                    char c = command.args[i];
                    if (c == 's')
                    {
                        obj[i] = s[i + 1];
                    }
                    else if (c == 'i')
                    {
                        obj[i] = Int32.Parse(s[i + 1]);
                    }
                    else if (c == 'u')
                    {
                        obj[i] = UInt32.Parse(s[i + 1]);
                    }
                    else if (c == 'f')
                    {
                        obj[i] = float.Parse(s[i + 1]);
                    }
                }
                //Invoke command
            }
            catch (Exception)
            {
                //Command parsing failed, show usage
                player.sendMsg(command.usage, ChatColor.ERROR);
                return;
            }
            command.command(player, obj);
        }
    }
}

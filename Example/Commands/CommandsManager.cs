using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Example.Commands
{
    public delegate void CommandFunc(SharpBridge.Player player, object[] param);

    public class Command
    {
        public CommandFunc command;
        public string args;
        public string usage;
        public bool loggedIn;

        public Command(CommandFunc f, string a, string usage, bool loggedIn)
        {
            command = f;
            args = a;
            this.usage = usage;
            this.loggedIn = loggedIn;
        }
    }

    public static class CommandsManager
    {
        public static Dictionary<string, Command> commands = new Dictionary<string, Command>();

        public static void Add(string cmdName, CommandFunc func, string args, string usage, bool loggedIn = true)
        {
            commands.Add(cmdName, new Command(func, args, usage, loggedIn));
        }

        public static void Init()
        {
            Add("/skin", SkinCommands.ChangeSkin, "u", "Usage: /skin [0 - 350]");
            Add("/clothes", SkinCommands.ChangeClothes, "uu", "Usage: /clothes [part: 1-10] [variation: 1-100]");
            Add("/props", SkinCommands.ChangeProperty, "uu", "Usage: /props [part: 1-2] [variation: 1-100]");
            Add("/saveskin", SkinCommands.SaveSkin, null, null);

            Add("/register", AccoutCommands.Register, "s", "Usage: /register [password]", false);
            Add("/login", AccoutCommands.Login, "s", "Usage: /login [password]", false);

            Add("/weapon", WeaponCommands.Spawn, "u", "Usage: /weapon [model id]. Ids: 1-5, 7, 9-18");
            Add("/disarm", WeaponCommands.Disarm, null, null);

            Add("/boat", Boat.Spawn, null, null);
            Add("/gosouth", Boat.MoveSouth, null, null);

            Add("/v", VehicleCommands.Spawn, "s", "Usage: /v [model name]. Ex: /v Infernus");
            Add("/savevehicle", AdminVehicleCommands.Save, null, null);
        }
    }
}

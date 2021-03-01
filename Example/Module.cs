using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.Entity;
using System.Text.Json;
using System.Text.Json.Serialization;
using System.Dynamic;

namespace Example
{
    public class Module
    {
        private static Events events;

        public static void Run()
        {
            Console.Clear();
            Console.WriteLine("Alright Im running");
            events = new Events();
            SharpBridge.bridgeServer.registerModuleEvents("Example.dll", events);

            Commands.CommandsManager.Init();
            Services.UpdateWeapons.StartTimer();    
        }
    }
}
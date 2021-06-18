using System;

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

            Services.ServerBoot.LoadVehicles.Load();
            Services.ServerBoot.LoadItemTypes.LoadTypes();

            Commands.CommandsManager.Init();
            Services.UpdateWeapons.StartTimer();
        }
    }
}
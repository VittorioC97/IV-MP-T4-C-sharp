using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Example
{
    public class Module
    {
        private static Events events;
        public static void Run()
        {
            Console.WriteLine("Alright Im running");
            events = new Events();
            SharpBridge.bridgeServer.registerModuleEvents("Example.dll", events);
        }
    }
}

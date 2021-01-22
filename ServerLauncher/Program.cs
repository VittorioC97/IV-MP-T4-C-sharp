using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using SharpBridge;

namespace ServerLauncher
{
    /*class EventsExample : SharpBridge.ServerEvents
    {
        override public bool onPlayerConnect(int playerid)
        {
            Console.WriteLine("Someone joined: " + playerid);
            return true;
        }
        override public bool onPlayerCredentials(int playerid)
        {
            Console.WriteLine("Credentials for: " + playerid);
            
            Player player = SharpBridge.Entities.getPlayer(playerid);
            Console.WriteLine("Player class: " + player);

            SharpBridge.Vector3 v = new SharpBridge.Vector3(100.0f, 2000.0f, 10.0f);
            player.spawn(v);
            return true;
        }

        override public void onPlayerDisconnect(int playerid, int reason)
        {
            Console.WriteLine("Player left: " + playerid + ", " + reason);
        }
        public override void onPlayerChat(int playerid, string txt)
        {
            Console.WriteLine(txt);
        }
    }*/
    class Program
    {
        //private static EventsExample events;
        static void Main(string[] args)
        {
            SharpBridge.bridgeServer.startIVMPServer();

            string appDir = Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location) + "\\modules";

            Console.WriteLine("Finding modules");
            DirectoryInfo d = new DirectoryInfo(appDir);
            FileInfo[] Files = d.GetFiles("*.dll");
            foreach (FileInfo file in Files)
            {
                string name = file.Name.Substring(0, file.Name.Length-4);
                Console.WriteLine("Loading: " + name);
                Assembly asm = Assembly.LoadFile(Path.Combine(appDir, file.Name));
                Type customerType = asm.GetType(name + ".Module");
                if(customerType == null)
                {
                    Console.WriteLine("Namespace Module wasnt found");
                    continue;
                }

                MethodInfo staticMethodInfo = customerType.GetMethod("Run");
                if(staticMethodInfo == null)
                {
                    Console.WriteLine("Function Module::Run wasnt found");
                    continue;
                }
                staticMethodInfo.Invoke(null, null);
            }
            SharpBridge.bridgeServer.controlServerNow();
        }
    }
}

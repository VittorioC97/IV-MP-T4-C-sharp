using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using SharpBridge;
using System.Text.Json;
using System.Text.Json.Serialization;

namespace ServerLauncher
{
    class Program
    {
        static void Main(string[] args)
        {
            string appDir = Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location);
            string configStr;
            using (StreamReader file = new StreamReader(appDir + "\\config.json"))
            {
                configStr = file.ReadToEnd();
            }

            var config = JsonSerializer.Deserialize<Configuration>(configStr);
            SharpBridge.bridgeServer.startIVMPServer(config.port, config.name, config.location, config.url, config.masterList, config.gtaIV);

            Console.WriteLine("Loading modules");
            foreach (string module in config.modules)
            {
                Console.WriteLine("Loading: " + module);
                Assembly asm = Assembly.LoadFile(Path.Combine(appDir, "modules", module + ".dll"));
                Type customerType = asm.GetType(module + ".Module");
                if(customerType == null)
                {
                    Console.WriteLine("Namespace Module wasn't found");
                    continue;
                }

                MethodInfo staticMethodInfo = customerType.GetMethod("Run");
                if(staticMethodInfo == null)
                {
                    Console.WriteLine("Function Module::Run wasn't found");
                    continue;
                }
                staticMethodInfo.Invoke(null, null);
            }
            SharpBridge.bridgeServer.controlServerNow();
        }
    }
}

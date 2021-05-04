using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using SharpBridge;

namespace Example.Commands
{
    public static class VehicleCommands
    {
        public static void Spawn(SharpBridge.Player player, object[] param)
        {
            string name = ((string)param[0]).ToUpper();
            int vehModel = VehicleModels.getModelByName(name);
            if(vehModel == -1)
            {
                player.sendMsg($"'{name}' is an invalid model", ChatColor.ERROR);
                return;
            }

            int color = new Random().Next(0, 140);
            Vector3 pos = player.getPos();
            pos.z += 1.0f; ;
            Vehicle veh = Entities.createVehicle(vehModel, pos, new Vector3(0.0f, 0.0f, player.getHeading()),
                color, color, color, color, player.getWorld());

            player.sendMsg($"{name} spawned: {veh.getId()}", ChatColor.SUCCESS);
        }
    }
}

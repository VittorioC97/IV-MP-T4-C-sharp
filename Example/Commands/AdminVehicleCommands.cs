using System;
using SharpBridge;

namespace Example.Commands
{
    public static class AdminVehicleCommands
    {
        public static void Save(Player player, object[] param)
        {
            Vehicle veh = Entities.getVehicle(player.isInVehicle());
            if(veh == null)
            {
                player.sendMsg("You must be in a vehicle", ChatColor.ERROR);
                return;
            }

            Vector3 pos = veh.getPosition(), rot = veh.getRotation();
            Models.EntityEF et = new Models.EntityEF
            {
                vehicle = new Models.VehicleEF
                {
                    color = (short)veh.getColor(0),
                    rx = rot.x,
                    ry = rot.y,
                    rz = rot.z,
                    model = (short)veh.getModel()
                },
                x = pos.x,
                y = pos.y,
                z = pos.z,
                createDate = DateTime.Now,
                items = new System.Collections.Generic.List<Models.ItemEF>()
            };
            et.vehicle.entity = et;

            using (Repositories.VehicleRepository repository = new Repositories.VehicleRepository())
            {
                repository.entities.Add(et);
                repository.SaveChanges();
                player.sendMsg($"Vehicle stored with ID {et.vehicle.id}", ChatColor.SUCCESS);
            }     
        }
    }
}

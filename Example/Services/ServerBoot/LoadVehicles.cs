using System;
using System.Collections.Generic;
using System.Data.Entity.Infrastructure;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Example.Repositories;
using Example.Models;
using System.Data.Entity;
using System.Text.Json;

namespace Example.Services.ServerBoot
{
    public static class LoadVehicles
    {
        public static void Load()
        {
            try
            {
                using (VehicleRepository db = new VehicleRepository())
                {
                    List<VehicleEF> vehs = db.vehicles.Include(v=>v.entity).Include(i=>i.entity.items).ToList();
                    foreach(VehicleEF v in vehs)
                    {
                        Game.Vehicle gv = new Game.Vehicle(v);

                        SharpBridge.Vehicle spawn = SharpBridge.Entities.createVehicle(v.model,
                            gv.GetStoredPos(), gv.GetStoredRot(), gv.vehicle.color, gv.vehicle.color,
                            gv.vehicle.color, gv.vehicle.color, 1);

                        Game.VehiclesManager.Add(spawn.getId(), gv);
                    }
                }
            }
            catch (DbUpdateException e)
            {
                Console.WriteLine(e.ToString());
                SharpBridge.Log.Write(e.ToString());
            }
        }
    }
}

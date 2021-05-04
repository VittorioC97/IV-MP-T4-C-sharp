using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using SharpBridge;

namespace Example.Game
{
    public class Vehicle
    {
        public Models.VehicleEF vehicle;

        public Vehicle(Models.VehicleEF v)
        {
            this.vehicle = v;
        }
        public Vector3 GetStoredPos()
        {
            return new Vector3(vehicle.entity.x, vehicle.entity.y, vehicle.entity.z);
        }
        public void SetStoredPos(Vector3 pos)
        {
            vehicle.entity.x = pos.x;
            vehicle.entity.y = pos.y;
            vehicle.entity.z = pos.z;
        }
        public Vector3 GetStoredRot()
        {
            return new Vector3(vehicle.rx, vehicle.ry, vehicle.rz);
        }
        public void SetStoredRot(Vector3 pos)
        {
            vehicle.rx = pos.x;
            vehicle.ry = pos.y;
            vehicle.rz = pos.z;
        }
    }
}

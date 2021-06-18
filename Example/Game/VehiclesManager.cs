using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Example.Models;

namespace Example.Game
{
    public static class VehiclesManager
    {
        private static Dictionary<int, Vehicle> spawned = new Dictionary<int, Vehicle>();

        public static Vehicle Get(int id)
        {
            return spawned.ContainsKey(id) ? spawned[id] : null;
        }
        public static void Add(int id, Vehicle v)
        {
            spawned[id] = v;
        }
        public static void Remove(int id)
        {
            spawned.Remove(id);
        }
    }
}

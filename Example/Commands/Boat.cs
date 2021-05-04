using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using SharpBridge;

namespace Example.Commands
{
    public static class Boat
    {
        private static List<SharpBridge.Object> objs = new List<SharpBridge.Object>();

        public static void Spawn(SharpBridge.Player player, object[] param)
        {    
            if (objs.Count != 0)
            {
                foreach (var i in objs) i.Destroy();
                objs.Clear();
            }

            Vector3 pos = player.getPos();
            pos.y += 200.0f;
            uint[] boatObjs = {1239854102, 2219185248, 67157199, 1930762713, 1233545547, 1005833766};
            foreach (uint obj in boatObjs)
            {
                objs.Add(Entities.createObject(pos, new Quaternion(), obj, player.getWorld(), false, 0, 255));
            }
        }

        public static void MoveSouth(SharpBridge.Player player, object[] param)
        {
            foreach (var i in objs)
            {
                Vector3 pos = i.getPos();
                pos.y -= 1000.0f;
                i.moveObject(pos, i.getRot(), 200000);
            }
        }
    }
}

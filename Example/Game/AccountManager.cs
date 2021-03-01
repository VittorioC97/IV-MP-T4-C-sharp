using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Example.Game
{
    static class AccountManager
    {
        private static Dictionary<int, Account> players = new Dictionary<int, Account>();
        public static void Add(int playerid, Account player)
        {
            players.Add(playerid, player);
        }
        public static void Remove(int playerid)
        {
            players.Remove(playerid);
        }
        public static Account Get(int playerid)
        {
            return players[playerid];
        }
        public static bool IsOnline(int playerid)
        {
            return players.ContainsKey(playerid);
        }
        public static Account GetByName(ref string name)
        {
            foreach(var i in players)
            {
                if (i.Value.getName() == name) return i.Value;
            }
            return null;
        }
    }
}

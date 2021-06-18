using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Example.Models;

namespace Example.Game
{
    public static class ItemTypesManager
    {
        private static List<ItemTypesEF> items = new List<ItemTypesEF>();

        public static void AddItem(ItemTypesEF i)
        {
            items.Add(i);
        }

        public static void CopyItems(ref List<ItemTypesEF> list)
        {
            items = list;
            foreach (var i in items)
            {
                if (i.weapon != null)
                {
                    i.weapon.ammoItemClass = list.Where(j => j.id == i.weapon.ammoItem).FirstOrDefault();
                }
            }
        }

        public static ItemTypesEF GetItemTypeById(int id)
        {
            return items.Where(i => i.id == (short)id).FirstOrDefault();
        }
        public static ItemTypesEF GetItemTypeByItem(ItemEF item)
        {
            return items.Where(i => i.id == item.type).FirstOrDefault();
        }
        public static ItemTypesEF GetItemTypeByName(ref string lowerCase)
        {
            foreach(ItemTypesEF i in items)
            {
                if (i.name.ToLower() == lowerCase) return i;
            }
            return null;
        }
        public static ItemTypesEF GetWeaponFromGameWeapon(byte weapon)
        {
            return items.Where(i => i.weapon != null && i.weapon.gameId == weapon).FirstOrDefault();
        }
        public static ItemTypesEF GetAmmoFromGameWeapon(byte weapon)
        {
            return items.Where(i => i.weapon != null && i.weapon.gameId == weapon).FirstOrDefault();
        }
    }
}

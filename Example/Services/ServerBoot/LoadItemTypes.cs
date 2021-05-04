using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Example.Repositories;
using System.Data.Entity;
using System.Text.Json;

namespace Example.Services.ServerBoot
{
    public static class LoadItemTypes
    {
        public static void LoadTypes()
        {
            using (ItemTypesRepository db = new ItemTypesRepository())
            {
                var items = db.items.Include(i => i.weapon).ToList();
                Game.ItemTypesManager.CopyItems(ref items);
            }
        }
    }
}

using System.Linq;
using Example.Repositories;
using System.Data.Entity;

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

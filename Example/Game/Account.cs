using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Example.Game
{
    class Account
    {
        private Models.UserEF user { get; set; }

        public Account(Models.UserEF user)
        {
            this.user = user;
        }
        public void setClothesFromString(SharpBridge.Player player)
        {
            Dictionary<uint, uint> dic = new Dictionary<uint, uint>();

            string[] pieces = user.clothes.Split(' ');
            try
            {
                if (pieces.Length >= 1) player.setSkinId(uint.Parse(pieces[0]));

                for (uint i = 1; i < pieces.Length; i++)
                {
                    string[] parts = pieces[i].Split(',');
                    if (parts.Length != 2) continue;

                    uint part = uint.Parse(parts[0]);
                    uint id = uint.Parse(parts[1]);

                    if (part < 10) player.setClothes(part, id);
                    else player.setProperty(part - 10, id);
                }
            }
            catch (Exception) { }
        }

        public void updateClothes(SharpBridge.Player player)
        {
            string s = SharpBridge.Skins.getIdByHash(player.getSkinModel()) + " ";
            for (uint i = 0; i < 12; i++)
            {
                uint val = i < 10 ? player.getClothes(i) : player.getProperty(i - 10);
                if (val == 0) continue; //If default why bother
                s += $"{i},{val} ";
            }
            user.clothes = s;
        }
        public SharpBridge.Vector3 getPos()
        {
            return new SharpBridge.Vector3(user.entity.x, user.entity.y, user.entity.z);
        }     
        public void updatePos(SharpBridge.Vector3 v)
        {
            user.entity.x = v.x;
            user.entity.y = v.y;
            user.entity.z = v.z;
        }
        public void updateHealth(int hp, int armor)
        {
            user.hp = (byte)hp;
            user.armor = (byte)armor;
        }
        public void save()
        {
            try
            {
                using (Repositories.UserRepository accs = new Repositories.UserRepository())
                {
                    Console.WriteLine("Saving Player");

                    bool mustAttach = false;
                    foreach(Models.ItemEF item in user.entity.items)
                    {
                        if (item.id == 0) mustAttach = true;
                        else if(item.mustSave)
                        {
                            item.mustSave = false;
                            accs.Entry(item).State = System.Data.Entity.EntityState.Modified; //Forces it to update
                        }
                    }

                    if (mustAttach) accs.users.Attach(user); //adds new items

                    accs.Entry(user.entity).State = System.Data.Entity.EntityState.Modified;
                    accs.Entry(user).State = System.Data.Entity.EntityState.Modified;
                    accs.SaveChanges();

                    Console.WriteLine(System.Text.Json.JsonSerializer.Serialize(user.entity.items));
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }
        }
        public string getName()
        {
            return user.name;
        }

        public void updateWeapon(byte model, short amount)
        {
            Models.ItemTypesEF weaponItem = ItemTypesManager.GetWeaponFromGameWeapon(model);
            if (weaponItem == null) return;

            Models.ItemEF item = user.entity.items.Where(i => i.type == weaponItem.weapon.ammoItem).FirstOrDefault();
            if(item == null)
            {
                item = new Models.ItemEF
                {
                    entity = user.entity,
                    type = model,
                    amount = amount,
                    fk = user.entity.id,
                    mustSave = false
                };
                user.entity.items.Add(item);
            }
            else if(item.amount != amount)
            {
                item.amount = amount;
                item.mustSave = true;
            }
        }
    }
}

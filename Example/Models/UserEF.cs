using System.ComponentModel.DataAnnotations.Schema;
using Newtonsoft.Json;
using System;

namespace Example.Models
{
    [Table("users")]
    public class UserEF
    {
        [ForeignKey("entity")]
        public int id { get; set; }

        [Index(IsUnique = true)]
        public string name { get; set; }
        public string password { get; set; }
        public int moneyBank { get; set; }
        public string clothes { get; set; }
        public byte hp { get; set; }
        public byte armor { get; set; }

        [JsonIgnore]
        public virtual EntityEF entity { get; set; }

        public void save()
        {
            try
            {
                using (Repositories.UserRepository accs = new Repositories.UserRepository())
                {
                    Console.WriteLine("Saving Player");
                    Console.WriteLine(JsonConvert.SerializeObject(entity.items));

                    foreach (Models.ItemEF item in entity.items)
                    {
                        item.mustSave = false;
                        if (item.id == 0)
                        {
                            accs.Entry(item).State = System.Data.Entity.EntityState.Added;
                        }
                        else
                        {
                            accs.Entry(item).State = System.Data.Entity.EntityState.Modified; //Forces it to update
                        }
                    }

                    //if (mustAttach) accs.users.Attach(this); //adds new items

                    accs.Entry(entity).State = System.Data.Entity.EntityState.Modified;
                    accs.Entry(this).State = System.Data.Entity.EntityState.Modified;
                    accs.SaveChanges();
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }
        }
    }
}

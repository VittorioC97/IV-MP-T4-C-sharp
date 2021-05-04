using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Example.Models;
using MySql.Data.Entity;

namespace Example.Repositories
{
    [DbConfigurationType(typeof(MySqlEFConfiguration))]
    class ItemTypesRepository : ReposityConnection
    {
        public DbSet<ItemTypesEF> items { get; set; }
        public DbSet<WeaponTypesEF> weapons { get; set; }
        protected override void OnModelCreating(DbModelBuilder mb)
        {
            mb.Entity<WeaponTypesEF>()
                .HasKey(v => v.weaponItem)
                .HasRequired(v => v.item)
                .WithOptional(e => e.weapon);
        }
    }
}

using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MySql.Data.Entity;

namespace Example.Repositories
{
    [DbConfigurationType(typeof(MySqlEFConfiguration))]
    public class VehicleRepository : ReposityConnection
    {
        public DbSet<Models.VehicleEF> vehicles { get; set; }
        public DbSet<Models.EntityEF> entities { get; set; }

        protected override void OnModelCreating(DbModelBuilder mb)
        {
            mb.Entity<Models.VehicleEF>()
                .HasKey(v => v.id)
                .HasRequired(v => v.entity)
                .WithOptional(e => e.vehicle);

            mb.Entity<Models.EntityEF>()
                .HasMany<Models.ItemEF>(e => e.items)
                .WithRequired(i => i.entity)
                .HasForeignKey<int>(i => i.fk);
        }

    }
}

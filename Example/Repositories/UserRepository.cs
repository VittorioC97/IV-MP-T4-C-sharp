using MySql.Data.Entity;
using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Example.Repositories
{
    [DbConfigurationType(typeof(MySqlEFConfiguration))]
    class UserRepository : ReposityConnection
    {
        public DbSet<Models.UserEF> users { get; set; }
        public DbSet<Models.EntityEF> entities { get; set; }
        public DbSet<Models.ItemEF> items { get; set; }

        protected override void OnModelCreating(DbModelBuilder mb)
        {
            mb.Entity<Models.UserEF>()
                .HasKey(v => v.id)
                .HasRequired(v => v.entity)
                .WithOptional(e => e.user);

            mb.Entity<Models.EntityEF>()
                .HasMany<Models.ItemEF>(e => e.items)
                .WithRequired(i => i.entity)
                .HasForeignKey<int>(i => i.fk);
        }
    }
}

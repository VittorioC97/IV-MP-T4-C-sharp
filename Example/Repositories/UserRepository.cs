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
        public DbSet<Models.User> users { get; set; }
        public DbSet<Models.UserContainer> containers { get; set; }
        public DbSet<Models.UserItem> items { get; set; }

        protected override void OnModelCreating(DbModelBuilder mb)
        {
            //base.OnModelCreating(mb);

            mb.Entity<Models.User>()
                .HasRequired(u => u.container)
                .WithMany(x => x.user)
                .HasForeignKey<int>(x => x.containerId);

            mb.Entity<Models.UserItem>()
                .HasRequired<Models.UserContainer>(c => c.container)
                .WithMany(g => g.items)
                .HasForeignKey<int>(s => s.fk);

            /*mb.Entity<Models.UserContainer>()
                .HasMany<Models.UserItem>(x => x.items)
                .WithRequired(x => x.container)
                .HasForeignKey(x => x.fk);*/
        }
    }
}

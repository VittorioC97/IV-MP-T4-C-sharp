using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Example.Repositories
{
    public class ReposityConnection : DbContext
    {
        public ReposityConnection() : base("server=127.0.0.1;port=3307;database=csharp;uid=root;password=1234")
        {
        }
    }
}

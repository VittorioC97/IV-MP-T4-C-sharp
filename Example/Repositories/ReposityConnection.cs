using System.Collections.Generic;
using System.Data.Entity;
using Newtonsoft.Json;
using System.IO;
using System;

namespace Example.Repositories
{
    public static class RepositoryConnection
    {
        public static readonly string cString;
        static RepositoryConnection()
        {
            using (StreamReader file = new StreamReader("config.json"))
            {
                var values = JsonConvert.DeserializeObject<Dictionary<string, Object>>(file.ReadToEnd());
                cString = values["database"].ToString();
            }
        }
    }
    public class ReposityConnection : DbContext
    {
        public ReposityConnection() : base(RepositoryConnection.cString)
        {
        }
    }
}

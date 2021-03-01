using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Text;
using System.Text.Json.Serialization;
using System.Threading.Tasks;

namespace Example.Models
{
    class User
    {
        [Key]
        public int id { get; set; }

        [Index(IsUnique = true)]
        public string name { get; set; }
        public string password { get; set; }
        public int moneyBank { get; set; }
        public float x { get; set; }
        public float y { get; set; }
        public float z { get; set; }
        public string clothes { get; set; }
        public byte hp { get; set; }
        public byte armor { get; set; }

        [ForeignKey("container")]
        public int containerId { get; set; }

        [JsonIgnore]
        public virtual UserContainer container { get; set; }
    }
}

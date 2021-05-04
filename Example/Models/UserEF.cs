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
    }
}

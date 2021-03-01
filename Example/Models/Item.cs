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
    [Table("items")]
    class Item
    {
        [Key]
        public int id { get; set; }
        public byte type { get; set; }
        public short amount { get; set; }

        [ForeignKey("container")]
        public int fk { get; set; }

        [NotMapped]
        public bool mustSave { get; set; } //default is false
    }

    [Table("items")]
    class UserItem : Item
    {
        [JsonIgnore]
        public virtual UserContainer container { get; set; }
    }
}

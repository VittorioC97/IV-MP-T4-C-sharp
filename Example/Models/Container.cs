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
    [Table("Containers")]
    class Container
    {
        [Key]
       
        public int id { get; set; }
        public byte type { get; set; }
    }

    [Table("Containers")]
    class UserContainer : Container
    {
        public virtual List<UserItem> items { get; set; }
        public virtual List<User> user { get; set; } //This is supposed to be One-One but that wasnt working so fuck it
    }
}

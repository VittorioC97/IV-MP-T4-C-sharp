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
    public class ItemEF
    {
        [Key]
        public int id { get; set; }

        [ForeignKey("entity")]
        public int fk { get; set; }

        public short type { get; set; }
        public short amount { get; set; }

        [JsonIgnore]
        public virtual EntityEF entity { get; set; }

        [NotMapped]
        public bool mustSave { get; set; } //default is false
    }
}

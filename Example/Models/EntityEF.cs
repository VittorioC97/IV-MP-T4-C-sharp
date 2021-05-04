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
    [Table("entities")]
    public class EntityEF
    {
        [Key]
        public int id { get; set; }
        public float x { get; set; }
        public float y { get; set; }
        public float z { get; set; }

        public virtual VehicleEF vehicle { get; set; }
        public virtual UserEF user { get; set; }
        public virtual List<ItemEF> items { get; set; }
    }
}

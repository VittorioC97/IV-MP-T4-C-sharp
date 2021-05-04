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
    [Table("vehicles")]
    public class VehicleEF
    {
        [ForeignKey("entity")]
        public int id { get; set; }
        public short model { get; set; }
        public float rx { get; set; }
        public float ry { get; set; }
        public float rz { get; set; }
        public short color { get; set; }
        [JsonIgnore]
        public virtual EntityEF entity { get; set; }
    }
}

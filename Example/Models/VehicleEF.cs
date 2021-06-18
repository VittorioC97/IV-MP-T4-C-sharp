using System.ComponentModel.DataAnnotations.Schema;
using Newtonsoft.Json;

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

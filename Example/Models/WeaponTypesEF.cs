using System.ComponentModel.DataAnnotations.Schema;
using Newtonsoft.Json;

namespace Example.Models
{
    [Table("weapons")]
    public class WeaponTypesEF
    {
        [ForeignKey("item")]
        public short weaponItem { get; set; }
        public short ammoItem { get; set; }
        public short buyAmount { get; set; }
        public byte gameId { get; set; }

        [JsonIgnore]
        public virtual ItemTypesEF item { get; set; }

        [NotMapped]
        public ItemTypesEF ammoItemClass { get; set; }
    }
}

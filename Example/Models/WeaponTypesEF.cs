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

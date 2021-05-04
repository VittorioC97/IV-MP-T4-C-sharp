using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Example.Models
{
    [Table("itemtypes")]
    public class ItemTypesEF
    {
        [Key]
        public short id { get; set; }
        public string name { get; set; }
        public short price { get; set; }
        public byte droppable { get; set; }
        public virtual WeaponTypesEF weapon { get; set; }
    }
}

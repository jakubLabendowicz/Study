using System;
using System.Collections.Generic;

namespace Lab7___Database_First.Models
{
    public partial class MediaType
    {
        public MediaType()
        {
            Tracks = new HashSet<Track>();
        }

        public long MediaTypeId { get; set; }
        public string? Name { get; set; }

        public virtual ICollection<Track> Tracks { get; set; }
    }
}

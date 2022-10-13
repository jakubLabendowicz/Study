using System;
using System.Collections.Generic;

namespace Lab7___Database_First.Models
{
    public partial class Artist
    {
        public Artist()
        {
            Albums = new HashSet<Album>();
        }

        public long ArtistId { get; set; }
        public string? Name { get; set; }

        public virtual ICollection<Album> Albums { get; set; }
    }
}

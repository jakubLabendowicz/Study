using System;
using System.Collections.Generic;

namespace Lab7___Database_First.Models
{
    public partial class Album
    {
        public Album()
        {
            Tracks = new HashSet<Track>();
        }

        public long AlbumId { get; set; }
        public string Title { get; set; } = null!;
        public long ArtistId { get; set; }

        public virtual Artist Artist { get; set; } = null!;
        public virtual ICollection<Track> Tracks { get; set; }
    }
}

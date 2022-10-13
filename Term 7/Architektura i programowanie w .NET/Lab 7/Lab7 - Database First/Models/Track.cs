using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;

namespace Lab7___Database_First.Models
{
    public partial class Track
    {
        public Track()
        {
            InvoiceLines = new HashSet<InvoiceLine>();
            Playlists = new HashSet<Playlist>();
        }

        public long TrackId { get; set; }
        public string Name { get; set; } = null!;
        public long? AlbumId { get; set; }
        public long MediaTypeId { get; set; }
        public long? GenreId { get; set; }
        public string? Composer { get; set; }
        public long Milliseconds { get; set; }
        public long? Bytes { get; set; }
        [DataType(DataType.Currency)]
        public decimal UnitPrice { get; set; }

        public virtual Album? Album { get; set; }
        public virtual Genre? Genre { get; set; }
        public virtual MediaType MediaType { get; set; } = null!;
        public virtual ICollection<InvoiceLine> InvoiceLines { get; set; }

        public virtual ICollection<Playlist> Playlists { get; set; }
    }
}

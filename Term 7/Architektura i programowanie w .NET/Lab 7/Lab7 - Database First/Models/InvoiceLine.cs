using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;

namespace Lab7___Database_First.Models
{
    public partial class InvoiceLine
    {
        public long InvoiceLineId { get; set; }
        public long InvoiceId { get; set; }
        public long TrackId { get; set; }
        [DataType(DataType.Currency)]
        public decimal UnitPrice { get; set; }
        public long Quantity { get; set; }

        public virtual Invoice Invoice { get; set; } = null!;
        public virtual Track Track { get; set; } = null!;
    }
}

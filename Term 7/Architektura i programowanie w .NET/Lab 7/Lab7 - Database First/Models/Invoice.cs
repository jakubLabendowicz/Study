using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Xml.Linq;

namespace Lab7___Database_First.Models
{
    public partial class Invoice
    {
        public Invoice()
        {
            InvoiceLines = new HashSet<InvoiceLine>();
        }

        public long InvoiceId { get; set; }
        public long CustomerId { get; set; }
        [DataType(DataType.DateTime)]
        [Display(Name = "Date")]
        [UIHint("DateView")]
        public DateTime InvoiceDate { get; set; }
        [Display(Name = "Billing Address")]
        public string? BillingAddress { get; set; }
        [Display(Name = "City")]
        public string? BillingCity { get; set; }
        [Display(Name = "State")]
        public string? BillingState { get; set; }
        [Display(Name = "Country")]
        public string? BillingCountry { get; set; }
        public string? BillingPostalCode { get; set; }
        [DataType(DataType.Currency)]
        public decimal Total { get; set; }

        public virtual Customer Customer { get; set; } = null!;
        public virtual ICollection<InvoiceLine> InvoiceLines { get; set; }
    }
}

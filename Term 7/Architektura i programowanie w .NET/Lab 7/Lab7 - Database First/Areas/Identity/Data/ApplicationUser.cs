using Microsoft.AspNetCore.Identity;

namespace Lab7___Database_First.Areas.Identity.Data
{
    public class ApplicationUser : IdentityUser
    {
        public long CustomerId { get; set; }
    }
}

using Lab5___ORM.Models;
using Microsoft.EntityFrameworkCore;

namespace Lab5___ORM.Data
{
    public class MoviesDbContext : DbContext
    {
        public DbSet<Movie> Movies { get; set; }

        public MoviesDbContext(DbContextOptions options) :
            base(options)
        {

        }
    }
}

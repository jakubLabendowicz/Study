using Lab6___Walidacja.Models;
using Microsoft.EntityFrameworkCore;

namespace Lab6___Walidacja.Data
{
    public class MoviesDbContext : DbContext
    {
        public DbSet<Movie> Movies { get; set; }
        public DbSet<Genre> Genres { get; set; }
        public MoviesDbContext(DbContextOptions options) :
            base(options)
        {

        }
    }
}

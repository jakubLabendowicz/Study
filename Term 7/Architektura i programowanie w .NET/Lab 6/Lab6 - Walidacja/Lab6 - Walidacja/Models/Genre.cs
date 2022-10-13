using System.ComponentModel.DataAnnotations;

namespace Lab6___Walidacja.Models
{
    public class Genre
    {
        [Key]
        public int Id { get; set; }
        public string Name { get; set; }
    }
}

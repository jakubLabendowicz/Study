using System.ComponentModel.DataAnnotations;
using Lab6___Walidacja.Models;

namespace Lab6___Walidacja.Models
{
    public class Movie
    {
        [Key]
        public int Id { get; set; }
        [Required]
        [MaxLength(50, ErrorMessage = "Tytuł może mieć max. 50 znaków.")]
        public string Title { get; set; }
        [UIHint("LongText")]
        [Required(ErrorMessage = "Opis jest wymagany.")]
        public string Description { get; set; }
        [UIHint("Stars")]
        [Range(0, 10, ErrorMessage = "Ocena musi być z zakresu od 0 do 10.")]
        public int Rating { get; set; }
        [UIHint("TrailerLink")]
        public string? TrailerLink { get; set; }
        public Genre Genre { get; set; }
    }
}

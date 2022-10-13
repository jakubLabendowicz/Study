using System.ComponentModel.DataAnnotations;

namespace Lab5___ORM.Models
{
    public class Movie
    {
        public int Id { get; set; }
        public string Title { get; set; }
        [UIHint("LongText")]
        public string Description { get; set; }
        [UIHint("Stars")]
        public int Rating { get; set; }
        [UIHint("TrailerLink")]
        public string TrailerLink { get; set; }
    }
}

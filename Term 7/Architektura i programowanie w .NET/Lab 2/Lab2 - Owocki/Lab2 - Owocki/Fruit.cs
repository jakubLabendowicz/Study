using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Lab2___Async;

namespace Lab2___Owocki
{
    public class Fruit
    {
        static readonly string[] names = new string[]
        {
            "Apple", "Banana", "Cherry",
            "Durian", "Edelberry", "Grape", "Jackfruit"
        };

        public string Name { get; set; }
        public bool IsSweet { get; set; }
        public double Price { get; set; }
        public double UsdPrice => Price / UsdCourse.Current;
        public static Fruit Create()
        {
            Random r = new Random();
            return new Fruit()
            {
                Name = names[r.Next(names.Length)],
                IsSweet = r.NextDouble() > 0.5,
                Price = r.NextDouble() * 10
            };
        }

        public override string ToString()
        {
            var priceReadable = MyFormatter.FormatPlnPrice(Price);
            var usdReadable = MyFormatter.FormatUsdPrice(UsdPrice);
            return $"Fruit: {Name} - Sweet: {IsSweet}, {priceReadable} / {usdReadable}";
        }
    }
}

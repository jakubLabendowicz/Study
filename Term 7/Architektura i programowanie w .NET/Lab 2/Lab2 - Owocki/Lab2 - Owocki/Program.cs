// See https://aka.ms/new-console-template for more information

using Lab2___Async;
using Lab2___Owocki;

Console.WriteLine("Hello, World!");

UsdCourse.Current = await UsdCourse.GetUsdCourseAsync();

List<Fruit> list = new List<Fruit>();

for (int i = 0; i < 10; i++)
{
    list.Add(Fruit.Create());
}

foreach (var fruit in list)
{
    Console.WriteLine(fruit);
}

Console.WriteLine("Po filtracji:");

var ordered = list.OrderBy(fruit => fruit.Price);

var filtered = ordered.Where(fruit => fruit.IsSweet);

foreach (var fruit in filtered)
{
    Console.WriteLine(fruit);
}
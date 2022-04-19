using ServiceReference1;

static async Task Main(string[] args)
{
    Console.WriteLine("My First SOAP Client!");
    MyFirstSOAPInterfaceClient client = new MyFirstSOAPInterfaceClient();
    string text = await client.getHelloWorldAsStringAsync("Karol");
    Console.WriteLine(text);
    long liczba = await client.getDaysBetweenDatesAsync("20 03 2022", "30 03 2022");
    Console.WriteLine(liczba);
}

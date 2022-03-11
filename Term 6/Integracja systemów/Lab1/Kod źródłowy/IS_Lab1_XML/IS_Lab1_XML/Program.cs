using System.IO;

namespace IS_Lab1_XML
{
    internal class IS_Lab1_XML
    {
        static void Main(String[] args)
        {
            string xmlpath = Path.Combine("Assets", "data.xml");
            // odczyt danych z wykorzystaniem DOM
            Console.WriteLine("XML loaded by DOM Approach");
            XMLReadWithDOMApproach.Read(xmlpath);
            Console.WriteLine();
            
            // odczyt danych z wykorzystaniem SAX
            Console.WriteLine("XML loaded by SAX Approach");
            XMLReadWithSAXApproach.Read(xmlpath);
            Console.WriteLine();

            // odczyt danych z wykorzystaniem XPath i DOM
            Console.WriteLine("XML loaded with XPath");
            XMLReadWithXLSTDOM.Read(xmlpath);


            Console.ReadLine();
        }
    }
}
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace IS_Lab1_XML
{
    internal class XMLReadWithSAXApproach
    {
        internal static void Read(string filepath)
        {
            // konfiguracja początkowa dla XmlReadera
            XmlReaderSettings settings = new XmlReaderSettings();
            settings.IgnoreComments = true;
            settings.IgnoreProcessingInstructions = true;
            settings.IgnoreWhitespace = true;
            // odczyt zawartości dokumentu
            XmlReader reader = XmlReader.Create(filepath, settings);
            // zmienne pomocnicze
            int count1 = 0;
            string postac = "";
            string sc = "";
            string nazwa = "";
            reader.MoveToContent();
            // analiza każdego z węzłów dokumentu

            
            while (reader.Read())
            {
                if (reader.NodeType == XmlNodeType.Element && reader.Name == "produktLeczniczy")
                {
                    postac = reader.GetAttribute("postac");
                    sc = reader.GetAttribute("nazwaPowszechnieStosowana");
                    if (postac == "Krem" && sc == "Mometasoni furoas")
                        count1++;
                }
            }
            Console.WriteLine("Liczba produktów leczniczych w postaci kremu, których jedyną substancją czynną jest Mometasoni furoas {0}", count1);




            reader = XmlReader.Create(filepath, settings);
            reader.MoveToContent();
            int count2 = 0;
            Dictionary<string, List<String>> productsDictionary = new Dictionary<string, List<String>>();
            while (reader.Read())
            {
                if (reader.NodeType == XmlNodeType.Element && reader.Name == "produktLeczniczy")
                {
                    postac = reader.GetAttribute("postac");
                    sc = reader.GetAttribute("nazwaPowszechnieStosowana");


                    if (!productsDictionary.ContainsKey(sc))
                    {
                        List<string> list = new List<string> { postac };
                        productsDictionary.Add(sc, list);
                    }
                    else
                    {
                        List<string> list = productsDictionary[sc];
                        if (!list.Contains(postac))
                        {
                            list.Add(postac);
                        }
                        productsDictionary[sc] = list;
                    }
                }
            }

            foreach (List<String> list in productsDictionary.Values)
            {
                if (list.Count > 1)
                {
                    count2++;
                }
            }
            Console.WriteLine("Liczba preparatów leczniczych o takiej samie nazwie powszechnej, pod różnymi postaciami {0}", count2);





            reader = XmlReader.Create(filepath, settings);
            reader.MoveToContent();
            Dictionary<string, int> substancesDictionary = new Dictionary<string, int>();
            while (reader.Read())
            {
                if (reader.NodeType == XmlNodeType.Element && reader.Name == "substancjaCzynna")
                {
                    string substancja = reader.ReadString();

                    if (!substancesDictionary.ContainsKey(substancja))
                    {
                        substancesDictionary.Add(substancja, 1);
                    }
                    else
                    {
                        substancesDictionary[substancja]++;
                    }
                }
            }
            Console.WriteLine("Substancja czynna, która występuje w największej liczbie produktów leczniczych {0}", substancesDictionary.Aggregate((x, y) => x.Value > y.Value ? x : y).Key);





            reader = XmlReader.Create(filepath, settings);
            reader.MoveToContent();
            Dictionary<string, int> productsDictionary2 = new Dictionary<string, int>();
            while (reader.Read())
            {
                if (reader.NodeType == XmlNodeType.Element && reader.Name == "produktLeczniczy") {
                    nazwa = reader.GetAttribute("nazwaProduktu");
                }

                int number = 0;

                if (reader.NodeType == XmlNodeType.Element && reader.Name == "opakowanie")
                {
                    number++;
                }

                if (!productsDictionary2.ContainsKey(nazwa))
                {
                    productsDictionary2.Add(nazwa, number);
                }
            }

            string text1 = productsDictionary2.Max(x => x.Key);
            productsDictionary2.Remove(text1);

            string text2 = productsDictionary2.Max(x => x.Key);
            productsDictionary2.Remove(text2);

            string text3 = productsDictionary2.Max(x => x.Key);
            productsDictionary2.Remove(text2);

            Console.WriteLine("Trzy produkty lecznicze, w których jest najwięcej różnych opakowań {0}", text1 + ", " + text2 + ", " + text3 + ", ");
        }
    }
}
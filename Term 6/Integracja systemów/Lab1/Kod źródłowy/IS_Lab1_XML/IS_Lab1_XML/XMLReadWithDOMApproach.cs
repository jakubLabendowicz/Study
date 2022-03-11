using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace IS_Lab1_XML
{
    internal class XMLReadWithDOMApproach
    {
        internal static void Read(string filepath)
        {
            // odczyt zawartości dokumentu
            XmlDocument doc = new XmlDocument();
            doc.Load(filepath);
            string postac;
            string sc;
            string nazwa;
            var drugs = doc.GetElementsByTagName("produktLeczniczy");


            int count1 = 0;
            foreach (XmlNode d in drugs)
            {
                postac = d.Attributes.GetNamedItem("postac").Value;
                sc = d.Attributes.GetNamedItem("nazwaPowszechnieStosowana").Value;
                if (postac == "Krem" && sc == "Mometasoni furoas")
                    count1++;
            }
            Console.WriteLine("Liczba produktów leczniczych w postaci kremu, których jedyną substancją czynną jest Mometasoni furoas {0}", count1);


            int count2 = 0;
            Dictionary<string, List<String>> productsDictionary = new Dictionary<string, List<String>>();
            foreach (XmlNode d in drugs)
            {
                sc = d.Attributes.GetNamedItem("nazwaPowszechnieStosowana").Value;
                postac = d.Attributes.GetNamedItem("postac").Value;

                if(!productsDictionary.ContainsKey(sc))
                {
                    List<string> list = new List<string> { postac };
                    productsDictionary.Add(sc, list);
                } else
                {
                    List<string> list = productsDictionary[sc];
                    if(!list.Contains(postac))
                    {
                        list.Add(postac);
                    }
                    productsDictionary[sc] = list;
                }
            }

            foreach(List<String> list in productsDictionary.Values)
            {
                if (list.Count > 1)
                {
                    count2++;
                }
            }
            Console.WriteLine("Liczba preparatów leczniczych o takiej samie nazwie powszechnej, pod różnymi postaciami {0}", count2);





            Dictionary<string, int> substancesDictionary = new Dictionary<string, int>();
            foreach (XmlNode d in drugs)
            {
                foreach (XmlNode s in d.ChildNodes.Item(0))
                {
                    string substancja = s.InnerText.ToString();

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






            Dictionary<string, int> productsDictionary2 = new Dictionary<string, int>();
            foreach (XmlNode d in drugs)
            {
                nazwa = d.Attributes.GetNamedItem("nazwaProduktu").Value;
                int number = 0;
                foreach (XmlNode s in d.ChildNodes.Item(0))
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

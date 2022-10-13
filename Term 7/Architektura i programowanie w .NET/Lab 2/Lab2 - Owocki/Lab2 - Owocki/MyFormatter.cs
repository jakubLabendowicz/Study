using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab2___Owocki
{
    public class MyFormatter
    {
        public static string FormatUsdPrice(double price)
        {
            var usc = new CultureInfo("en-us");
            return price.ToString("C2", usc);
        }
        public static string FormatPlnPrice(double price)
        {
            var usc = new CultureInfo("pl-pl");
            return price.ToString("C2", usc);
        }
    }
}

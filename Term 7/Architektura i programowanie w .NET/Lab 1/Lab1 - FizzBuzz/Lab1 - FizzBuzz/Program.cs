

int n = 100;

for (int i = 0; i < n; i++)
{
    string word = "";
    if (i % 3 == 0) word += "Fizz";
    if (i % 5 == 0) word += "Buzz";
    if (word == "") word += i;
    Console.WriteLine(word);
}

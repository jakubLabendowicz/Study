using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab1___Gra
{
    internal class Game
    {
        public void Run(int maxNumber = 100)
        {
            Console.WriteLine($"Random gierka - Podaj liczbę od 0 do {maxNumber}");
            int tries = 0;
            bool won = false;
            int randomNumber = new Random().Next(0, maxNumber + 1);
            while (!won)
            {
                int number = GetNumberFromUser();
                if (number == randomNumber)
                    won = true;
                else if (number > randomNumber)
                    Console.WriteLine("Za dużo!");
                else
                    Console.WriteLine("Za mało!");
                tries++;
            }

            Console.WriteLine("GG - Podaj imie: ");
            var name = GetNameFromUser();
            HighScore score = new HighScore()
            {
                Trials = tries, Name = name,
            };
            GameSaveSystem gss = new GameSaveSystem();
            gss.SaveScore(score);

            var scores = gss.GetHighScores();
            foreach (var s in scores)
            {
                Console.WriteLine($"{s.Name} - {s.Trials}");
            }
        }

        private int GetNumberFromUser()
        {
            int number = 0;
            bool isOk = false;
            while (!isOk)
            {
                string? input = Console.ReadLine();
                if (input == null)
                    continue;
                isOk = Int32.TryParse(input, out number);
            }

            return number;
        }

        private string GetNameFromUser()
        {
            while (true)
            {
                string? input = Console.ReadLine();
                if (input != null)
                    return input;
            }
        }
    }
}

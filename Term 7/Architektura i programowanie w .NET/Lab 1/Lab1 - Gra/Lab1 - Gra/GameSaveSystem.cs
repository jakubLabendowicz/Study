using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.Json;
using System.Threading.Tasks;

namespace Lab1___Gra
{
    internal class GameSaveSystem
    {
        readonly string FileName = "highscores.json";
        public List<HighScore> GetHighScores()
        {

            if (File.Exists(FileName))
            {
                return JsonSerializer.Deserialize<List<HighScore>>(File.ReadAllText(FileName));
            }
            else
                return new List<HighScore>();
        }

        public void SaveScore(HighScore score)
        {
            var list = GetHighScores();
            list.Add(score);
            list.Sort((el1, el2) =>
            {
                return el1.Trials.CompareTo(el2.Trials);
            });

            File.WriteAllText(FileName,
                JsonSerializer.Serialize(list));
        }
    }
}

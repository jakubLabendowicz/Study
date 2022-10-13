using Lab8___WebAPI.Models;

namespace Lab8___WebAPI.Data
{
    public interface IFoxesRepository
    {
        void Add(Fox f);
        Fox Get(int id);
        IEnumerable<Fox> GetAll();
        void Update(int id, Fox f);
    }
}

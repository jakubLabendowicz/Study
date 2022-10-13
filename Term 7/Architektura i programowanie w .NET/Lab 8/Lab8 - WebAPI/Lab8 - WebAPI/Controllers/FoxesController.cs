using Lab8___WebAPI.Data;
using Lab8___WebAPI.Models;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;

namespace Lab8___WebAPI.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class FoxesController : ControllerBase
    {
        private IFoxesRepository _repo;

        public FoxesController(IFoxesRepository repo)
        {
            _repo = repo;
        }

        [HttpGet("{id}")]
        public IActionResult Get(int id)
        {
            return new JsonResult(_repo.Get(id));
        }

        [HttpPut("love/{id}")]
        public IActionResult Love(int id)
        {
            var fox = _repo.Get(id);
            if (fox == null)
                return NotFound();
            fox.Loves++;
            _repo.Update(id, fox);
            return Ok(fox);
        }

        [HttpPut("hate/{id}")]
        public IActionResult Hate(int id)
        {
            var fox = _repo.Get(id);
            if (fox == null)
                return NotFound();
            fox.Hates++;
            _repo.Update(id, fox);
            return Ok(fox);
        }

        [HttpGet]
        public IActionResult Get()
        {
       
            return new JsonResult(_repo.GetAll());
        }

        [HttpPost]
        public IActionResult Post([FromBody] Fox fox)
        {
            _repo.Add(fox);
            return CreatedAtAction(nameof(Get), new { id = fox.Id },
            fox);
        }
    }
}

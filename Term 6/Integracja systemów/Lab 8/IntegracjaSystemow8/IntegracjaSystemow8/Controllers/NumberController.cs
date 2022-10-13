using Microsoft.AspNetCore.Mvc;

using IntegracjaSystemow8.Model;
using IntegracjaSystemow8.Sevices.Users;
using Microsoft.AspNetCore.Authentication.JwtBearer;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Server.HttpSys;
using System;
using IntegracjaSystemow8.Services;

namespace IntegracjaSystemow8.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class NumberController : ControllerBase
    {
        private IUserService userService;
        public NumberController(IUserService userService)
        {
            this.userService = userService;
        }

        [HttpGet("getNumber")]
        [Authorize(Roles = "number", AuthenticationSchemes = JwtBearerDefaults.AuthenticationScheme)]
        public IActionResult getNumber()
        {
            Random rand = new Random();
            int[] tab = {2, 3, 5, 7, 11, 13 };
            int number = rand.Next(0, tab.Length);
            return Ok(tab[number]);
        }



    }
}
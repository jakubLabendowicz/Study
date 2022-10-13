using Microsoft.AspNetCore.Mvc;

using IntegracjaSystemow8.Model;
using IntegracjaSystemow8.Sevices.Users;
using Microsoft.AspNetCore.Authentication.JwtBearer;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Server.HttpSys;
using System.Linq;
using IntegracjaSystemow8.Services;

namespace IntegracjaSystemow8.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class UsersController : ControllerBase
    {
        private IUserService userService;
        public UsersController(IUserService userService)
        {
            this.userService = userService;
        }
        [HttpPost("authenticate")]
        public IActionResult
        Authenticate(AuthenticationRequest request)
        {
            var response = userService.Authenticate(request);
            if (response == null)
                return BadRequest(new
                {
                    message = "Username or password is incorrect"
                });
            return Ok(response);
        }

        [HttpGet("getUsers")]
        [Authorize(Roles = "admin", AuthenticationSchemes = JwtBearerDefaults.AuthenticationScheme)]
        public IActionResult GetUsers()
        {

            return Ok(userService.GetUsers());
        }

        [HttpGet("countUsers")]
        [Authorize(Roles = "user", AuthenticationSchemes = JwtBearerDefaults.AuthenticationScheme)]
        public IActionResult countUsers()
        {

            return Ok(userService.GetUsers().Count());
        }


    }
}
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;

namespace Lab4___Razor_Pages.Pages
{
    public class SingleModel : PageModel
    {
        [BindProperty(SupportsGet = true)]
        public string Image { get; set; }

        private string imagesDir;

        public SingleModel(IWebHostEnvironment env)
        {
            imagesDir = Path.Combine(env.WebRootPath, "images");
        }

        public IActionResult OnGet()
        {
            if (System.IO.File.Exists(Path.Combine(imagesDir, Image)))
            {
                return Page();
            }
            else
            {
                return NotFound();
            }
        }
    }
}

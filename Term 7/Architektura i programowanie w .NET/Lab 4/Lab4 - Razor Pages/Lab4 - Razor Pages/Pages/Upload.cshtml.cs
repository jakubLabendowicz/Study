using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;

namespace Lab4___Razor_Pages.Pages
{
    public class UploadModel : PageModel
    {
        [BindProperty]
        public IFormFile UploadedFile { get; set; }

        public UploadModel(IWebHostEnvironment environment)
        {
            imagesDir = Path.Combine(environment.WebRootPath, "images");
        }

        private string imagesDir;
        public void OnGet()
        {
        }

        public IActionResult OnPost()
        {
            if (UploadedFile != null)
            {
                string extension = ".jpg";
                switch (UploadedFile.ContentType)
                {
                    case "image/png":
                        extension = ".png"; 
                        break;
                    case "image/gif":
                        extension = ".gif";
                        break;
                }
                var fileName =
                    Path.GetFileNameWithoutExtension(Path.GetRandomFileName()) +
                    extension;
                using (var fs =
                       System.IO.File.OpenWrite(Path.Combine(imagesDir, fileName)))
                {
                    UploadedFile.CopyTo(fs);
                    return RedirectToPage("Index");
                }
                
            }
            return RedirectToPage("Error");
        }
    }
}

using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;

namespace Lab4___Razor_Pages.Pages
{
    public class IndexModel : PageModel
    {
        private readonly ILogger<IndexModel> _logger;
        public List<string> Images { get; set; }

        private string imagesDir;
        public IndexModel(ILogger<IndexModel> logger, IWebHostEnvironment environment)
        {
            imagesDir = Path.Combine(environment.WebRootPath, "images");
            _logger = logger;
        }

        private void UpdateFileList()
        {
            Images = new List<string>();
            foreach (var item in
                     Directory.EnumerateFiles(imagesDir).ToList())
            {
                Images.Add(Path.GetFileName(item));
            }
        }

        public void OnGet()
        {
            UpdateFileList();
        }
    }
}
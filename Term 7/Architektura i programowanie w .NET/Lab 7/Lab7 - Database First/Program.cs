using System.Globalization;
using Lab7___Database_First.Areas.Identity.Data;
using Microsoft.AspNetCore.Identity;
using Microsoft.EntityFrameworkCore;
using Lab7___Database_First.Data;
using Microsoft.AspNetCore.Localization;

var builder = WebApplication.CreateBuilder(args);

// Add services to the container.
var connectionString = builder.Configuration.GetConnectionString("DefaultConnection");
builder.Services.AddDbContext<ApplicationDbContext>(options =>
    options.UseSqlite(connectionString));
builder.Services.AddDatabaseDeveloperPageExceptionFilter();

builder.Services.AddDefaultIdentity<ApplicationUser>(options => options.SignIn.RequireConfirmedAccount = true)
    .AddEntityFrameworkStores<ApplicationDbContext>();
builder.Services.AddDbContext<ChinookDbContext>();
builder.Services.AddControllersWithViews();

builder.Services.AddLocalization();



var app = builder.Build();

var supportedCultures = new[] { new CultureInfo("en-US") };

app.UseRequestLocalization(
    new RequestLocalizationOptions
    {
        DefaultRequestCulture = new RequestCulture("en-US"),
        SupportedCultures = supportedCultures,
        FallBackToParentCultures = false
    }
);
CultureInfo.DefaultThreadCurrentCulture = CultureInfo.CreateSpecificCulture("en-US");

// Configure the HTTP request pipeline.
if (app.Environment.IsDevelopment())
{
    app.UseMigrationsEndPoint();
}
else
{
    app.UseExceptionHandler("/Home/Error");
    // The default HSTS value is 30 days. You may want to change this for production scenarios, see https://aka.ms/aspnetcore-hsts.
    app.UseHsts();
}



app.UseHttpsRedirection();
app.UseStaticFiles();

app.UseRouting();

app.UseAuthentication();
app.UseAuthorization();

app.MapControllerRoute(
    name: "default",
    pattern: "{controller=Home}/{action=Index}/{id?}");
app.MapRazorPages();

app.MapControllerRoute(
    name: "orderslist",
    pattern: "orders",
    defaults: new { controller = "Home", action = "MyOrders" }
);
app.MapControllerRoute(
    name: "order",
    pattern: "orders/{id}",
    defaults: new
    {
        controller = "Invoices", // Ró¿ni siê z racji na dodanie kontrolera do Invoice'ów.
        action = "Details"
    }
);


using (var scope = app.Services.CreateScope())
{
    using (var context =
           scope.ServiceProvider.GetService<ChinookDbContext>())
    {
        var userManager =
            scope.ServiceProvider.GetService<UserManager<ApplicationUser>>
                ();
        if (
            await userManager.FindByEmailAsync(
                context.Customers.OrderBy(x =>
                    x.CustomerId).First().Email) == null
        )
        {
            foreach (var item in context.Customers)
            {
                var user = new ApplicationUser
                {
                    UserName = item.Email,
                    NormalizedUserName = item.Email,
                    Email = item.Email,
                    NormalizedEmail = item.Email,
                    EmailConfirmed = true,
                    LockoutEnabled = false,
                    SecurityStamp = Guid.NewGuid().ToString(),
                    CustomerId = item.CustomerId
                };
                await userManager.CreateAsync(user,
                    "P@ssw0rd");
            }
        }
    }
}



app.Run();

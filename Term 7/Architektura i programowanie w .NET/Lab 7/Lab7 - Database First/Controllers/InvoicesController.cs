using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Lab7___Database_First.Areas.Identity.Data;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using Lab7___Database_First.Data;
using Lab7___Database_First.Models;
using Microsoft.AspNetCore.Identity;

namespace Lab7___Database_First.Controllers
{
    public class InvoicesController : Controller
    {
        private readonly ILogger<HomeController> _logger;
        private readonly ChinookDbContext _context;
        private readonly UserManager<ApplicationUser> _userManager;
        public InvoicesController(ILogger<HomeController> logger,
            ChinookDbContext chinook,
            UserManager<ApplicationUser> userManager)
        {
            _logger = logger;
            _context = chinook;
            _userManager = userManager;
        }

        // GET: Invoices
        public async Task<IActionResult> Index()
        {
            var user = await _userManager.GetUserAsync(User);
            var chinookDbContext = _context.Invoices.Include(i => i.Customer).Where(i => i.CustomerId == user.CustomerId);
            return View(await chinookDbContext.ToListAsync());
        }

        // GET: Invoices/Details/5
        public async Task<IActionResult> Details(long? id)
        {
            if (id == null || _context.Invoices == null)
            {
                return NotFound();
            }

            var user = await _userManager.GetUserAsync(User);
            var customerId = user.CustomerId;

            var invoice = _context.Invoices
                .Include(x => x.InvoiceLines)
                .ThenInclude(x => x.Track)
                .FirstOrDefault(x => x.InvoiceId == id);
            if (invoice == null)
            {
                return NotFound();
            }

            if (invoice.CustomerId != user.CustomerId)
            {
                return Forbid();
            }

            return View(invoice);
        }

        // GET: Invoices/Create
        public IActionResult Create()
        {
            ViewData["CustomerId"] = new SelectList(_context.Customers, "CustomerId", "CustomerId");
            return View();
        }

        // POST: Invoices/Create
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Create([Bind("InvoiceId,CustomerId,InvoiceDate,BillingAddress,BillingCity,BillingState,BillingCountry,BillingPostalCode,Total")] Invoice invoice)
        {
            if (ModelState.IsValid)
            {
                _context.Add(invoice);
                await _context.SaveChangesAsync();
                return RedirectToAction(nameof(Index));
            }
            ViewData["CustomerId"] = new SelectList(_context.Customers, "CustomerId", "CustomerId", invoice.CustomerId);
            return View(invoice);
        }

        // GET: Invoices/Edit/5
        public async Task<IActionResult> Edit(long? id)
        {
            if (id == null || _context.Invoices == null)
            {
                return NotFound();
            }

            var invoice = await _context.Invoices.FindAsync(id);
            if (invoice == null)
            {
                return NotFound();
            }
            ViewData["CustomerId"] = new SelectList(_context.Customers, "CustomerId", "CustomerId", invoice.CustomerId);
            return View(invoice);
        }

        // POST: Invoices/Edit/5
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Edit(long id, [Bind("InvoiceId,CustomerId,InvoiceDate,BillingAddress,BillingCity,BillingState,BillingCountry,BillingPostalCode,Total")] Invoice invoice)
        {
            if (id != invoice.InvoiceId)
            {
                return NotFound();
            }

            if (ModelState.IsValid)
            {
                try
                {
                    _context.Update(invoice);
                    await _context.SaveChangesAsync();
                }
                catch (DbUpdateConcurrencyException)
                {
                    if (!InvoiceExists(invoice.InvoiceId))
                    {
                        return NotFound();
                    }
                    else
                    {
                        throw;
                    }
                }
                return RedirectToAction(nameof(Index));
            }
            ViewData["CustomerId"] = new SelectList(_context.Customers, "CustomerId", "CustomerId", invoice.CustomerId);
            return View(invoice);
        }

        // GET: Invoices/Delete/5
        public async Task<IActionResult> Delete(long? id)
        {
            if (id == null || _context.Invoices == null)
            {
                return NotFound();
            }

            var invoice = await _context.Invoices
                .Include(i => i.Customer)
                .FirstOrDefaultAsync(m => m.InvoiceId == id);
            if (invoice == null)
            {
                return NotFound();
            }

            return View(invoice);
        }

        // POST: Invoices/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> DeleteConfirmed(long id)
        {
            if (_context.Invoices == null)
            {
                return Problem("Entity set 'ChinookDbContext.Invoices'  is null.");
            }
            var invoice = await _context.Invoices.FindAsync(id);
            if (invoice != null)
            {
                _context.Invoices.Remove(invoice);
            }
            
            await _context.SaveChangesAsync();
            return RedirectToAction(nameof(Index));
        }

        private bool InvoiceExists(long id)
        {
          return _context.Invoices.Any(e => e.InvoiceId == id);
        }
    }
}

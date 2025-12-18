using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using SistemaFuncionarios.Data;
using SistemaFuncionarios.Models;

namespace SistemaFuncionarios.Controllers
{
    public class FuncionarioController : Controller
    {
        private readonly AppDbContext _context;

        public FuncionarioController(AppDbContext context)
        {
            _context = context;
        }

        // GET: Funcionario
        public async Task<IActionResult> Index()
        {
            return View(await _context.TabelaFuncionarios.ToListAsync());
        }

        // GET: Funcionario/Details/5
        public async Task<IActionResult> Details(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var tabelaFuncionario = await _context.TabelaFuncionarios
                .FirstOrDefaultAsync(m => m.Id == id);
            if (tabelaFuncionario == null)
            {
                return NotFound();
            }

            return View(tabelaFuncionario);
        }

        // GET: Funcionario/Create
        public IActionResult Create()
        {
            return View();
        }

        // POST: Funcionario/Create
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Create([Bind("Id,Nome,SalarioBase,Cargo")] TabelaFuncionario tabelaFuncionario)
        {
            if (ModelState.IsValid)
            {
                _context.Add(tabelaFuncionario);
                await _context.SaveChangesAsync();
                return RedirectToAction(nameof(Index));
            }
            return View(tabelaFuncionario);
        }

        // GET: Funcionario/Edit/5
        public async Task<IActionResult> Edit(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var tabelaFuncionario = await _context.TabelaFuncionarios.FindAsync(id);
            if (tabelaFuncionario == null)
            {
                return NotFound();
            }
            return View(tabelaFuncionario);
        }

        // POST: Funcionario/Edit/5
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Edit(int id, [Bind("Id,Nome,SalarioBase,Cargo")] TabelaFuncionario tabelaFuncionario)
        {
            if (id != tabelaFuncionario.Id)
            {
                return NotFound();
            }

            if (ModelState.IsValid)
            {
                try
                {
                    _context.Update(tabelaFuncionario);
                    await _context.SaveChangesAsync();
                }
                catch (DbUpdateConcurrencyException)
                {
                    if (!TabelaFuncionarioExists(tabelaFuncionario.Id))
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
            return View(tabelaFuncionario);
        }

        // GET: Funcionario/Delete/5
        public async Task<IActionResult> Delete(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var tabelaFuncionario = await _context.TabelaFuncionarios
                .FirstOrDefaultAsync(m => m.Id == id);
            if (tabelaFuncionario == null)
            {
                return NotFound();
            }

            return View(tabelaFuncionario);
        }

        // POST: Funcionario/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> DeleteConfirmed(int id)
        {
            var tabelaFuncionario = await _context.TabelaFuncionarios.FindAsync(id);
            if (tabelaFuncionario != null)
            {
                _context.TabelaFuncionarios.Remove(tabelaFuncionario);
            }

            await _context.SaveChangesAsync();
            return RedirectToAction(nameof(Index));
        }

        private bool TabelaFuncionarioExists(int id)
        {
            return _context.TabelaFuncionarios.Any(e => e.Id == id);
        }
    }
}

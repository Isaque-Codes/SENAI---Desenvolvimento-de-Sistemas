using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using SistemaCursos.Data;
using SistemaCursos.Models;

namespace SistemaCursos.Controllers
{
    public class CursoController : Controller
    {
        private readonly AppDbContext _context;

        public CursoController(AppDbContext contextConstrutor)
        {
            _context = contextConstrutor;
        }

        //* Listar
        public async Task<IActionResult> Index()
        {
            var lista = await _context.TabelaCurso.ToListAsync();
            return View(lista);
        }

        [HttpGet]
        public IActionResult Criar() => View();

        //* Criar
        [HttpPost]
        public async Task<IActionResult> Criar(string nomeConstrutor, int horasConstrutor,
        string tipoCursoConstrutor)
        {
            Curso? novoCurso = null;
            if (tipoCursoConstrutor == "Tecnico")
            {
                novoCurso = new Tecnico(nomeConstrutor, horasConstrutor);
            }
            else if (tipoCursoConstrutor == "Superior")
            {
                novoCurso = new Superior(nomeConstrutor, horasConstrutor);
            }
            else
            {
                return BadRequest("Tipo de curso invalido.");
            }

            _context.TabelaCurso.Add(novoCurso);
            await _context.SaveChangesAsync();
            return RedirectToAction("Index");
        }

        //* Excluir
        public async Task<IActionResult> Deletar(int id)
        {
            var Curso = await _context.TabelaCurso.FindAsync(id);

            if (Curso == null)
            {
                return NotFound();
            }

            _context.TabelaCurso.Remove(Curso);
            await _context.SaveChangesAsync();
            return RedirectToAction("Index");
        }
    }
}
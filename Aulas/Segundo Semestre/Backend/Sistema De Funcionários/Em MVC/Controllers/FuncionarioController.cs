using System;
using System.Collections.Generic;
using System.ComponentModel.Design;
using System.Diagnostics;
using System.Linq;
using System.Security.Authentication;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Logging;

namespace Em_MVC.Controllers
{
    [Route("[controller]")]
    public class FuncionarioController : Controller
    {
        private readonly AppDbContext _context;

        public FuncionarioController(AppDbContext contextConstrutor)
        {
            _context = contextConstrutor;
        }

        //* ASYNC / AWAIT => Aguardar enquanto realiza outras tarefas
        public async Task<IActionResult> Index()
        {
            //* ToList - Lista as informacoes dentro da tabela funcionario
            var lista = await _context.TabelaFuncionario.ToListAsync();
            //* Retorna a view com a lista de funcionarios no index
            return View(lista);
        }

        //* Formulario de criacao - Retorna lista de formulario vazio
        [HttpGet] //* GET - Listar
        public IActionResult Criar() => View();

        //* Cadastrar - Cria as informacoes do formulario
        [HttpPost]
        public async Task<IActionResult> Criar(string NomeConstrutor,
        Double SalarioBaseConstrutor, string CargoConstrtor)
        {
            //? A interrogacao garante que o sistema aceite o funcionario caso esteja vazio
            Funcionario? novoFuncionario = null;

            if (CargoConstrtor == "Gerente")
            {
                novoFuncionario = new Gerente(NomeConstrutor, SalarioBaseConstrutor);
            }
            else if (CargoConstrutor == "Vendedor")
            {
                novoFuncionario = new Vendedor(NomeConstrutor, SalarioBaseConstrutor);
            }
            else
            {
                return BadRequest("Cargo invalido.");
            }

            _context.TabelaFuncionario.Add(novoFuncionario);
            await _context.SaveChangesAsync();

            return RedirectToAction("Index");
        }

        //* Excluir
        public async Task<IActionResult> Deletar(int id)
        {
            //* FindAsync => Busca pelo campo especificadoF
            var funcionario = await _context.TabelaFuncionario.FindAsync(id);
            if (funcionario == null)
            {
                return NotFound();
            }
            //? REMOVE registro do banco
            _context.TabelaFuncionario.Remove(Funcionario);
            await _context.SaveChangesAsync();
            return RedirectToAction("Index");
        }
    }
}
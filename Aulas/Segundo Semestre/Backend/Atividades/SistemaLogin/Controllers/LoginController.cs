using Sistema_Login.Data;
using Microsoft.AspNetCore.Mvc;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Microsoft.EntityFrameworkCore.Metadata.Internal;
using Microsoft.Identity.Client;
using Sistema_Login.Services;

namespace Sistema_Login.Controllers
{
    public class LoginController : Controller
    {
        private readonly AppDbContext _context;

        public LoginController(AppDbContext context) => _context = context;

        public IActionResult Index() => View();

        [HttpPost]
        public IActionResult Entrar(string email, string senha)
        {
            //* Se houverem espacos ou caracteres nulos
            if (string.IsNullOrWhiteSpace(email) || string.IsNullOrWhiteSpace(senha))
            {
                ViewBag.Erro = "Preencha todos os campos.";
                return View("Index");
            }

            //? Hash da senha digitada
            byte[] senhaDigitadaHash = HashService.GerarHashBytes(senha);

            //* Buscar usuario pelo email
            //? FirstOrDefault: procura usuario pelo email, RETORNA NULO SE NAO ENCONTRAR
            var usuario = _context.Usuarios.FirstOrDefault(usuario => usuario.Email == email);

            if (usuario == null)
            {
                ViewBag.Erro = "E-mail ou senha incorretos.";
                return View("Index");
            }

            //* Comparar byte a byte de senha
            //? SequenceEqual: Se encarrega da funcao de comparacao
            if (!usuario.SenhaHash.SequenceEqual(senhaDigitadaHash))
            {
                ViewBag.Erro = "E-mail ou senha incorretos.";
                return View("Index");
            }

            //* Se o login estiver correto, SALVA NA SESSAO
            HttpContext.Session.SetString("UsuarioNome", usuario.NomeCompleto);
            HttpContext.Session.SetInt32("UsuarioId", usuario.Id);

            //* Retorna para a index da HOME, nao da login
            return RedirectToAction("Index", "Home");
        }

        public IActionResult Sair()
        {
            HttpContext.Session.Clear();
            return RedirectToAction("Index");
        }
    }
}
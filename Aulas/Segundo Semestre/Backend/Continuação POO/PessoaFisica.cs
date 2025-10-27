using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Continuação_POO
{
    public class PessoaFisica : Pessoa
    {
        public string Cpf { get; set; } = string.Empty;

        public DateTime DataNascimento { get; set; }

        public override void PagarImposto()
        {
            Console.WriteLine($"Pessoa fisica: {Nome}, CPF: {Cpf} - pagando imposto (ou nao)...");
        }
    }
}
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Continuação_POO
{
    public class PessoaJuridica : Pessoa
    {
        public string Cnpj { get; set; } = string.Empty;

        public string RazaoSocial { get; set; } = string.Empty;

        public override void PagarImposto()
        {
            Console.WriteLine($"Pessoa juridica: {Nome}, CNPJ: {Cnpj} - pagando imposto (ou nao)...");
        }
    }
}
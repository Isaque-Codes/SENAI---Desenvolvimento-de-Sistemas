using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Introdução_POO
{
    public class Aluno : Pessoa
    {
        public String curso;

        public override void Apresentar()
        {
            Console.WriteLine("$Sou o aluno {nome}, tenho {idade} anos e estudo {curso}.");
        }
    }
}
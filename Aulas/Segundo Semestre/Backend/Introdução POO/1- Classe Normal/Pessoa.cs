using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Introdução_POO
{
    public class Pessoa
    {
        public string nome;

        public int idade;

        // Virtual: O metodo sera utilizado em outra classe, podendo ser sobrescrito
        public virtual void Apresentar()
        {
            Console.WriteLine("$Ola, meu nome eh {nome} e tenho {idade} anos.");
        }
    }
}
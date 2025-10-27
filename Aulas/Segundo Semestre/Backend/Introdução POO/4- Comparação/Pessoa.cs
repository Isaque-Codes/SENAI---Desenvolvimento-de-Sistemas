using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace _4__Comparação
{
    public class Pessoa
    {
        public string? Nome = null;

        public void falar() => Console.WriteLine($"{Nome} esta falando.");
    }
}
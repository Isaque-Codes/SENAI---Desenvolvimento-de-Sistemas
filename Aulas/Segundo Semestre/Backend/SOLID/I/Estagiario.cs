using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace I
{
    public class Estagiario : ITrabalhador
    {
        public void Trabalhar() => Console.WriteLine("Pegando cafe pro senior...");
    }
}
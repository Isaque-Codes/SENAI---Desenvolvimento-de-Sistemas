using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace _2__Classe_Abstrata
{
    public abstract class Forma
    {
        public abstract double CalcularArea();

        public void MostrarTipo()
        {
            Console.WriteLine("Sou uma forma geometrica.");
        }
    }
}
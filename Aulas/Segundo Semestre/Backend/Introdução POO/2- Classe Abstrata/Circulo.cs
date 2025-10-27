using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace _2__Classe_Abstrata
{
    public class Circulo : Forma
    {
        public double Raio;
        public override double CalcularArea() => Math.PI * Raio * Raio;
    }
}
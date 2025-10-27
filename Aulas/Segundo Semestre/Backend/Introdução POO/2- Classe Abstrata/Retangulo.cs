using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Threading.Tasks;

namespace _2__Classe_Abstrata
{
    public class Retangulo : Forma
    {
        public double Largura;
        public double Altura;
        public override double CalcularArea() => Largura * Altura;
    }
}
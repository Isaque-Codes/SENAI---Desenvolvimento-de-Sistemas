using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace O
{
    public class DescontoNatal : Desconto
    {
        public override double Calcular(double valor) => valor * 0.10;
    }
}
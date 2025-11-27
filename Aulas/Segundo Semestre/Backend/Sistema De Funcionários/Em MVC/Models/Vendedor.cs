using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Em_MVC.Models
{
    public class Vendedor : Funcionario
    {
        public Vendedor() { }

        public Vendedor(string NomeConstrutor, double SalarioBaseConstrutor)
        : base(NomeConstrutor, SalarioBaseConstrutor) { }

        public override double CalcularSalario() => SalarioBase * 1.2;
    }
}
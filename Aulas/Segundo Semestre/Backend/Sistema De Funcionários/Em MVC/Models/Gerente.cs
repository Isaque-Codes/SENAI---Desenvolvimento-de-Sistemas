using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Em_MVC.Models
{
    public class Gerente : Funcionario
    {
        public Gerente() { } //* Vazio para a criacao no banco de dados

        public Gerente(string NomeConstrutor, double SalarioBaseConstrutor)
        : base(NomeConstrutor, SalarioBaseConstrutor) { }

        public override double CalcularSalario() => SalarioBase * 1.5;
    }
}
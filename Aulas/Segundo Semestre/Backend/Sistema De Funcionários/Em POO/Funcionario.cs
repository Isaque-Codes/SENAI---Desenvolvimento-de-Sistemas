
using System.Diagnostics.Contracts;

namespace SistemaFuncionarios
{
    public abstract class Funcionario
    {
        public string Nome { get; set; } = string.Empty;
        public double SalarioBase { get; set; }

        public Funcionario(string NomeConstrutor, double SalarioBaseConstrutor)
        {
            Nome = NomeConstrutor;
            SalarioBase = SalarioBaseConstrutor;
        }

        public abstract double CalcularSalario();

        public virtual void ExibirResumo()
        {
            Console.WriteLine($"Funcionário: {Nome}");
            Console.WriteLine($"Salário base: R${SalarioBase:F2}");
            Console.WriteLine($"Salário Final: R${CalcularSalario():F2}");
        }

    }
}
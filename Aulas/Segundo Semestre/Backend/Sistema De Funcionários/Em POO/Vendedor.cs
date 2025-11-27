
namespace SistemaFuncionarios
{
    public class Vendedor : Funcionario
    {
        public Vendedor(string NomeConstrutor, double SalarioBaseConstrutor) : base(NomeConstrutor, SalarioBaseConstrutor) { }

        public override double CalcularSalario()
        {
            return SalarioBase * 1.2; // 20% de bonus
        }
    }
}
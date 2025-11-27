namespace SistemaFuncionarios;

class Program
{
    static void Main(string[] args)
    {
        List<Funcionario> funcionarios = new List<Funcionario>
        {
            new Gerente("Késsia", 5000),
            new Vendedor("Thiago", 3000)
        };

        // Console.WriteLine(funcionarios[1]);

        foreach (var funcionario in funcionarios)
        {
            funcionario.ExibirResumo();
        }
    }
}
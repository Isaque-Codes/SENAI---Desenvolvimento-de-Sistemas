using System.Reflection;

namespace Backend_C_; // Para diferenciar classes com mesmo nome

class Program
{
    static void Main(string[] args)
    {
        Console.WriteLine("Bem vindo ao sistema!");

        // Entrada de Dados

        Console.WriteLine("Digite seu nome.");
        string nome = Console.ReadLine();

        Console.WriteLine("Digite sua idade.");
        int idade = int.Parse(Console.ReadLine());

        Console.WriteLine($"\nOla, {nome}! Voce tem {idade} anos.");

        if (idade < 18)
        {
            Console.WriteLine("Voce ainda eh menor de idade.");
        }
        else
        {
            Console.WriteLine("Voce ja eh maior de idade.");
        }

        // Menu
        int opcao = 0;
        do
        {
            Console.WriteLine("\nEscolha uma opcao");
            Console.WriteLine("1: Ver a tabuada de um numero");
            Console.WriteLine("2: Contar ate determinado numero");
            Console.WriteLine("3: Sair");
            Console.WriteLine("4: Ver determinados ciclos da sequencia fibonacci");
            Console.WriteLine("Digite a sua opcao");

            opcao = int.Parse(Console.ReadLine());

            switch (opcao)
            {
                case 1:
                    Console.WriteLine("Insira o numero a ser multiplicado");
                    int multiplicando = int.Parse(Console.ReadLine());
                    Console.WriteLine("Ate qual numero voce deseja que o numero escolhido seja multiplicado?");
                    int multiplicador = int.Parse(Console.ReadLine());

                    for (int i = 1; i <= multiplicador; i++)
                    {
                        int produto = multiplicando * i;
                        Console.WriteLine($"\n{multiplicando} vezes {i} eh igual a: {produto}");
                    }
                    break;

                case 2:
                    Console.WriteLine("Ate qual numero voce deseja contar?");
                    int contador = int.Parse(Console.ReadLine());

                    for (int i = 1; i <= contador; i++)
                    {
                        Console.WriteLine($"Contando: {i}");
                    }
                    break;

                case 3:
                    Console.WriteLine("Ate a proxima!");
                    break;

                case 4:
                    Console.WriteLine("Quantos ciclos voce deseja ver?");
                    int repeticoes = int.Parse(Console.ReadLine());

                    ulong numeroAnterior = 0;
                    ulong numeroAtual = 1;
                    ulong proximoNumero = 0;
                    for (int i = 1; i <= repeticoes; i++)
                    {
                        Console.WriteLine($"Ciclo {i}: {numeroAtual}");
                        proximoNumero = numeroAnterior + numeroAtual;
                        numeroAnterior = numeroAtual;
                        numeroAtual = proximoNumero;
                    }
                    break;

                default:
                    Console.WriteLine("Por favor, escolha uma das opcoes validas.");
                    break;
            }
        }
        while (opcao != 3);
    }
}
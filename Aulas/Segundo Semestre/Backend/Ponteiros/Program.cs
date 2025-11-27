namespace Ponteiros;

class Program
{
    // UNSAFE: Usado por Conta do Acesso aos Ponteiros (Enderecos de Memoria)
    static unsafe void Main(string[] args)
    {
        int variavelA = 10;
        Console.WriteLine($"Variavel: {variavelA}");

        // (Variavel*): O ASTERISTICO eh usado para manipular ponteiros
        int* ponteiro = &variavelA;
        // CASTING: Modifica Tipo de Variavel (com ULONG)
        Console.WriteLine($"Endereco da memoria: {(ulong)ponteiro}");

        *ponteiro = 75;
        Console.WriteLine($"Novo valor da variavel A: {variavelA}");

        int[] numeros = { 10, 20, 30, 40 };

        // FIXED: Impede a movimentacao na memoria
        fixed (int* pArray = numeros)
        {
            Console.WriteLine($"Endereco do array: {(ulong)pArray}");
            Console.WriteLine($"pArray [0] {*(pArray)}");
            Console.WriteLine($"pArray [1] {*(pArray + 1)}");
            Console.WriteLine($"pArray [2] {*(pArray + 2)}");
            Console.WriteLine($"pArray [3] {*(pArray + 3)}");
            Console.WriteLine($"pArray [?] {*(pArray + 4)}");
        }
    }
}

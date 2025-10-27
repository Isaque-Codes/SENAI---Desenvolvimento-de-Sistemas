namespace O;

class Program
{
    static void Main(string[] args)
    {
        Desconto d1 = new DescontoNatal();
        Desconto d2 = new DescontoBlackFraude();

        // :C OU .ToString("C") trazem o formato monetario do sistema
        Console.WriteLine($"Valor com desconto de natal: {d1.Calcular(1000)}:C");
        Console.WriteLine($"Valor com desconto de black fraude: {d2.Calcular(1000).ToString("C")}");
        Console.WriteLine($"Valor black fraude em outro formato: {d2.Calcular(1000)}");
    }
}
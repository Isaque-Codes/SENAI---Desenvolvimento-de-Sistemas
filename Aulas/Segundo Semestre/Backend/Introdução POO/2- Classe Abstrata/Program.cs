using System.Reflection;

namespace _2__Classe_Abstrata;

class Program
{
    static void Main(string[] args)
    {
        Retangulo r = new Retangulo { Largura = 5, Altura = 5 };
        Circulo c = new Circulo { Raio = 3 };

        r.MostrarTipo(); Console.WriteLine($"Area do retangulo: {r.CalcularArea()}");
        c.MostrarTipo(); Console.WriteLine($"Area do circulo: {c.CalcularArea()}");
    }
}

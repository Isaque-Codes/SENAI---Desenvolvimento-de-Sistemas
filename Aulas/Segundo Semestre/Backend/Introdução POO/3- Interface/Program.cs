using System.Net.Http.Headers;

namespace _3__Interface;

class Program
{
    static void Main(string[] args)
    {
        Cachorro c = new Cachorro();
        // (Cachorro c) = IAnimal c
        Gato g = new Gato();
        // (Gato g) = IAnimal g

        c.EmitirSom();
        g.EmitirSom();
    }
}

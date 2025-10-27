using System.Reflection;

namespace L;

class Program
{
    static void Main(string[] args)
    {
        Ave a1 = new Andorinha();
        Ave a2 = new Pinguim();

        a1.Mover();
        a2.Mover();

        a1.Dormir();
        a2.Dormir();
    }
}
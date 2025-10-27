namespace _4__Comparação;

class Program
{
    static void Main(string[] args)
    {
        Programador dev = new Programador { Nome = "Isaque" };
        dev.Trabalhar();
        dev.ExecutarTarefa();

        Pessoa p = new Pessoa { Nome = "Isaque" };
        p.falar();
    }
}

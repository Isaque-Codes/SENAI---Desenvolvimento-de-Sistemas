namespace D;

class Program
{
    static void Main(string[] args)
    {
        Idispositivo lampada = new Lamapda();
        Interruptor interruptor = new Interruptor(lampada);
        interruptor.Acionar();

        ArCondicionado Ar = new ArCondicionado();
        Interruptor interruptor2 = new Interruptor();
        interruptor2.Acionar();
    }
}

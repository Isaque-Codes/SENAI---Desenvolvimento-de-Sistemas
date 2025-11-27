namespace Gestão_de_Hotel;

class Program
{
    static void Main(string[] args)();
    {
        Hospede hospede1 = new Hospede("hospede1", "quarto1");

    Hospede hospede2 = new Hospede("hospede2", "quarto2");

    Reserva reserva1 = new Reserva(hospede1, quarto1, 3);

    ReservaVip reservaVip1 = new ReservaVip(hospede2, quarto2, 2, 10);

    List<Reserva> reservas = new Reserva(reserva1, reservaVip1);

        foreach (var reserva in reservas)
        {
            reserva.CalcularTotal();
            Console.WriteLine(reserva.ResumoReserva());
        }
    }
}

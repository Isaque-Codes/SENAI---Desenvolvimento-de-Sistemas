
using System.Runtime.InteropServices;

namespace Gestão_de_Hotel
{
    public class ReservaVip : Reserva
    {
        public double Desconto { get; set; }

        public ReservaVip(Hospede HospedeConstrutor, Quarto QuartoConstrutor, int DiasConstrutor, double DescontoConstrutor) : base(HospedeConstrutor, QuartoConstrutor, DiasConstrutor)
        {
            Desconto = DescontoConstrutor;
        }

        public override double CalcularTotal()
        {
            double ValorSemDesconto = QuartoReserva.PrecoDiaria * Dias;
            double ValorComDesconto = ValorSemDesconto * (1 - (Desconto / 100));
            return ValorComDesconto;
        }

        public override string ResumoReserva()
        {
            return
                    $"Reserva VIP de {HospedeReserva.Nome}\n Quarto: {QuartoReserva.Numero} ({QuartoReserva.Tipo})\n Desconto aplicado: {Desconto}%\n Valor total: R${CalcularTotal():F2}";
        }
    }
}
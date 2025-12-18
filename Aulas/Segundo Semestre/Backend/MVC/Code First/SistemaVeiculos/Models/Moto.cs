using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace SistemaVeiculos.Models
{
    public class Moto : Veiculo
    {
        public Moto() { }

        public Moto(string ModeloConstrutor, int AnoConstrutor)
        : base(ModeloConstrutor, AnoConstrutor) { }

        public override void CalcularRevisao()
        {
            ValorRevisao = 300.00m;
        }
    }
}
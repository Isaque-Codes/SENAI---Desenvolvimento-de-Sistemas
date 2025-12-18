using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace SistemaVeiculos.Models
{
    public class Carro : Veiculo
    {
        public Carro() { }

        public Carro(string ModeloConstrutor, int AnoConstrutor)
        : base(ModeloConstrutor, AnoConstrutor) { }

        public override void CalcularRevisao()
        {
            ValorRevisao = 500.00m;
        }
    }
}
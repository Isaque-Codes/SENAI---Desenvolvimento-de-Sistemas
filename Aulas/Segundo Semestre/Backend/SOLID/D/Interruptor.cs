using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace D
{
    public class Interruptor
    {
        // ------------------------ JEITO CERTO ------------------------------
        // Variavel criada como dispositivo
        private readonly IDispositivo dispositivo;

        public Interruptor(IDispositivo dispositivo)
        {
            // O THIS serve para o sistema nao confundir variaveis iguais.
            // Tambem poderia ser (...) = _dispositivo
            this.dispositivo = dispositivo;
        }

        public void Acionar() => dispositivo.ligarLampada();

        // ------------------------ JEITO ERRADO -----------------------------
        private ArCondicionado Ar;

        public InterruptorAr()
        {
            Ar = new ArCondicionado();
        }


        public void AcionarAr() => Ar.LigarAr();
    }
}
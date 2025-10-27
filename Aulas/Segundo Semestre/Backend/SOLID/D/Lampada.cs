using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace D
{
    public class Lampada : IDispositivo
    {
        public void LigarLampada() => Console.WriteLine("Lampada ligada!");
    }
}
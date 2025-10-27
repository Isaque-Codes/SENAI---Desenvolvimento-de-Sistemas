using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace L
{
    public abstract class Ave
    {
        public abstract void Mover();

        public void Dormir() => Console.WriteLine("Dormindo...");
    }
}
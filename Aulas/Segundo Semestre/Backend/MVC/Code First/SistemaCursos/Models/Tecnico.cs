using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace SistemaCursos.Models
{
    public class Tecnico : Curso
    {
        public Tecnico() { }

        public Tecnico(string nomeConstrutor, int horasConstrutor)
        : base(nomeConstrutor, horasConstrutor) { }

        public override double CalcularPreco()
        {
            return Horas * 20;
        }
    }
}
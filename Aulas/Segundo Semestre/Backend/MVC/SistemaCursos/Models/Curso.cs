using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Threading.Tasks;

namespace SistemaCursos.Models
{
    public abstract class Curso
    {
        [Key]
        public int Id { get; set; }

        [Required]
        public string Nome { get; set; } = string.Empty;

        public int Horas { get; set; }

        public Curso() { }

        public Curso(string nomeConstrutor, int horasConstrutor)
        {
            Nome = nomeConstrutor;
            Horas = horasConstrutor;
        }

        public abstract double CalcularPreco();
    }
}
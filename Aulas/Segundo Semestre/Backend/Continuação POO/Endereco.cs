using System;
using System.Collections.Generic;
using System.Dynamic;
using System.Linq;
using System.Threading.Tasks;

namespace Continuação_POO
{
    public class Endereco
    {
        public string Rua { get; set; } = string.Empty;

        public int Numero { get; set; }

        public string Cidade { get; set; } = string.Empty;

        public string Estado { get; set; } = string.Empty;

        public string Cep { get; set; } = string.Empty;

        public string Complemento { get; set; } = string.Empty;

        public bool Comercial { get; set; }
    }
}
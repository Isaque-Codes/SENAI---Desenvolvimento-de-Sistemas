using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Continuação_POO
{
    public abstract class Pessoa
    {
        public string Nome { get; set; } = string.Empty;

        public List<Endereco> Enderecos { get; } = new List<Endereco>();

        public abstract void PagarImposto();

        public void AdicionarEndereco(Endereco parametro_endereco)
        {
            Enderecos.Add(parametro_endereco);
        }
    }
}
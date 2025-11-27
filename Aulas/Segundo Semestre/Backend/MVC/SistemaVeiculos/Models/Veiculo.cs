using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Threading.Tasks;
using System.ComponentModel.DataAnnotations.Schema;


namespace SistemaVeiculos.Models
{
    public abstract class Veiculo
    {
        [Key]
        public int Id { get; set; }

        [Required]
        public string Modelo { get; set; }

        [Range(1900, 2040)]
        public int Ano { get; set; }

        [Column(TypeName = "decimal(5, 2)")]
        public decimal? ValorRevisao { get; set; }

        public Veiculo() { }

        public Veiculo(string ModeloConstrutor, int AnoConstrutor)
        {
            Modelo = ModeloConstrutor;
            Ano = AnoConstrutor;
        }

        public abstract void CalcularRevisao();

        public virtual void ExibirResumo()
        {
            Console.WriteLine($"\nInformações do Veículo {Modelo}:\nAno: {Ano}.\nValor da revisão: {ValorRevisao:C}");
        }
    }
}
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using Microsoft.EntityFrameworkCore;

namespace SistemaFuncionarios.Models;

[Table("TabelaFuncionario")]
public partial class TabelaFuncionario
{
    [Key]
    public int Id { get; set; }

    [StringLength(120)]
    public string Nome { get; set; } = null!;

    [Column(TypeName = "decimal(10, 2)")]
    public decimal SalarioBase { get; set; }

    [StringLength(30)]
    public string Cargo { get; set; } = null!;
}

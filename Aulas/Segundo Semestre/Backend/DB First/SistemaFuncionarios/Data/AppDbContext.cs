using System;
using System.Collections.Generic;
using Microsoft.EntityFrameworkCore;
using SistemaFuncionarios.Models;

namespace SistemaFuncionarios.Data;

public partial class AppDbContext : DbContext
{
    public AppDbContext(DbContextOptions<AppDbContext> options)
        : base(options)
    {
    }

    public virtual DbSet<TabelaFuncionario> TabelaFuncionarios { get; set; }

    protected override void OnModelCreating(ModelBuilder modelBuilder)
    {
        OnModelCreatingPartial(modelBuilder);
    }

    partial void OnModelCreatingPartial(ModelBuilder modelBuilder);
}

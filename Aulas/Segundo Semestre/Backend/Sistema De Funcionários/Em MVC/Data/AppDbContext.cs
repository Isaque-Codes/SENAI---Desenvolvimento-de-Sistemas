using Microsoft.EntityFrameworkCore;
using SistemaFuncionariosMVC.Models;

namespace Em_MVC.Data
{
    public class AppDbContext : DbContext
    {
        //? Recebe as opcoes de configuracao do banco
        public AppDbContext(DbContextOptions<AppDbContext> options) : base(options) { }

        public DbSet<Funcionario> TabelaFuncionario { get; set; }

        //? Ajuste para uso da mesma tabela para 3 models no banco de dados
        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            //? Inicia configuracao da classe base
            modelBuilder.Entity<Funcionario>()

            //? Cria tabela unica diferenciando por cargo
            .HasDiscriminator<string>("Cargo")

            .HasValue<Gerente>("Gerente") //* If instancia == Gerente, cargo = Gerente

            .HasValue<Vendedor>("Vendedor"); //* If instancia == Vendedor, cargo = vendedor
        }
    }
}
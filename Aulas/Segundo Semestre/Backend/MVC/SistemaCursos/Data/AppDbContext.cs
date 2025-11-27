using SistemaCursos.Models;
using Microsoft.EntityFrameworkCore;

namespace SistemaCursos.Data
{
    public class AppDbContext : DbContext
    {
        public AppDbContext(DbContextOptions<AppDbContext> options) : base(options) { }

        public DbSet<Curso> TabelaCurso { get; set; }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            modelBuilder.Entity<Curso>()
            .HasDiscriminator<string>("Tipo")
            .HasValue<Tecnico>("Tecnico")
            .HasValue<Superior>("Superior");
        }
    }
}
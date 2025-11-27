using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Atividade_POO
{
    public class Livro
    {
        public string Titulo { get; set; }
        public string Autor { get; set; }
        public int AnoPublicacao { get; set; }
        /*{
            get
            {
                return AnoPublicacao;
            }
            set
            {
                if (value > 0)
                {
                    AnoPublicacao = value;
                }
                else
                {
                    Console.WriteLine("Ano de publicacao invalido.");
                }
            }
        }*/
        public double Preco { get; set; }
        public bool Disponibilidade { get; set; } = true;

        //* CONSTRUTOR
        //? METODO usado para INICIALIZAR OBJETO

        public Livro(
            string TituloConstrutor,
            string autorConstrutor,
            int anoConstrutor,
            double precoConstrutor
        )
        {
            Titulo = TituloConstrutor;
            Autor = autorConstrutor;
            AnoPublicacao = anoConstrutor;
            Preco = precoConstrutor;
            Disponibilidade = true;
            Console.WriteLine($"Novo livro: {TituloConstrutor} criado e disponivel.");
        }
        public void ExibirDetalhes()
        {
            Console.WriteLine("\n*** DETALHES DO LIVRO ***");
            Console.WriteLine($"Titulo: {Titulo}.");
            Console.WriteLine($"Autor: {Autor}.");
            Console.WriteLine($"Ano de publicacao: {AnoPublicacao}.");
            Console.WriteLine($"Preco: {Preco:F2}."); //* F2 FORMATA com 2 CASAS DECIMAIS

            if (Disponibilidade)
            {
                Console.WriteLine("Status: Disponivel para emprestimo.");
            }
            else
            {
                Console.WriteLine("Status: Indisponivel, em uso.");
            }
        }
        public void Emprestar()
        {
            if (Disponibilidade)
            {
                Disponibilidade = false;
                Console.WriteLine($"Voce recebeu o livro {Titulo} emprestado.");
            }
            else
            {
                Console.WriteLine($"O livro {Titulo} ja foi emprestado.");
            }
        }
    }
}
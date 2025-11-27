namespace Atividade_POO;

class Program
{
    static void Main(string[] args)
    {
        //? COM CONSTRUTOR
        Console.WriteLine("*** SISTEMA DE CONTROLE DE BIBLIOTECA ***");
        Livro livro1 = new Livro("A arte da guerra", "Sun Tzu", 1950, 45.90);
        Livro livro2 = new Livro("Dom Casmurro", "Machado de Assis", 1899, 79.99);

        //? Interacao com os livros: Emprestar / Ver detalhes
        Console.WriteLine("\nInteragindo com o livro 1.");
        livro1.ExibirDetalhes();
        livro1.Emprestar();
        livro1.ExibirDetalhes();
        livro1.Emprestar();

        Console.WriteLine("\nInteragindo com o livro 2.");
        livro2.ExibirDetalhes();
        livro2.Preco = 32.99;
        Console.WriteLine($"Atualizacao de preco: {livro2.Titulo} ajustado para: R$ {livro2.Preco:F2}");
        livro2.ExibirDetalhes();

        //! SEM CONSTRUTOR
        /*Livro Livro = new Livro();
        Console.WriteLine($"Titulo: {Livro.Titulo}");
        Console.WriteLine($"Ano: {Livro.AnoPublicacao}");
        Console.WriteLine($"Disponibilidade: {Livro.Disponibilidade}");

        //! Injetando valores manualmente
        Livro.Titulo = "O poder do construtor";
        Livro.Autor = "Parceiro de programacao";
        Livro.AnoPublicacao = 2025;
        Livro.Preco = 57.99;
        Livro.Disponibilidade = true;

        Console.WriteLine("Exibindo detalhes: ");
        Livro.ExibirDetalhes();*/
    }
}
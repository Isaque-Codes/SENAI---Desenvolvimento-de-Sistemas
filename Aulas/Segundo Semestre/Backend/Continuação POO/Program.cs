namespace Continuação_POO;

class Program
{
    static void Main(string[] args)
    {
        PessoaFisica pf = new PessoaFisica
        {
            Nome = "Ana Sousa",
            Cpf = "111.111.111-11",
            DataNascimento = new DateTime(1995, 4, 12)
        };

        pf.AdicionarEndereco(new Endereco
        {
            Rua = "Rua do caldeirao",
            Numero = 100,
            Cidade = "Sao Paulo",
            Estado = "SP",
            Cep = "01000 000",
            Comercial = false
        });

        PessoaJuridica pj = new PessoaJuridica
        {
            Nome = "Osvaldo Roberson",
            RazaoSocial = "Loja Exemplo LTDA",
            Cnpj = "12.134.156/0789-90"
        };

        pj.AdicionarEndereco(new Endereco
        {
            Rua = "Alameda das flores",
            Numero = 302,
            Cidade = "Campinas",
            Estado = "SP",
            Cep = "13000-000",
            Comercial = true
        });

        pf.PagarImposto();
        pj.PagarImposto();
    }
}

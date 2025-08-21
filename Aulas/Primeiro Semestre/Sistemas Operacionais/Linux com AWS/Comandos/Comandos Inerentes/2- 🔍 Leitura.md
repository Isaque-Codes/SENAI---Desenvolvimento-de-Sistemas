
| Comando                         | Descrição                                                                                                             | Exemplo                 |
| ------------------------------- | --------------------------------------------------------------------------------------------------------------------- | ----------------------- |
| `ls [opção] [arquivo ou pasta]` | Lista arquivos e diretórios no diretório atual ou especificado. Suporta múltiplas opções para personalização.         | `ls /home/usuario/docs` |
| `ls [nome da pasta]`            | Lista o conteúdo de uma pasta específica.  <br>- Pressione `Tab` duas vezes para autocompletar nomes de pastas.       | `ls documentos`         |
| `ls --help`                     | Exibe a documentação completa do comando `ls`, incluindo todas as opções disponíveis.                                 | `ls --help`             |
| `ls -1`                         | Lista arquivos em uma única coluna, útil para scripts ou saídas limpas.                                               | `ls -1`                 |
| `ls -l`                         | Exibe detalhes dos arquivos, como permissões, proprietário, grupo, tamanho e data de modificação.                     | `ls -l`                 |
| `ls -a`                         | Inclui arquivos ocultos (iniciados com `.`) na listagem, como `.bashrc`.                                              | `ls -a`                 |
| `ls -r`                         | Lista arquivos em ordem inversa (alfabética descendente).                                                             | `ls -r`                 |
| `ls -t`                         | Ordena arquivos por data de modificação, do mais recente ao mais antigo.                                              | `ls -t`                 |
| `ls -S`                         | Ordena arquivos por tamanho, do maior ao menor.                                                                       | `ls -S`                 |
| `ls -h`                         | Exibe tamanhos de arquivos em formato legível (ex.: KB, MB) quando usado com `-l`.                                    | `ls -lh`                |
| `ls -R`                         | Lista diretórios recursivamente, incluindo o conteúdo de subdiretórios.                                               | `ls -R /home/usuario`   |
| `ls [-lah / -lha / -alh]`       | Combina opções populares: `-l` (detalhado), `-a` (ocultos), `-h` (tamanhos legíveis).                                 | `ls -lah`               |
| `wc [opção] [arquivo]`          | Conta linhas, palavras ou caracteres em um arquivo.  <br>- Opções: `-l` (linhas), `-w` (palavras), `-c` (caracteres). | `wc -l texto.txt`       |
| `clear`                         | Limpa a tela do terminal, removendo todo o conteúdo visível.                                                          | `clear`                 |

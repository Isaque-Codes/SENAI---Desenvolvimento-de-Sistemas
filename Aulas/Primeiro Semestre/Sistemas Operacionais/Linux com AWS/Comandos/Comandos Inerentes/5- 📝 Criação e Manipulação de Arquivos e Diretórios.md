
| Comando                    | Descrição                                                                                        | Exemplo                                              |
| -------------------------- | ------------------------------------------------------------------------------------------------ | ---------------------------------------------------- |
| `mkdir [nome da pasta]`    | Cria um novo diretório com o nome especificado.                                                  | `mkdir documentos`                                   |
| `mkdir -p [caminho/pasta]` | Cria um diretório e seus pais, se necessário (ex.: cria `/a/b/c` mesmo que `/a/b` não exista).   | `mkdir -p projetos/novo/subpasta`                    |
| `touch [texto.txt]`        | Cria um arquivo vazio ou atualiza a data de modificação de um existente.                         | `touch nota.txt`                                     |
| `nano [texto.txt]`         | Abre o editor `nano` para criar ou editar um arquivo de texto. Salvar: `Ctrl+O`, Sair: `Ctrl+X`. | `nano nota.txt`                                      |
| `cat [texto.txt]`          | Exibe o conteúdo de um arquivo no terminal.                                                      | `cat nota.txt`                                       |
| `less [texto.txt]`         | Visualiza um arquivo página por página, ideal para arquivos grandes. Sair: `q`.                  | `less log.txt`                                       |
| `mv texto.txt texto2.txt`  | Renomeia um arquivo (ex.: de `texto.txt` para `texto2.txt`).                                     | `mv nota.txt nota2.txt`                              |
| `mv [/X/Y/Z/] [/A/B/Z2/]`  | Move e renomeia um arquivo ou diretório para outro local.                                        | `mv /home/docs/relatorio.pdf /backup/relatorio2.pdf` |
| `mv [/X/Y/Z/] [/A/B/]`     | Move um arquivo ou diretório para outro diretório sem renomear.                                  | `mv documento.txt backups/`                          |
| `mv -i [/X/Y/Z/] [/A/B/]`  | Move com confirmação interativa, evitando sobrescrever arquivos existentes.                      | `mv -i documento.txt backups/`                       |

### Notas Úteis

- **Cuidado com `mv`**: Sem `-i`, `mv` sobrescreve arquivos sem aviso. Use `mv -i` para confirmação.
- **Visualização com `less`**: Melhor que `cat` para arquivos longos, pois permite navegar com setas e buscar com `/`.
- **Atalhos do `nano`**: Use `Ctrl+O` para salvar, `Ctrl+X` para sair, e `Ctrl+W` para buscar texto.
- **Saiba mais**: Consulte `man mkdir`, `man nano`, `man cat`, `man less`, ou `man mv` para detalhes.
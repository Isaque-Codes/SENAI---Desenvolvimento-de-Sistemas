
| Comando                      | Descrição                                                                                                              | Exemplo                               |
| ---------------------------- | ---------------------------------------------------------------------------------------------------------------------- | ------------------------------------- |
| `rm [nome]`                  | Remove arquivos especificados.                                                                                         | `rm arquivo.txt`                      |
| `rm -i [nome]`               | Remove arquivos com confirmação interativa, pedindo confirmação para cada arquivo.                                     | `rm -i *.txt`                         |
| `rmdir [nome]`               | Remove diretórios vazios.                                                                                              | `rmdir pasta_vazia`                   |
| `rm -rf [diretório]`         | Remove um diretório e todo seu conteúdo recursivamente (`-r`) e sem confirmação (`-f`). Use com cuidado!               | `rm -rf temp/`                        |
| `cp [/X/Y/Z] [/A/B/Z2].bkp`  | Copia um arquivo ou diretório para outro local, opcionalmente com novo nome.                                           | `cp documento.txt backups/doc.bkp`    |
| `cp -r [/X/Y/Z] [/A/B/]`     | Copia um diretório e seu conteúdo recursivamente.                                                                      | `cp -r docs/ backups/docs/`           |
| `rsync -av [/X/Y/Z] [/A/B/]` | Copia arquivos/diretórios com sincronização, preservando permissões e estrutura (opções `-a`: arquivo, `-v`: verboso). | `rsync -av projeto/ backups/projeto/` |

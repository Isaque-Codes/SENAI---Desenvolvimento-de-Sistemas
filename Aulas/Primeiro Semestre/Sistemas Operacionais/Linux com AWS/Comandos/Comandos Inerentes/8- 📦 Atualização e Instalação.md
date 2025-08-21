
| Comando                                          | Descrição                                                                                       | Exemplo                                          |
| ------------------------------------------------ | ----------------------------------------------------------------------------------------------- | ------------------------------------------------ |
| `apt-get update`                                 | Atualiza a lista de pacotes disponíveis nos repositórios.                                       | `apt-get update`                                 |
| `sudo apt-get upgrade`                           | Atualiza todos os pacotes instalados para suas versões mais recentes, sem alterar dependências. | `sudo apt-get upgrade`                           |
| `sudo apt-get update && sudo apt-get upgrade -y` | Combina atualização da lista e dos pacotes, com `-y` para aceitar prompts automaticamente.      | `sudo apt-get update && sudo apt-get upgrade -y` |
| `sudo apt-get install [pacote]`                  | Instala um pacote específico, como o servidor web Apache2.                                      | `sudo apt-get install apache2`                   |
| `sudo apt-get remove [pacote]`                   | Remove um pacote, mantendo seus arquivos de configuração.                                       | `sudo apt-get remove apache2`                    |
| `sudo apt-get purge [pacote]`                    | Remove um pacote e seus arquivos de configuração.                                               | `sudo apt-get purge apache2`                     |
| `sudo apt-get autoremove`                        | Remove dependências não mais necessárias após desinstalações.                                   | `sudo apt-get autoremove`                        |
| `sudo apt-get dist-upgrade`                      | Atualiza pacotes, incluindo mudanças em dependências, para versões mais recentes.               | `sudo apt-get dist-upgrade`                      |
| `apt-cache search [termo]`                       | Busca pacotes disponíveis nos repositórios que correspondem ao termo.                           | `apt-cache search python`                        |

### Notas Úteis

- **Ordem dos comandos**: Sempre execute `apt-get update` antes de `upgrade` ou `install` para garantir uma lista de pacotes atualizada.
- **Cuidado com `dist-upgrade`**: Pode instalar ou remover dependências, o que pode afetar o sistema; revise as mudanças propostas.
- **Limpeza com `autoremove`**: Use após remover pacotes para liberar espaço.
- **Saiba mais**: Consulte `man apt-get` ou `man apt-cache` para detalhes.
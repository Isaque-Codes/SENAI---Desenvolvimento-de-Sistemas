
| Comando                                       | Descrição                                                                                  | Exemplo                                      |
| --------------------------------------------- | ------------------------------------------------------------------------------------------ | -------------------------------------------- |
| `sudo adduser [nome do usuário]`              | Cria um novo usuário interativamente, configurando senha e detalhes (ex.: nome completo).  | `sudo adduser joao`                          |
| `sudo useradd -m -G [grupo] [usuário]`        | Cria um usuário com diretório home (`-m`) e adiciona a um grupo (`-G`), sem senha inicial. | `sudo useradd -m -G developers ana`          |
| `sudo passwd [usuário]`                       | Define ou altera a senha de um usuário.                                                    | `sudo passwd joao`                           |
| `sudo addgroup [nome do grupo]`               | Cria um novo grupo no sistema.                                                             | `sudo addgroup equipe`                       |
| `sudo usermod -aG [grupo] [usuário]`          | Adiciona um usuário a um grupo adicional (`-aG` evita remover de outros grupos).           | `sudo usermod -aG equipe joao`               |
| `getent group`                                | Lista todos os grupos do sistema, incluindo seus membros.                                  | `getent group`                               |
| `groups [usuário]`                            | Mostra os grupos aos quais um usuário pertence.                                            | `groups joao`                                |
| `sudo groupmod -n [novo nome] [nome antigo]`  | Renomeia um grupo existente.                                                               | `sudo groupmod -n dev equipe`                |
| `sudo chown -R [usuário] [diretório]`         | Altera o proprietário (usuário) de um diretório e seu conteúdo (`-R`).                     | `sudo chown -R joao /var/www/projeto`        |
| `sudo chown -R [usuário]:[grupo] [diretório]` | Altera usuário e grupo proprietários de um diretório e seu conteúdo (`-R`).                | `sudo chown -R joao:equipe /var/www/projeto` |
| `sudo chmod XXX [nome da pasta]`              | Define permissões numéricas (ex.: `755` para `rwxr-xr-x`) para um diretório.               | `sudo chmod 755 /var/www/projeto`            |
| `sudo chgrp -R [grupo] [pasta]`               | Altera o grupo proprietário de um diretório, com `-R` para conteúdo recursivo.             | `sudo chgrp -R equipe /var/www/projeto`      |
| `sudo deluser [usuário]`                      | Remove um usuário, com opção `--remove-home` para excluir o diretório home.                | `sudo deluser --remove-home ana`             |
| `sudo delgroup [grupo]`                       | Remove um grupo, desde que não seja o grupo primário de um usuário.                        | `sudo delgroup equipe`                       |

### Notas Úteis

- **Cuidado com `chmod` e `chown`**: Alterar permissões ou proprietários em diretórios críticos (ex.: `/etc`) pode causar problemas no sistema. Sempre verifique com `ls -l` antes.
- **Diferença entre `adduser` e `useradd`**: `adduser` é mais amigável, configurando detalhes interativamente; `useradd` é mais técnico, exigindo configurações manuais (ex.: `passwd`).
- **Uso de `-aG` em `usermod`**: Sem `-a`, `usermod -G` substitui todos os grupos do usuário, o que pode remover permissões importantes.
- **Saiba mais**: Consulte `man adduser`, `man chmod`, `man chown`, ou `man usermod` para detalhes.
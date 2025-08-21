| Diretório        | Função técnica detalhada                                                                   |
| ---------------- | ------------------------------------------------------------------------------------------ |
| **`bin`**        | Link para `/usr/bin`. Contém **comandos essenciais** para uso de todos os usuários.        |
| **`boot`**       | Armazena o **kernel**, imagens initramfs e arquivos do **bootloader** (ex: GRUB).          |
| **`dev`**        | Sistema virtual que fornece acesso a **dispositivos de hardware** como arquivos especiais. |
| **`etc`**        | Contém **arquivos de configuração** do sistema, serviços e pacotes instalados.             |
| **`home`**       | Diretórios pessoais dos usuários comuns. Ex: `/home/usuario`.                              |
| **`lib`**        | Link para `/usr/lib`. Bibliotecas compartilhadas para programas em `/bin` e `/sbin`.       |
| **`lib64`**      | Link para `/usr/lib64`. Bibliotecas de 64 bits para a arquitetura do sistema.              |
| **`lost+found`** | Criado por sistemas ext*. Guarda arquivos recuperados após falhas de disco.                |
| **`media`**      | Ponto de montagem **automático** para mídias removíveis (USB, CDs, etc.).                  |
| **`mnt`**        | Usado para montagens **temporárias e manuais** feitas por administradores.                 |
| **`opt`**        | Instalação de **softwares adicionais** que não fazem parte do sistema base.                |
| **`proc`**       | Sistema de arquivos virtual que expõe informações sobre **processos** e o **kernel**.      |
| **`root`**       | Diretório pessoal do usuário `root` (administrador).                                       |
| **`run`**        | Armazena arquivos temporários **em tempo de execução** (PID files, sockets).               |
| **`sbin`**       | Link para `/usr/sbin`. Contém comandos **administrativos e de sistema**.                   |
| **`snap`**       | Diretório de montagem para **pacotes Snap** (formato contêiner da Canonical).              |
| **`srv`**        | Guarda dados usados por **serviços** como HTTP, FTP, etc. (ex: `/srv/www`).                |
| **`sys`**        | Sistema de arquivos virtual que fornece acesso ao **hardware** via `sysfs`.                |
| **`tmp`**        | Arquivos temporários criados por usuários ou processos; geralmente apagados no boot.       |
| **`usr`**        | Programas, bibliotecas e dados de **uso geral do sistema** (não críticos para boot).       |
| **`var`**        | Dados que **mudam com o tempo**, como logs, caches, spool de impressão, etc.               |
### 🧩 Diretórios especiais de transição (`/usr merge`):

|Diretório|Função explicativa|
|---|---|
|**`bin.usr-is-merged`**|Indica que `/bin` agora é um link para `/usr/bin`. Parte da modernização do FHS.|
|**`lib.usr-is-merged`**|Marca que `/lib` foi movido para `/usr/lib`.|
|**`sbin.usr-is-merged`**|Indica que `/sbin` agora aponta para `/usr/sbin`.

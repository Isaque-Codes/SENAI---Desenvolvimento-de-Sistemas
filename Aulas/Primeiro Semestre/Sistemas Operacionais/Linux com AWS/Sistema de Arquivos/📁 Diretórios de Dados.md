- **`etc/`**  
    Arquivos de configuração do sistema. Exemplos: rede, usuários, serviços.
    
- **`var/`**  
    Dados variáveis (logs, filas de impressão, caches). Ex: `/var/log`, `/var/spool`.
    
- **`tmp/`**  
    Arquivos temporários. Pode ser apagado a qualquer momento (especialmente no boot).
    
- **`run/`**  
    Dados de runtime. Contém arquivos que refletem o estado do sistema em tempo real (como PID de processos, sockets).
    
- **`proc/`**  
    Sistema de arquivos virtual com informações sobre processos e o kernel. Ex: `/proc/cpuinfo`, `/proc/meminfo`.
    
- **`sys/`**  
    Outro sistema de arquivos virtual, com informações e controle de dispositivos (via `sysfs`).
    
- **`dev/`**  
    Contém arquivos de dispositivos (como discos, terminais, etc). Ex: `/dev/sda`, `/dev/tty`.
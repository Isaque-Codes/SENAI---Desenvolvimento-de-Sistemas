### Gerenciamento de Serviços (systemctl)

|Comando|Descrição|Exemplo|
|---|---|---|
|`sudo systemctl status [programa]`|Verifica o status de um serviço (ex.: `apache2`), mostrando se está ativo.|`sudo systemctl status apache2`|
|`sudo systemctl start [programa]`|Inicia um serviço.|`sudo systemctl start apache2`|
|`sudo systemctl stop [programa]`|Para a execução de um serviço.|`sudo systemctl stop apache2`|
|`sudo systemctl restart [programa]`|Reinicia um serviço (para e inicia novamente).|`sudo systemctl restart apache2`|
|`sudo systemctl enable [programa]`|Habilita um serviço para iniciar automaticamente na inicialização do sistema.|`sudo systemctl enable apache2`|
|`sudo systemctl disable [programa]`|Desabilita a inicialização automática de um serviço.|`sudo systemctl disable apache2`|

### Firewall UFW

| Comando                             | Descrição                                                                   | Exemplo                        |
| ----------------------------------- | --------------------------------------------------------------------------- | ------------------------------ |
| `sudo ufw status`                   | Verifica se o firewall UFW está ativo e lista as regras configuradas.       | `sudo ufw status`              |
| `sudo ufw enable`                   | Ativa o firewall UFW, aplicando as regras configuradas.                     | `sudo ufw enable`              |
| `sudo ufw allow '[programa/porta]'` | Permite tráfego para um programa ou porta (ex.: `Apache Full`, `22/tcp`).   | `sudo ufw allow 'Apache Full'` |
| `sudo ufw deny '[programa/porta]'`  | Bloqueia tráfego para um programa ou porta.                                 | `sudo ufw deny 23`             |
| `sudo ufw app list`                 | Lista aplicativos com regras disponíveis no UFW (ex.: `Apache`, `OpenSSH`). | `sudo ufw app list`            |
| `sudo ufw reset`                    | Reseta todas as regras do firewall para o estado padrão (use com cuidado).  | `sudo ufw reset`               |

### Notas Úteis

- **Cuidado com o firewall**: Antes de ativar o `ufw` ou bloquear portas, garanta que o acesso SSH (`22/tcp`) está permitido para evitar perda de conexão.
- **Verificar serviços**: Use `systemctl status` para diagnosticar problemas (ex.: verificar logs de falhas).
- **Uso de `ufw allow`**: Especifique portas (ex.: `80/tcp`) ou nomes de aplicativos (ex.: `Apache Full`) para regras precisas.
- **Saiba mais**: Consulte `man systemctl` ou `man ufw` para detalhes.


### Exemplos Práticos

1. Iniciar e verificar o status de um serviço:
    
    ```bash
    sudo systemctl start apache2
    sudo systemctl status apache2
    ```
    
    Saída parcial: `Active: active (running)` (indica que o Apache2 está rodando).
    
2. Configurar o firewall para permitir tráfego HTTP e SSH:
    
    ```bash
    sudo ufw allow 'Apache Full'
    sudo ufw allow 22/tcp
    sudo ufw enable
    sudo ufw status
    ```
    
    Saída parcial:
    
    ```
    Status: active
    To                         Action      From
    --                         ------      ----
    80,443/tcp (Apache Full)   ALLOW       Anywhere
    22/tcp                     ALLOW       Anywhere
    ```
    
3. Bloquear uma porta e verificar:
    
    ```bash
    sudo ufw deny 8080
    sudo ufw status
    ```
    
    Saída parcial:
    
    ```
    Status: active
    To                         Action      From
    --                         ------      ----
    8080                       DENY        Anywhere
    ```
    
4. Resetar as regras do firewall (com cuidado):
    
    ```bash
    sudo ufw reset
    ```
    
    Saída: Pede confirmação para remover todas as regras e desativar o firewall.
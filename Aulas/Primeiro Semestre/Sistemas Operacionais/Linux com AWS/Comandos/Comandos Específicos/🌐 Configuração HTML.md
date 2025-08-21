## Localização de Arquivos HTML

- Arquivos HTML do Apache geralmente estão em `/var/www/html/`.
- Configurações de sites do Apache estão em `/etc/apache2/sites-available/`.

## Criação de Arquivos HTML e Configuração de Virtual Host

Para configurar um site com um virtual host no Apache, siga estes passos:

1. **Copiar configuração padrão**:
    
    ```bash
    cp /etc/apache2/sites-available/000-default.conf /etc/apache2/sites-available/[site].conf
    ```
    
    Cria uma cópia do arquivo de configuração padrão para o novo site.
    
2. **Configurar portas**:  
    Edite `/etc/apache2/ports.conf`:
    
    ```bash
    sudo nano /etc/apache2/ports.conf
    ```
    
    Adicione ou verifique a porta desejada, por exemplo:
    
    ```
    Listen 80
    Listen 443
    ```
    
3. **Configurar o Virtual Host**:  
    Edite o arquivo de configuração do site:
    
    ```bash
    sudo nano /etc/apache2/sites-available/[site].conf
    ```
    
    Adicione:
    
    ```
    <VirtualHost *:[porta]>
        ServerAdmin webmaster@localhost
        ServerName [site].local
        DocumentRoot /var/www/[site]
    </VirtualHost>
    ```
    
4. **Editar arquivo hosts**:  
    Adicione o site ao arquivo `/etc/hosts`:
    
    ```bash
    sudo nano /etc/hosts
    ```
    
    Inclua:
    
    ```
    127.0.0.1 [site].local
    ```
    
5. **Habilitar o site e recarregar Apache**:
    
    ```bash
    sudo a2ensite [site].conf
    sudo systemctl reload apache2
    ```
    
    Ativa o site e recarrega o Apache para aplicar as mudanças.
    
6. **Verificar**:  
    Teste o site com:
    
    ```bash
    curl http://[site].local
    ```
    
    Exibe o conteúdo da página no terminal.
## 🔧 Atualização do Sistema

1. **sudo apt update**
    
    ```
    sudo apt update
    ```
    
    Atualiza a lista de pacotes disponíveis nos repositórios.
    
2. **sudo apt upgrade**
    
    ```
    sudo apt upgrade
    ```
    
    Atualiza todos os pacotes instalados para as versões mais recentes.
    

---

## 🌐 Instalação do Apache (Servidor Web)

3. **sudo apt install apache2 -y**
    
    ```
    sudo apt install apache2 -y
    ```
    
    Instala o servidor Apache. O -y confirma a instalação automaticamente.

---

## ⚙️ Instalação do Node.js e npm

4a. **sudo apt install nodejs -y**  
`sudo apt install nodejs -y`  
Instala o Node.js (ambiente de execução JavaScript no servidor).

4b. **nodejs -v**  
`nodejs -v`  
Verifica a versão instalada do Node.js.

5a. **sudo apt install npm -y**  
`sudo apt install npm -y`  
Instala o npm, o gerenciador de pacotes do Node.js.

5b. **npm -v**  
`npm -v`  
Verifica a versão do npm.

---

## 🧬 Instalação do Git

6. **sudo apt install git -y**
    
    ```
    sudo apt install git -y
    ```
    
    Instala o Git, necessário para clonar o repositório do jogo.

---

## 📁 Clonando e Preparando o Projeto

7. **cd /var/www**
    
    ```
    cd /var/www
    ```
    
    Vai até o diretório padrão de aplicações web no Apache.
    
8. **sudo git clone [https://github.com/simondiep/node-multiplayer-snake.git](https://github.com/simondiep/node-multiplayer-snake.git)**
    
    ```
    sudo git clone https://github.com/simondiep/node-multiplayer-snake.git
    ```
    
    Clona o projeto do jogo Snake multiplayer.
    
9. **sudo chown -R $USER:$USER node-multiplayer-snake**
    
    ```
    sudo chown -R $USER:$USER node-multiplayer-snake
    ```
    
    Altera a propriedade dos arquivos para o seu usuário, permitindo edição e execução.
    
10. **cd node-multiplayer-snake**
    
    ```
    cd node-multiplayer-snake
    ```
    
    Entra no diretório do projeto.
    
11. **npm install**
    
    ```
    npm install
    ```
    
    Instala as dependências definidas no package.json.
    

- **node app.js**
    
    ```
    node app.js
    ```
    

---

## 🔁 Rodando o Projeto com PM2 (Gerenciador de Processos Node.js)

12. **sudo npm install -g pm2**
    
    ```
    sudo npm install -g pm2
    ```
    
    Instala o PM2 globalmente para gerenciar o processo Node.js como serviço.
    
13. **pm2 start app.js --name jogo_da_cobrinha**
    
    ```
    pm2 start app.js --name jogo_da_cobrinha
    ```
    
14. **pm2 startup**
    
    ```
    pm2 startup
    ```
    
    Gera o comando necessário para iniciar o PM2 automaticamente ao ligar o sistema.
    
15. **(copiar e colar o comando da tela)**
    
    ```
    sudo env PATH=$PATH:/usr/bin /usr/local/lib/node_modules/pm2/bin/pm2 startup systemd -u ubuntu --hp /home/ubuntu
    ```
    
    Executa o comando que o pm2 startup sugeriu. Isso cria o serviço no systemd.
    
16. **pm2 save**
    
    ```
    pm2 save
    ```
    
    Salva o estado atual dos processos gerenciados para restaurar no boot.
    

---

## 🌍 Configurando o Apache como Proxy Reverso

17. **sudo a2enmod proxy**
    
    ```
    sudo a2enmod proxy
    ```
    
18. **sudo a2enmod proxy_http**
    
    ```
    sudo a2enmod proxy_http
    ```
    
    Ativa os módulos proxy e proxy_http do Apache, necessários para redirecionar o tráfego HTTP.
    
19. **sudo systemctl restart apache2**
    
    ```
    sudo systemctl restart apache2
    ```
    
    Reinicia o Apache para aplicar os módulos ativados.
    
20. **sudo nano /etc/apache2/sites-available/000-default.conf**
    
    ```
    sudo nano /etc/apache2/sites-available/000-default.conf
    ```
    
    Abre o arquivo de configuração do site padrão no editor.
    
21. **Adicionar os comandos:**
    
    ```
    ProxyPreserveHost On
    ProxyPass / http://localhost:3000/
    ProxyPassReverse / http://localhost:3000/
    ```
    
    Esses comandos redirecionam o tráfego da porta 80 (Apache) para a porta 3000 (onde o jogo está rodando).
    
22. **sudo systemctl restart apache2**
    
    ```
    sudo systemctl restart apache2
    ```
    
    Reinicia o Apache para aplicar a nova configuração de proxy reverso.
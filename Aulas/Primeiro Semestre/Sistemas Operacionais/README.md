# 🐧 Sistemas Operacionais com Linux & AWS

Esta unidade curricular forneceu uma introdução imersiva ao mundo dos sistemas operacionais, utilizando **Linux (distribuição Ubuntu)** como o sistema de estudo e a **Amazon Web Services (AWS)** como a plataforma para provisionamento da infraestrutura.

O objetivo principal foi mergulhar na experiência prática, permitindo a interação direta com um servidor **Ubuntu** real na nuvem. Através de uma instância **EC2 (Elastic Compute Cloud)**, exploramos desde a estrutura fundamental do sistema de arquivos e os comandos essenciais do shell, até a hospedagem de múltiplas aplicações web e a execução de programas à partir de repositórios externos.

> **Nota:** Todo o processo de aprendizado ocorreu diretamente na linha de comando da máquina virtual, acessada via SSH, e em sua configuração manual na plataforma AWS.

---

## ☁️ Ambiente de Aprendizagem: Instância EC2 na AWS

A base para todas as atividades práticas foi a criação e configuração de uma máquina virtual na AWS. Este processo, por si só, cobriu conceitos fundamentais de computação em nuvem:

*   **Provisionamento de Instância:** Escolha de uma AMI (Amazon Machine Image), especificamente a distribuição **Ubuntu Server**.
*   **Gerenciamento de Acesso:** Criação e utilização de pares de chaves (`.pem`) para acesso seguro via protocolo **SSH (Secure Shell)**.
*   **Configuração de Rede e Segurança:** Liberação de portas específicas (como 22 para SSH e 8080, 8081, e 8082 para tráfego web) através da configuração de **Security Groups**, atuando como um firewall virtual para a instância.

---

## ⌨️ Comandos e Conceitos Fundamentais

A jornada de aprendizado foi dividida em dinâmicas práticas e colaborativas, explorando o sistema operacional **Ubuntu** através da linha de comando. A documentação completa dos comandos e conceitos pode ser encontrada na pasta **[Comandos](./Linux%20com%20AWS/Comandos/)**.

### 1. Estrutura e Manipulação do Sistema de Arquivos

O ponto de partida foi o estudo da organização hierárquica do sistema de arquivos do Linux, cujas ramificações de diretórios e suas respectivas funções estão detalhadas em **[Sistema de Arquivos](./Linux%20com%20AWS/Sistema%20de%20Arquivos/)**. Em seguida, aplicamos este conhecimento para criar, renomear, mover, copiar e excluir arquivos e diretórios em uma hierarquia complexa.

*   **Visualização e Navegação:** `ls`, `pwd`, `cd`, `tree`.
*   **Criação e Manipulação:** `mkdir -p`, `touch`, `cp`, `mv`, `rm`, `rmdir`.
*   **Leitura de Arquivos:** `cat`, `less`.

### 2. Gerenciamento de Usuários, Grupos e Permissões

Uma dinâmica crucial envolveu a simulação de um ambiente multiusuário. Em grupo, criamos diversos usuários e grupos, e praticamos a atribuição de permissões específicas para arquivos e diretórios usando `chmod` e `chown`, garantindo que cada usuário tivesse acesso apenas aos recursos pertinentes.

*   **Superusuário:** `sudo`, `su`.
*   **Gerenciamento de Usuários e Grupos:** `adduser`, `addgroup`, `usermod`, `deluser`, `delgroup`.
*   **Gerenciamento de Permissões:** `chmod` (modos numérico e simbólico), `chown`, `chgrp`.

### 3. Gerenciamento de Pacotes, Serviços e Firewall

Aprendemos a gerenciar o ciclo de vida do software e dos serviços no servidor.

*   **Gerenciador de Pacotes APT:** `apt-get update`, `upgrade`, `install`, `remove`, `purge`.
*   **Gerenciador de Serviços `systemctl`:** `status`, `start`, `stop`, `restart`, `enable`, `disable`.
*   **Firewall UFW:** `ufw status`, `enable`, `allow`, `deny`.

---

## 🚀 Projetos Práticos Aplicados

Para consolidar o conhecimento, realizamos projetos que simulam tarefas comuns de um desenvolvedor ou administrador de sistemas.

### 1. Hospedagem de Múltiplos Sites com Apache2

Este projeto prático abordou o desafio de hospedar vários sites em uma única máquina virtual. A dinâmica envolveu a configuração de **Virtual Hosts** no Apache2, permitindo que o servidor respondesse em múltiplas portas e direcionasse o tráfego para o diretório raiz de cada site correspondente.

*   **Tecnologia Utilizada:** Servidor Web **Apache2**.
*   **Conceitos Aplicados:** Edição de arquivos de configuração (`/etc/apache2/sites-available/`), mapeamento de portas (`Listen`), e ativação de sites (`a2ensite`).
*   **Resultado:** Três sites distintos (feitos no ChatGPT com temáticas aleatórias) foram hospedados simultaneamente, acessíveis através do mapeamento de portas externas para a porta 80 interna do servidor (`8080`, `8081`, `8082`). Os prints do resultado podem ser vistos na pasta **[3 Sites em Nuvem com EC2](./Linux%20com%20AWS/3%20Sites%20em%20Nuvem%20com%20EC2/)** e o manual para replicar o procedimento se encontra no arquivo **[🌐 Configuração HTML.md](./Linux%20com%20AWS/Comandos/Comandos%20Espec%C3%ADficos/%F0%9F%8C%90%20Configura%C3%A7%C3%A3o%20HTML.md)**.

### 2. Executando uma Aplicação Web Externa: Jogo da Cobrinha

Este projeto demonstrou o fluxo completo de implantação de uma aplicação **Node.js** à partir do GitHub, tornando-a um serviço persistente e acessível pela web. O passo a passo completo está documentado em **[🕹️ Jogo da Cobrinha.md](./Linux%20com%20AWS/Comandos/Comandos%20Espec%C3%ADficos/%F0%9F%95%B9%EF%B8%8F%20Jogo%20da%20Cobrinha.md)**.

*   **Tecnologias Utilizadas:** **Node.js** como ambiente de execução, **PM2** como gerenciador de processos, e **Apache2** como proxy reverso.
*   **Fluxo Executado:**
    1.  **Preparação do Ambiente:** Instalação do Node.js, npm e Git.
    2.  **Obtenção do Código:** Clonagem do repositório com `git clone`.
    3.  **Instalação de Dependências:** Uso do `npm install`.
    4.  **Gerenciamento do Processo:** Utilização do `pm2` para iniciar a aplicação e garantir que ela continue rodando e reinicie automaticamente com o servidor.
    5.  **Exposição na Web:** Configuração do Apache2 como um **proxy reverso**, redirecionando o tráfego da porta 80 para a porta 3000, onde a aplicação Node.js estava sendo executada.

Esta dinâmica proporcionou uma compreensão prática e profunda de como implantar e gerenciar aplicações web modernas em um ambiente de servidor Linux.
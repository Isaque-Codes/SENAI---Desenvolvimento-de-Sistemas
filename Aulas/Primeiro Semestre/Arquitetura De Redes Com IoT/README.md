# 🌐 Arquitetura de Redes com IoT

A progressão nesta unidade curricular abrange desde a criação de funções e estruturas de dados robustas, passando pela comunicação sem fio local com Bluetooth (Master-Slave), até a implementação de um ecossistema IoT completo, onde dispositivos coletam dados de sensores, publicam na nuvem via protocolo MQTT, e outros dispositivos consomem esses dados para exibição e controle. O foco é construir soluções que sejam não apenas funcionais, mas também modulares, eficientes e robustas contra falhas. Os projetos contidos aqui marcam a transição de sistemas embarcados locais para dispositivos conectados, inteligentes e resilientes.

> **Nota:** Os projetos aqui presentes foram desenvolvidos e testados com hardware físico (ESP32, sensores, displays, etc.). Como a execução depende de componentes específicos e da montagem de circuitos, o foco deste material é a demonstração da arquitetura de software, da lógica de programação e dos conceitos de rede aplicados.

---

## 🚀 Projetos em Destaque

Para uma visão rápida das habilidades desenvolvidas, recomendo explorar os seguintes projetos, que representam a síntese dos conhecimentos adquiridos nesta disciplina.

1.  **[Internet Continuação](./Internet%20Continua%C3%A7%C3%A3o):** O projeto mais completo. Demonstra um nó sensor IoT bidirecional que lê dados de um sensor de temperatura/umidade (DHT) e de um botão, os empacota em JSON e os publica na nuvem via MQTT. Simultaneamente, ele recebe comandos da nuvem para ter seu comportamento (controle de LED, intervalo de publicação) alterado remotamente. É um sistema de telemetria e controle de ponta a ponta.

2.  **[Internet 2](./Internet%202):** O par perfeito do projeto anterior e um exemplo de excelência em arquitetura de software. Este nó de monitoramento consome dados da nuvem, mas se destaca pela sua modularidade (código quebrado em funções pequenas e focadas) e robustez (tratamento de erro de JSON). A forma como ele usa o timestamp recebido para formatar a data/hora localmente é um exemplo de grande refinamento técnico.

3.  **[Aula 50 - Encoder Rotativo](./Aula%2050%20-%20Encoder%20Rotativo):** Um mergulho profundo em programação de baixo nível para criar uma interface de usuário sofisticada. A leitura do encoder rotativo é feita de forma extremamente eficiente, usando uma máquina de estados com tabela de transição (lookup table), uma técnica de alta performance. A arquitetura de menu com múltiplos modos de operação é a base para qualquer interface embarcada complexa.

4.  **[Aula 56 - Comunicacao VT](./Aula%2056%20-%20Comunica%C3%A7%C3%A3o%20VT):** A melhor demonstração de comunicação direta **Dispositivo-para-Dispositivo (M2M)**. Este projeto implementa uma rede pessoal sem fio (WPAN) via Bluetooth, com funcionalidades Master/Slave e um protocolo de comando-ação-resposta. Essencial para entender a automação onde dispositivos colaboram diretamente.

5.  **[Aula 58 - Comunicacao Serial](./Aula%2058%20-%20Comunica%C3%A7%C3%A3o%20Serial):** Uma aula sobre como escrever um firmware **correto e responsivo**. Sua arquitetura não-bloqueante, que separa a leitura de comandos, o processamento da lógica e a atuação no hardware, é o padrão de ouro para sistemas embarcados. O parser de comandos avançado é a base para qualquer dispositivo controlado via texto.

---

## 🗺️ Guia de Navegação Rápida

Abaixo está um mapeamento dos principais conceitos e seus respectivos projetos que melhor os demonstram.

| Conceito | Projetos de Referência |
| :--- | :--- |
| **Estruturas de Dados (`struct`)** | [Structs](./Structs) |
| **Criação de Funções e Prototipagem** | [Aula 46 - Funcoes](./Aula%2046%20-%20Funcoes) |
| **Debounce de Botão por Temporização** | [Aula 45 - Debounce Button](./Aula%2045%20-%20Debounce%20Button), [Aula 50 - Encoder Rotativo](./Aula%2050%20-%20Encoder%20Rotativo) |
| **Leitura de Encoder Rotativo** | [Aula 50 - Encoder Rotativo](./Aula%2050%20-%20Encoder%20Rotativo) |
| **Manipulação de Strings (Strings / Strings char)** | [Aula 54 - Manipulacao De Strings](./Aula%2054%20-%20Manipula%C3%A7%C3%A3o%20De%20Strings) |
| **Comunicação Bluetooth (Pessoa-Dispositivo)** | [Aula 55 - Leitura Da Serial](./Aula%2055%20-%20Leitura%20Da%20Serial) |
| **Comunicação Bluetooth Master-Slave (Dispositivo-Dispositivo)** | [Aula 56 - Comunicacao VT](./Aula%2056%20-%20Comunica%C3%A7%C3%A3o%20VT) |
| **Comunicação Bluetooth Full-Duplex** | [Aula 59 - FullDuplex](./Aula%2059%20-%20FullDuplex), [Aula 59 - FullDuplex 2](./Aula%2059%20-%20FullDuplex%202) |
| **Conectividade Wi-Fi Resiliente (Reconexão)** | [Captura De Dados MQTT](./Captura%20De%20Dados%20MQTT), [Internet](./Internet), [Internet 2](./Internet%202), [Internet Continuação](./Internet%20Continua%C3%A7%C3%A3o) |
| **Sincronização de Tempo (NTP) e `ezTime`** | [Internet](./Internet), [Internet 2](./Internet%202), [Internet Continuação](./Internet%20Continua%C3%A7%C3%A3o) |
| **Protocolo MQTT (Publisher & Subscriber)** | [Captura De Dados MQTT](./Captura%20De%20Dados%20MQTT), [Internet 2](./Internet%202), [Internet Continuação](./Internet%20Continua%C3%A7%C3%A3o) |
| **Parsing de JSON (Deserialização)** | [Captura De Dados MQTT](./Captura%20De%20Dados%20MQTT), [Internet 2](./Internet%202) |
| **Construção de JSON (Serialização)** | [Internet Continuação](./Internet%20Continua%C3%A7%C3%A3o) |
| **Leitura de Sensores (DHT)** | [Internet Continuação](./Internet%20Continua%C3%A7%C3%A3o) |
| **Arquitetura Não-Bloqueante (`millis()`)** | [Aula 58 - Comunicacao Serial](./Aula%2058%20-%20Comunica%C3%A7%C3%A3o%20Serial), [Internet 2](./Internet%202), [Internet Continuação](./Internet%20Continua%C3%A7%C3%A3o) |

---

## 🛠️ Lista Completa de Conceitos Aplicados

Esta seção detalha a lista completa de habilidades técnicas demonstradas nos códigos desta disciplina.

### Estrutura de Software e Programação
- **Modularização de Código:** Separação de responsabilidades em múltiplos arquivos (`.cpp`, `.h`) para criar módulos reutilizáveis.
- **Funções Personalizadas:** Criação de funções com e sem retorno (`void`), passagem de parâmetros e prototipagem.
- **Estruturas de Dados (`struct`):** Agrupamento de variáveis de tipos diferentes para modelar entidades de forma organizada.
- **Arquitetura Não-Bloqueante:** Uso extensivo de `millis()` para criar sistemas responsivos que executam múltiplas tarefas.
- **Gerenciamento de Estado:** Uso de variáveis `static` para manter o estado do dispositivo (modos, contadores, etc.) entre as execuções do `loop()`.
- **Operador Ternário:** Uso de `condição ? true : false` para lógicas condicionais compactas.

### Interação com Hardware e Sensores
- **Debounce de Botão:** Implementação de filtro de ruído por temporização para garantir leituras de botão confiáveis.
- **Leitura de Encoder Rotativo:** Decodificação de sinais em quadratura para detectar direção e movimento com alta precisão.
- **Leitura de Sensores:** Codificação e integração de sensores para coleta de dados em tempo real.
- **Tratamento de Erro de Hardware:** Verificação de leituras inválidas de sensores (`isnan()`).
- **Controle de Display LCD I2C:** Criação de Interfaces Homem-Máquina (IHM) para feedback visual.

### Conectividade e Protocolos de Rede
- **Gerenciamento de Wi-Fi:** Criação de um módulo de conexão robusto com lógica de timeout e reconexão automática.
- **Comunicação Bluetooth Serial:** Implementação de comunicação Pessoa-Dispositivo, Master-Slave e Full-Duplex.
- **Protocolo MQTT:** Domínio do ciclo completo de publicação e assinatura (Publish/Subscribe) para comunicação com a nuvem.
- **Formato de Dados JSON:** Serialização (criação) e Deserialização (parsing) de mensagens JSON para troca de dados estruturados.
- **Sincronização de Tempo (NTP):** Uso de servidores de tempo na internet para obter data e hora precisas, com gerenciamento de fuso horário.
- **Timestamp Unix:** Utilização do padrão universal de tempo para registro de eventos.

### Bibliotecas do Ecossistema
- **`Bounce2`:** Debounce de botões e detecção de eventos (clique, mudança de estado).
- **`PubSubClient`:** Implementação do protocolo MQTT.
- **`ArduinoJson`:** Manipulação de dados no formato JSON.
- **`ezTime`:** Sincronização e manipulação de data/hora.
- **`DHT_U` / `Adafruit_Sensor`:** Interação com sensores de hardware.

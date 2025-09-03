# 💧💨 Monitor de Gás e Chuva com ESP32

Este projeto, desenvolvido pelo grupo 3, demonstra a integração e o monitoramento de um sensor de gás (CO) e um sensor de chuva, utilizando um microcontrolador ESP32. O sistema lê os dados dos sensores em tempo real, exibe o status em um display LCD I2C e permite a consulta dos valores via comunicação serial.

---

## 🎯 Objetivo do Projeto

O objetivo principal foi desenvolver uma aula invertida sobre o funcionamento de sensores de gás e chuva, demonstrando de forma prática a sua aplicação. O projeto abrange desde a montagem do hardware até o desenvolvimento de um firmware que integra a leitura de múltiplos sensores, o controle de um display e a comunicação com o usuário.

---

## ✨ Funcionalidades Principais

*   **Monitoramento de Gás (CO):** Leitura contínua da concentração de gás no ambiente, mapeando o valor para uma escala de intensidade e exibindo alertas de segurança no LCD ("Seguro", "Alerta", "Perigo").
*   **Detecção de Chuva/Umidade:** Verificação do estado do sensor de chuva, indicando se a superfície está "Seca" ou "Molhada".
*   **Interface Homem-Máquina:** Utilização de um display LCD I2C para fornecer feedback visual instantâneo sobre o status de ambos os sensores.
*   **Comunicação Serial Interativa:** Permite que o usuário solicite um relatório completo do estado dos sensores digitando o comando `leitura` no monitor serial.
*   **Arquitetura Não-Bloqueante:** O firmware utiliza a função `millis()` para gerenciar a leitura dos sensores em intervalos regulares, sem "congelar" o processador com o uso da função delay, garantindo que o sistema permaneça responsivo.

---

## 🛠️ Componentes e Montagem

Abaixo estão os materiais necessários e o esquema de conexão para a montagem do protótipo, refletindo os pinos utilizados no código-fonte final.

### Materiais Necessários
*   1x ESP32
*   1x Sensor de Gás (ex: MQ-2, MQ-135)
*   1x Sensor de Chuva (com módulo comparador)
*   1x Display LCD I2C 20x4
*   Protoboard e Jumpers

### Esquema de Conexão

| Componente | Pino no Componente | Pino no ESP32 |
| :--- | :--- | :--- |
| **Sensor de Gás** | `VCC` | `3V3` |
| | `GND` | `GND` |
| | `AO` (Saída Analógica) | `GPIO 34` |
| **Sensor de Chuva** | `VCC` | `3V3` |
| | `GND` | `GND` |
| | `AO` (Saída Analógica) | `GPIO 35` |
| **Display LCD I2C** | `VCC` | `5V` (ou `VIN`) |
| | `GND` | `GND` |
| | `SDA` | `GPIO 21` |
| | `SCL` | `GPIO 22` |

---

## 👨‍💻 Sobre o Código

O firmware foi desenvolvido em C/C++ utilizando a extensão PlatformIO no Visual Studio Code.

### Lógica Principal

O `loop()` principal é dividido em três seções que operam de forma concorrente graças à temporização com `millis()`:

1.  **Leitura do Sensor de Gás:** A cada segundo, o valor analógico do `pinoFumaca` é lido, mapeado para uma escala de intensidade e exibido no LCD com o respectivo nível de alerta.
2.  **Leitura do Sensor de Chuva:** Também a cada segundo, o `pinoChuva` é verificado e o display é atualizado para "Seco" ou "Molhado", atualizando a variável `estaChovendo`.
3.  **Comunicação Serial:** O código verifica continuamente se há dados disponíveis na porta serial. Se o comando "leitura" for recebido, ele envia um relatório formatado com os últimos valores registrados nas variáveis `teorCO` e `estaChovendo`.

### Destaque do Código: Função `lerSerial()`

Uma função `lerSerial()` foi implementada para gerenciar a comunicação serial de forma robusta e eficiente. Esta abordagem é uma prática recomendada em programação para microcontroladores.

> **Por que esta implementação é importante?**
> A função utiliza um array de `char` (C-string) de tamanho fixo em vez do objeto `String` do Arduino. Isso evita o uso de alocação dinâmica de memória, que pode causar **fragmentação da memória heap** e levar a travamentos inesperados em sistemas que operam por longos períodos. O resultado é um firmware mais estável, previsível e com menor consumo de recursos.
>
> **[Confira o código-fonte com comentários linha a linha aqui](https://github.com/Isaque-Codes/SENAI---Desenvolvimento-de-Sistemas/blob/main/Projetos/Sensores%20de%20G%C3%A1s%20e%20Chuva/C%C3%B3digo/src/main.cpp )**.

A função lê os caracteres da porta serial um por um, armazenando-os em um buffer até que um caractere de fim de linha (`\n` ou `\r`) seja detectado. Somente então ela finaliza a string com um terminador nulo (`\0`), garantindo que apenas comandos completos sejam processados.

---

## 🚀 Como Executar

1.  **Montagem:** Monte o circuito conforme o esquema de conexão acima.
2.  **Ambiente:** Abra o projeto no Visual Studio Code com a extensão PlatformIO.
3.  **Upload:** Conecte o ESP32 ao computador e faça o upload do código.
4.  **Monitoramento:** Abra o Monitor Serial com a velocidade (baud rate) de `9600` para visualizar os logs de inicialização e interagir com o sistema.
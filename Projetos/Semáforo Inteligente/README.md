# 🚦 Semáforo Adaptativo com Lógica Não-Bloqueante

Este é o primeiro projeto prático de codificação do curso, se trata de um **exercício de lógica de programação intensiva**, implementado em C/C++ para as plataformas Arduino/ESP32. O objetivo foi construir mais do que um simples semáforo; o sistema é um **controlador de tráfego adaptativo**, capaz de alterar seu comportamento em tempo real com base em uma entrada externa.

A complexidade do projeto não está apenas em alternar luzes, mas em gerenciar múltiplos processos (temporização, leitura de botão, atualização de display e funcionamento adaptativo) de forma simultânea e responsiva, utilizando uma arquitetura de software não-bloqueante.

---

## 🛠️ Montagem e Execução

Este guia descreve como montar o hardware e executar o projeto para vê-lo em funcionamento.

### Componentes Necessários
*   1x ESP32
*   1x Display LCD I2C 20x4
*   1x LED Vermelho
*   1x LED Amarelo
*   1x LED Verde
*   3x Resistores de 220Ω (um para cada LED)
*   1x Push Button (botão de pressão)
*   Protoboard e Jumpers

### Esquema de Conexão

Siga as conexões abaixo para montar o circuito.

| Componente | Conexão | Pino no ESP32 |
| :--- | :--- | :--- |
| **LED Vermelho** | Anodo (+) via Resistor 220Ω | `GPIO 19` |
| **LED Amarelo** | Anodo (+) via Resistor 220Ω | `GPIO 5` |
| **LED Verde** | Anodo (+) via Resistor 220Ω | `GPIO 18` |
| **Botão** | Um terminal | `GPIO 4` |
| | Outro terminal | `GND` |
| **Display LCD I2C** | `VCC` | `5V` (ou `VIN`) |
| | `GND` | `GND` |
| | `SDA` | `GPIO 21` |
| | `SCL` | `GPIO 22` |

*Nota: Todos os catodos (-) dos LEDs devem ser conectados ao `GND`.*

### Passo a Passo para Execução

1.  **Monte o Circuito:** Utilize a tabela acima para conectar todos os componentes no protoboard com o ESP32.
2.  **Ambiente de Desenvolvimento:** Abra o projeto no Visual Studio Code com a extensão PlatformIO instalada.
3.  **Conecte o ESP32:** Conecte seu ESP32 ao computador via cabo USB.
4.  **Faça o Upload:** Use a função de "Upload" do PlatformIO para compilar e enviar o firmware para o microcontrolador.
5.  **Teste:** Após o upload, o sistema iniciará automaticamente. Pressione o botão durante a fase verde para testar a lógica adaptativa.

---

## ⚙️ Arquitetura e Lógica Implementada

O sistema é construído sobre três pilares lógicos que operam em conjunto a cada ciclo do `loop()`.

### 1. Máquina de Estados Finitos (Controle do Semáforo)

O núcleo do sistema é uma máquina de estados que gerencia as fases do semáforo (Vermelho, Verde, Amarelo). A transição entre os estados é controlada pela função `millis()`, garantindo que o microcontrolador permaneça livre para executar outras tarefas.

> **Ponto Destaque Secundário: Gerenciamento de Estado Adaptativo -**
> A máquina de estados foi projetada para ser flexível. Durante a fase verde, o código verifica uma flag booleana (`alteredTime`) para decidir qual lógica de tempo aplicar. Isso permite que o sistema opere com seu tempo padrão ou mude para um novo tempo recalculado dinamicamente, sem quebrar a sequência da máquina de estados.
> ```c++
> // Fase verde (com lógica adaptativa)
> else if (trafficLightPhase == 1)
> {
>   // Se o tempo não foi alterado, usa o tempo padrão (greenTime).
>   // Se foi alterado, usa o novo tempo recalculado (updatedRemainingTime).
>   if (alteredTime == false)
>   {
>     remainingTime = greenTime - (currentTime - beginTime);
>   }
>   else
>   {
>     remainingTime = updatedRemainingTime - (currentTime - beginTime);
>   }
>   // ... transição para a próxima fase ...
> }
> ```
> Esta abordagem com uma flag de estado desacopla a lógica de temporização da lógica de transição, tornando o sistema modular e fácil de expandir.

### 2. Lógica Adaptativa (O Cérebro do Sistema)

Esta é a funcionalidade central que torna o semáforo "inteligente". O sistema monitora um botão, mas a lógica de interrupção só é acionada durante a fase verde. Ao detectar o pressionar, ele não muda de fase imediatamente. Em vez disso, ele executa uma lógica de recálculo complexa.

> **Ponto Destaque Principal: Recálculo Dinâmico e Proporcional de Tempo -**
> O coração da lógica adaptativa reside em um bloco condicional aninhado que só é executado sob três condições: o botão foi pressionado, a fase atual é a verde e o tempo ainda não foi alterado neste ciclo.
>
> 1.  **Cálculo de Progresso:** Primeiro, ele calcula quanto tempo do sinal verde já se passou (`progress = greenTime - remainingTime`).
> 2.  **Lógica Escalonada:** Em seguida, ele usa uma série de `if-else if` para aplicar uma redução de tempo proporcional. Quanto mais cedo o botão é pressionado (maior `remainingTime`), maior é a "aceleração" do ciclo.
> 3.  **Atualização Sistemática:** Ao decidir a nova duração, ele atualiza todas as variáveis de estado relevantes (`alteredTime`, `newGreenTime`, `remainingTime`, `updatedRemainingTime`) e, crucialmente, **reseta o cronômetro da fase** (`beginTime = currentTime`). Isso garante que a contagem regressiva continue de forma suave a partir do novo valor, sem saltos ou inconsistências.
> ```c++
> // A lógica de recálculo só é acionada se o botão for pressionado,
> // durante a fase verde e se o tempo ainda não foi alterado.
> if (!stateButton && trafficLightPhase == 1 && alteredTime == false)
> {
>   progress = (greenTime - remainingTime);
>
>   // Quanto mais cedo o botão for pressionado, maior a redução de tempo.
>   if (remainingTime > (greenTime * 75) / 100)
>   {
>     alteredTime = true;
>     newGreenTime = (greenTime * 60) / 100;
>     remainingTime = newGreenTime - progress;
>     updatedRemainingTime = remainingTime;
>     beginTime = currentTime; // Reseta o cronômetro com o novo tempo.
>   }
>   else if (/* ... outras condições ... */)
>   // ...
> }
> ```

### 3. Tratamento de Hardware

Para garantir a confiabilidade do sistema, foi implementado um tratamento de **debounce** para o botão de entrada. Uma lógica baseada em `millis()` ignora as flutuações elétricas de um único aperto de botão, garantindo que a lógica adaptativa seja acionada apenas uma vez, de forma limpa e intencional. A sessão do código responsável pelo debounce se encontra nas linhas **94-118**, com última aparição na linha **152**.

> **Confira o código-fonte documentado** **[aqui](https://github.com/Isaque-Codes/SENAI---Desenvolvimento-de-Sistemas/blob/main/Projetos/Sem%C3%A1foro%20Inteligente/C%C3%B3digo/src/main.cpp )**.

---

## 🛠️ Conceitos Aplicados

*   **Programação Concorrente Simulada:** Gerenciamento de múltiplas tarefas (temporização, input, output) sem o uso de `delay()`.
*   **Máquinas de Estado Finito (FSM):** Controle de fluxo sequencial com lógica de transição baseada em estado e tempo.
*   **Lógica Condicional Complexa:** Tomada de decisão em tempo real baseada em múltiplas variáveis de estado (`trafficLightPhase`, `alteredTime`, `lastAction`).
*   **Algoritmos de Temporização Dinâmica:** Recálculo de tempo de execução com base em eventos externos.
*   **Interação Hardware-Software:** Integração de LEDs, display LCD I2C e botões.
*   **Debounce de Botão:** Implementação de filtro de ruído por software para entradas digitais.
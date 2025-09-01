# 🚦 Semáforo Adaptativo com Lógica Não-Bloqueante

Este projeto é um exercício de lógica de programação intensiva, implementado em C/C++ para as plataformas Arduino/ESP32. O objetivo foi construir mais do que um simples semáforo; o sistema é um **controlador de tráfego adaptativo**, capaz de alterar seu comportamento em tempo real com base em uma entrada externa.

A complexidade do projeto não está apenas em alternar luzes, mas em gerenciar múltiplos processos (temporização, leitura de botão, atualização de display) de forma simultânea e responsiva, utilizando uma arquitetura de software não-bloqueante.

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

### 3. Tratamento de Hardware (Robustez)

Para garantir a confiabilidade do sistema, foi implementado um tratamento de **debounce** para o botão de entrada. Uma lógica baseada em `millis()` ignora as flutuações elétricas de um único aperto de botão, garantindo que a lógica adaptativa seja acionada apenas uma vez, de forma limpa e intencional.

---

## 🛠️ Conceitos Aplicados

*   **Programação Concorrente Simulada:** Gerenciamento de múltiplas tarefas (temporização, input, output) sem o uso de `delay()`.
*   **Máquinas de Estado Finito (FSM):** Controle de fluxo sequencial com lógica de transição baseada em estado e tempo.
*   **Lógica Condicional Complexa:** Tomada de decisão em tempo real baseada em múltiplas variáveis de estado (`trafficLightPhase`, `alteredTime`, `lastAction`).
*   **Algoritmos de Temporização Dinâmica:** Recálculo de tempo de execução com base em eventos externos.
*   **Interação Hardware-Software:** Integração de LEDs, display LCD I2C e botões.
*   **Debounce de Botão:** Implementação de filtro de ruído por software para entradas digitais.
# 🚦 Semáforo Adaptativo com Lógica Não-Bloqueante

Este projeto é um exercício de lógica de programação intensiva, implementado em C/C++ para as plataformas Arduino/ESP32. O objetivo foi construir mais do que um simples semáforo, o sistema é um **controlador de tráfego adaptativo**, capaz de alterar seu comportamento em tempo real com base em uma entrada externa.

A complexidade do projeto não está apenas em alternar luzes, mas em gerenciar múltiplos processos (temporização, leitura de botão, atualização de display) de forma simultânea e responsiva, utilizando uma arquitetura de software não-bloqueante.

---

## ⚙️ Arquitetura e Lógica Implementada

O sistema é construído sobre três pilares lógicos que operam em conjunto a cada ciclo do `loop()`.

### 1. Máquina de Estados Finitos (Controle do Semáforo)

O núcleo do sistema é uma máquina de estados que gerencia as fases do semáforo (Vermelho, Verde, Amarelo).

*   **Controle de Tempo Não-Bloqueante:** A transição entre os estados é controlada pela função `millis()`, em vez de `delay()`. Isso garante que o microcontrolador permaneça livre para executar outras tarefas, como ler o estado do botão, enquanto a temporização ocorre em paralelo.
*   **Visualização em Tempo Real:** O estado atual é representado por três LEDs (vermelho, amarelo e verde) e exibido em um display LCD I2C, que também informa o tempo restante de cada fase.

### 2. Lógica Adaptativa (O Cérebro do Sistema)

Esta é a funcionalidade central que torna o semáforo "inteligente".

*   **Gatilho de Interrupção:** O sistema monitora um botão, mas a lógica de interrupção só é acionada durante a fase verde.
*   **Recálculo Dinâmico de Tempo:** Ao detectar o pressionar do botão, o sistema não muda de fase imediatamente. Em vez disso, ele calcula o progresso da fase verde atual e recalcula um novo tempo de duração, muito menor.
*   **Lógica Escalonada:** A redução do tempo é proporcional ao tempo que ainda restava. Quanto mais cedo o botão é pressionado, maior é a "aceleração" do ciclo, forçando uma transição rápida para a fase amarela. Isso simula um sistema real, como um botão de pedestres que otimiza o fluxo do trânsito.

### 3. Tratamento de Hardware (Robustez)

Para garantir a confiabilidade do sistema, foi implementado um tratamento de **debounce** para o botão de entrada.

*   **Filtro de Ruído:** Uma lógica baseada em `millis()` ignora as flutuações elétricas de um único aperto de botão, garantindo que a lógica adaptativa seja acionada apenas uma vez, de forma limpa e intencional.

---

## 🛠️ Conceitos Aplicados

*   **Programação Concorrente Simulada:** Gerenciamento de múltiplas tarefas (temporização, input, output) sem o uso de `delay()`.
*   **Máquinas de Estado Finito (FSM):** Controle de fluxo sequencial e lógico.
*   **Lógica Condicional Complexa:** Tomada de decisão em tempo real baseada em múltiplas variáveis de estado e tempo.
*   **Interação Hardware-Software:** Integração de LEDs, display LCD I2C e botões.
*   **Debounce de Botão:** Implementação de filtro de ruído por software para entradas digitais.

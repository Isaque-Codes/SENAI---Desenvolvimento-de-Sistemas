# 🧠 Lógica de Programação e Algoritmos

O objetivo é construir uma base sólida em programação estruturada, manipulação de hardware e resolução de problemas algorítmicos.

> **Nota:** Os projetos aqui presentes foram desenvolvidos e simulados na plataforma **Tinkercad**. Como a execução depende da montagem manual de circuitos virtuais, o foco deste material é a demonstração da lógica de programação e dos conceitos aplicados, e não um guia de reprodução.

---

## 🚀 Projetos de Destaque

Para uma visão rápida das habilidades desenvolvidas, recomendo explorar os seguintes projetos, que representam marcos importantes no aprendizado:

*   **[Aula 36 - Analog LCD](./Arduino%20Uno/Aula%2036%20-%20Analog%20LCD):** Este é o projeto de síntese desta unidade curricular, ele combina uma interface de usuário em um display LCD, leitura de múltiplos botões em uma única porta analógica, controle de brilho de LEDs (PWM) e uma máquina de estados robusta. É a demonstração prática da integração de hardware e software para criar um produto interativo e funcional.

*   **[Aula 31 - Lógica De Temporização](./Arduino%20Uno/Aula%2031%20-%20L%C3%B3gica%20De%20Temporiza%C3%A7%C3%A3o):** Este projeto é um exemplo crucial de programação não-bloqueante. Ao abandonar o `delay()` e adotar a função `millis()`, o código cria um sistema de temporização eficiente que permite ao microcontrolador permanecer responsivo a outras tarefas, uma técnica essencial para qualquer projeto de IoT ou automação complexo.

*   **[Aula 41 - Estruturas De Repetição](./Arduino%20Uno/Aula%2041%20-%20Estruturas%20De%20Repeti%C3%A7%C3%A3o):** O destaque aqui é o Exercício 4, que demonstra o uso prático do `INPUT_PULLUP` para simplificar a fiação de botões e uma lógica de controle de fluxo avançada, onde um laço `for` pode ser interrompido a qualquer momento por uma ação do usuário.

---

## 🗺️ Guia de Navegação Rápida

Abaixo está um mapeamento dos principais conceitos e as aulas onde eles são mais bem demonstrados.

| Conceito | Aulas de Referência |
| :--- | :--- |
| **Conceitos Básicos (pinMode, digitalWrite)** | [Aula 23 - Semáforos Paralelos Simultâneos](./Arduino%20Uno/Aula%2023%20-%20Sem%C3%A1foros%20Paralelos%20Simult%C3%A2neos) |
| **Tipos de Variáveis e Comunicação Serial** | [Aula 25 - Tipos De Dados Primitivos](./Arduino%20Uno/Aula%2025%20-%20Tipos%20De%20Dados%20Primitivos) |
| **Operadores Aritméticos e Funções Matemáticas** | [Aula 26 - Operações Aritméticas](./Arduino%20Uno/Aula%2026%20-%20Opera%C3%A7%C3%B5es%20Aritm%C3%A9ticas) |
| **Estruturas Condicionais (if-else)** | [Aula 27 - Estruturas De Decisão](./Arduino%20Uno/Aula%2027%20-%20Estruturas%20De%20Decis%C3%A3o), [Aula 31 - Lógica De Temporização](./Arduino%20Uno/Aula%2031%20-%20L%C3%B3gica%20De%20Temporiza%C3%A7%C3%A3o) |
| **Estrutura de Seleção (switch-case)** | [Aula 27 - Estruturas De Decisão](./Arduino%20Uno/Aula%2027%20-%20Estruturas%20De%20Decis%C3%A3o), [Aula 31 - Lógica De Temporização](./Arduino%20Uno/Aula%2031%20-%20L%C3%B3gica%20De%20Temporiza%C3%A7%C3%A3o) |
| **Controle de Tempo sem `delay()` (millis())** | [Aula 31 - Lógica De Temporização](./Arduino%20Uno/Aula%2031%20-%20L%C3%B3gica%20De%20Temporiza%C3%A7%C3%A3o) |
| **Leitura de Botão e Detecção de Borda** | [Aula 33 - Reset De Acionamento](./Arduino%20Uno/Aula%2033%20-%20Reset%20De%20Acionamento), [Aula 34 - Digital LCD](./Arduino%20Uno/Aula%2034%20-%20Digital%20LCD) |
| **Uso de Bibliotecas e Controle de LCD I2C** | [Aula 34 - Digital LCD](./Arduino%20Uno/Aula%2034%20-%20Digital%20LCD), [Aula 36 - Analog LCD](./Arduino%20Uno/Aula%2036%20-%20Analog%20LCD) |
| **Leitura de Sinais Analógicos (analogRead)** | [Aula 35 - Medidor De Tensão Elétrica](./Arduino%20Uno/Aula%2035%20-%20Medidor%20De%20Tens%C3%A3o%20El%C3%A9trica), [Aula 36 - Analog LCD](./Arduino%20Uno/Aula%2036%20-%20Analog%20LCD) |
| **Controle de Brilho com PWM (analogWrite)** | [Aula 36 - Analog LCD](./Arduino%20Uno/Aula%2036%20-%20Analog%20LCD) |
| **Estrutura de Repetição (for) e Arrays** | [Aula 39 - Arrays](./Arduino%20Uno/Aula%2039%20-%20Arrays), [Aula 41 - Estruturas De Repetição](./Arduino%20Uno/Aula%2041%20-%20Estruturas%20De%20Repeti%C3%A7%C3%A3o) |
| **Estrutura de Repetição (do-while) e INPUT_PULLUP** | [Aula 41 - Estruturas De Repetição](./Arduino%20Uno/Aula%2041%20-%20Estruturas%20De%20Repeti%C3%A7%C3%A3o) |
| **Técnica de Múltiplos Botões em Porta Analógica** | [Aula 36 - Analog LCD](./Arduino%20Uno/Aula%2036%20-%20Analog%20LCD) |

---

## 🛠️ Lista Completa de Conceitos Aplicados

Esta seção detalha a lista completa de habilidades técnicas demonstradas nos códigos desta disciplina.

### Fundamentos de Programação (C/C++ para Arduino)
- **Estrutura Básica:** Uso das funções `setup()` e `loop()`.

- **Variáveis e Tipos de Dados:** Declaração e uso de `bool`, `char`, `byte`, `int`, `unsigned int`, `long`, `unsigned long`, `float`, `double`.
- **Constantes e Macros:** Uso de `const` e `#define` para criar constantes e apelidos para pinos/valores.
- **Operadores Aritméticos:** Soma (`+`), subtração (`-`), multiplicação (`*`), divisão (`/`), resto (`%`).
- **Operadores Compostos de Atribuição:** `+=`, `-=`.
- **Operadores de Incremento/Decremento:** `++` (pré e pós), `--` (pré e pós).
- **Operadores Relacionais e de Comparação:** `==`, `!=`, `>`, `<`, `>=`, `<=`.
- **Operadores Lógicos:** `&&` (E), `||` (OU), `!` (NÃO).
- **Estruturas Condicionais:** `if`, `else if`, `else`.
- **Estrutura de Seleção:** `switch-case` com `break` e `default`.
- **Estruturas de Repetição (Laços):** `for`, `do-while`.
- **Estruturas de Dados:** Arrays (vetores) para agrupar dados como pinos e valores.
- **Escopo de Variáveis:** Variáveis globais e locais, com destaque para o uso de `static` para manter o estado dentro de uma função.
- **Bibliotecas Externas:** Inclusões como o uso de `#include <LiquidCrystal_I2C.h>`.

### Funções Nativas do Arduino
- **Digitais:** `pinMode()`, `digitalWrite()`, `digitalRead()`.
- **Analógicas:** `analogRead()`, `analogWrite()` (PWM).
- **Tempo:** `delay()`, `millis()`.
- **Matemáticas:** `pow()`, `sq()`, `sqrt()`, `abs()`, `constrain()`, `map()`.
- **Comunicação:** `Serial.begin()`, `Serial.print()`, `Serial.println()`.

### Técnicas e Algoritmos
- **Controle de Fluxo:** Criação de lógicas complexas com condicionais aninhadas.
- **Máquina de Estados:** Implementação de lógica sequencial e temporizada sem `delay()` (usando `millis()`), controlada por uma variável de "fase".
- **Detecção de Borda de Botão (Debounce):** Leitura de botão que reage apenas à transição (pressionar ou soltar), evitando múltiplas ativações.
- **Leitura de Múltiplos Botões em Porta Analógica:** Uso de um divisor de tensão para ler vários botões com uma única entrada analógica.
- **Algoritmos Clássicos:** Sequência de Fibonacci e busca linear em um array.

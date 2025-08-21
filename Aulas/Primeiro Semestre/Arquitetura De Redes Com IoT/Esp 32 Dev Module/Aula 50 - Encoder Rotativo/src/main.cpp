#include <Arduino.h>
#include <Bounce2.h>

// Definições de pinos
#define PINO_ENCODER_A 5  // Canal A (CLK) do encoder rotativo
#define PINO_ENCODER_B 18 // Canal B (DT) do encoder rotativo
#define PINO_BOTAO 4      // Botão embutido no encoder

// Objeto da biblioteca Bounce para tratar debounce do botão
Bounce botaoEncoder = Bounce();

// Protótipo da função que detecta rotação do encoder
int detectarRotacaoEncoder(void);

// Tabela de transição de estados do encoder rotativo
// Cada entrada representa a direção do movimento com base no estado anterior e atual
const int8_t tabelaTransicao[4][4] = {
    {0, 1, -1, 0}, // de estado 0
    {-1, 0, 0, 1}, // de estado 1
    {1, 0, 0, -1}, // de estado 2
    {0, -1, 1, 0}  // de estado 3
};

void setup()
{
  pinMode(PINO_ENCODER_A, INPUT);
  pinMode(PINO_ENCODER_B, INPUT);
  botaoEncoder.attach(PINO_BOTAO, INPUT);

  Serial.begin(9600);
}

void loop()
{
  // Detecta a direção da rotação: -1 anti-horário, +1 horário, 0 parado
  int direcaoRotacao = detectarRotacaoEncoder();

  // Atualiza o estado do botão com debounce
  botaoEncoder.update();

  // Variável para alternar entre modos: menu de seleção ou ajuste
  static bool modoMenuAtivo = true; // true = menu, false = ajuste

  // Variável que indica a posição atual do cursor no menu (0 a 3)
  static int indiceItemMenu = 0;

  // Intensidades individuais dos LEDs (0 a 100)
  static int intensidadeLed[4] = {0, 0, 0, 0};

  // Alterna entre o modo de menu e o modo de ajuste ao pressionar o botão
  if (botaoEncoder.fell())
  {
    modoMenuAtivo = !modoMenuAtivo;
  }

  // --------------------------
  // MODO MENU ATIVO (Seleciona o LED)
  // --------------------------
  if (modoMenuAtivo)
  {
    if (direcaoRotacao != 0)
    {
      indiceItemMenu += direcaoRotacao;

      // Faz o índice circular entre 0 e 3
      if (indiceItemMenu > 3)
        indiceItemMenu = 0;
      else if (indiceItemMenu < 0)
        indiceItemMenu = 3;

      Serial.print("Item selecionado: LED ");
      Serial.println(indiceItemMenu + 1);
    }
  }

  // --------------------------
  // MODO AJUSTE ATIVO (Modifica intensidade do LED selecionado)
  // --------------------------
  else if (direcaoRotacao != 0)
  {
    intensidadeLed[indiceItemMenu] += direcaoRotacao * 10;

    // Limita a intensidade entre 0 e 100
    if (intensidadeLed[indiceItemMenu] > 100)
      intensidadeLed[indiceItemMenu] = 100;
    else if (intensidadeLed[indiceItemMenu] < 0)
      intensidadeLed[indiceItemMenu] = 0;

    Serial.print("Intensidade do LED ");
    Serial.print(indiceItemMenu + 1);
    Serial.print(": ");
    Serial.println(intensidadeLed[indiceItemMenu]);
  }

  // Aqui você pode futuramente aplicar essas intensidades com analogWrite() ou PWM.
}

int detectarRotacaoEncoder()
{
  // Lê o estado atual dos canais do encoder
  bool estadoA = digitalRead(PINO_ENCODER_A);
  bool estadoB = digitalRead(PINO_ENCODER_B);

  // Junta os dois bits (A e B) em uma única variável (valores de 0 a 3)
  int estadoAtual = (estadoA << 1) | estadoB;

  static int estadoAnterior = 3; // 3 = repouso
  static int acumulador = 0;     // Acumula os passos do movimento
  int resultado = 0;             // Retorna 1, -1 ou 0

  // Detecta mudança de estado (movimento)
  if (estadoAtual != estadoAnterior)
  {
    // Atualiza o acumulador com base na tabela de transição
    acumulador += tabelaTransicao[estadoAnterior][estadoAtual];

    // Se o estado atual for 3 (repouso), verifica se houve rotação completa
    if (estadoAtual == 3)
    {
      if (acumulador == 4)
      {
        resultado = 1; // sentido horário
      }
      else if (acumulador == -4)
      {
        resultado = -1; // sentido anti-horário
      }

      acumulador = 0; // zera para próxima leitura
    }

    // Atualiza o estado anterior
    estadoAnterior = estadoAtual;
  }

  return resultado;
}
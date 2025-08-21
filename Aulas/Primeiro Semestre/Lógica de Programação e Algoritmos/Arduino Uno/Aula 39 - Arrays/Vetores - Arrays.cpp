/* 18/03/2025

-FAZER CONTAGEM EM SEQUENCIA FIBONACCI COM E SEM A FUNCAO FOR
-LIGAR 5 LEDS JUNTOS COM A ESTRUTURA DE DADOS ARRAY
*/

const int pinLeds[5] = {7, 5, 4, 3, 2};

void setup()
{
  Serial.begin(9600);

  for (char Leds = 0; Leds < 5; Leds++)
    pinMode(pinLeds[Leds], OUTPUT);
}

void loop()
{
  // FIBONACCI SEM FOR
  static unsigned long numeroAnterior;
  static unsigned long numeroAtual = 1;
  static unsigned long numeroPosterior;

  // Serial.println (numeroAtual);

  numeroPosterior = numeroAtual + numeroAnterior;

  numeroAnterior = numeroAtual;

  numeroAtual = numeroPosterior;

  delay(500);

  // FIBONACCI COM FOR
  static unsigned long valorAnterior;
  static unsigned long valorAtual = 1;
  static unsigned long valorPosterior;

  for (byte X = 1; X < 5; X++)
  {
    Serial.println(valorAtual);
    valorPosterior = valorAtual + valorAnterior;
    valorAnterior = valorAtual;
    valorAtual = valorPosterior;
    delay(500);
  }

  // TRATAMENTO DOS LEDS
  for (int Y = 0; Y < 5; Y++)
  {
    digitalWrite(pinLeds[Y], HIGH);
    delay(300);
  }
  for (int Y = 0; Y < 5; Y++)
  {
    digitalWrite(pinLeds[Y], LOW);
    delay(300);
  }
}
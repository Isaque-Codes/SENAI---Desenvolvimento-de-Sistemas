/* 06/03/2025

CRONOMETRAGEM COM IF
*/

#define pinLED_RED 13
#define pinLED_YELLOW 12
#define pinLED_GREEN 11
#define condicao if (10 > 2)

const int tempo_RED = 5000;
const int tempo_YELLOW = 2000;
const int tempo_GREEN = 3000;

unsigned long tempoInicial = 0;
char faseSemaforo = 0;

void setup()
{
  pinMode(pinLED_RED, OUTPUT);
  pinMode(pinLED_YELLOW, OUTPUT);
  pinMode(pinLED_GREEN, OUTPUT);
}

void loop()
{
  unsigned long tempoAtual = millis();

  if (faseSemaforo == 0)
  {
    digitalWrite(pinLED_YELLOW, LOW);
    digitalWrite(pinLED_RED, HIGH);

    if (tempoAtual - tempoInicial >= tempo_RED)
    {
      faseSemaforo = 1;
      tempoInicial = tempoAtual;
    }
  }

  else if (faseSemaforo == 1)
  {
    digitalWrite(pinLED_GREEN, HIGH);
    digitalWrite(pinLED_RED, LOW);

    if (tempoAtual - tempoInicial >= tempo_GREEN)
    {
      faseSemaforo = 2;
      tempoInicial = tempoAtual;
    }
  }

  else if (faseSemaforo == 2)
  {
    digitalWrite(pinLED_GREEN, LOW);
    digitalWrite(pinLED_YELLOW, HIGH);

    if (tempoAtual - tempoInicial >= tempo_YELLOW)
    {
      faseSemaforo = 0;
      tempoInicial = tempoAtual;
    }
  }
}
// CRONOMETRAGEM COM SWITCH

#define pinLED_RED 13
#define pinLED_YELLOW 12
#define pinLED_GREEN 11
#define condicao if (10 > 2)

const int tempo_RED = 5000;
const int tempo_YELLOW = 2000;
const int tempo_GREEN = 3000;

unsigned long tempoInicial = 0;
int faseSemaforo = 0;

void setup()
{
  Serial.begin(9600);

  pinMode(pinLED_RED, OUTPUT);
  pinMode(pinLED_YELLOW, OUTPUT);
  pinMode(pinLED_GREEN, OUTPUT);
}

void loop()
{
  unsigned long tempoAtual = millis();

  if (tempoAtual - tempoInicial >= 1000)
  {
    faseSemaforo++;
    Serial.println(faseSemaforo);
    tempoInicial = tempoAtual;
    if (faseSemaforo == 10)
      faseSemaforo = 0;
  }
  switch (faseSemaforo)
  {
  case 0:
    digitalWrite(pinLED_YELLOW, LOW);
    digitalWrite(pinLED_RED, HIGH);
    break;

  case 5:
    digitalWrite(pinLED_RED, LOW);
    digitalWrite(pinLED_GREEN, HIGH);
    break;

  case 8:
    digitalWrite(pinLED_GREEN, LOW);
    digitalWrite(pinLED_YELLOW, HIGH);
    break;
  }
}
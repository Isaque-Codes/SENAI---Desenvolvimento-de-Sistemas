#include <Arduino.h>

#define pinLed 5
#define pinBotao 4

int raizDaFuncao;

//* PROTOTIPOS DAS FUNCAOS
int funcaoSegundoGrau(int, int, int);

void ligaLed(uint8_t);
void desligaLed(uint8_t);
//* FIM DA PROTOTIPACAO

void setup()
{
  Serial.begin(115200);

  pinMode(pinLed, OUTPUT);
}

void loop()
{
  funcaoSegundoGrau(1, 6, 9);
  Serial.print("Raiz Da Funcao: ");
  Serial.println(raizDaFuncao);

  ligaLed(pinLed);
  delay(300);
  desligaLed(pinLed);
  delay(300);
}

int funcaoSegundoGrau(int a, int b, int c)
{
  raizDaFuncao = ((b * -1) + (sqrt(sq(b) - (4 * a * c)) / (2 * a)));
  return raizDaFuncao;
}

void ligaLed(uint8_t pin)
{
  digitalWrite(5, HIGH);
}

void desligaLed(uint8_t pin)
{
  digitalWrite(5, LOW);
}
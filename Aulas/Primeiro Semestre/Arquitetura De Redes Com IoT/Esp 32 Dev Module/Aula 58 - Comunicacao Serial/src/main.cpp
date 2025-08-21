#include <Arduino.h>

//* A funcao readStringUntil trava o sistema enquanto alguem esta digitando na serial

#define pinLed 2

void setup()
{
  Serial.begin(9600);
  Serial.print("Comunicacao serial iniciada\n");
  pinMode(pinLed, OUTPUT);
}

void loop()
{
  static bool estadoLed = false;
  static bool piscaLed = false;
  static int tempo = 0;

  if (Serial.available())
  {
    String msg = Serial.readStringUntil('\n');
    msg.trim();
    msg.toLowerCase();
    if (msg.equals("liga"))
    {
      estadoLed = true;
    }
    else if (msg.equals("desliga"))
    {
      estadoLed = false;
      piscaLed = false;
    }
    else if (msg.equals("pisca"))
    {
      piscaLed = true;
    }
    else if (msg.equals("rap") && piscaLed)
    {
      tempo -= 50;
      if (tempo < 50)
      {
        tempo = 50;
        Serial.print("Velocidade maxima atingida\n");
      }
    }
    else if (msg.equals("dev") && piscaLed)
    {
      tempo += 50;
      if (tempo > 1000)
      {
        tempo = 1000;
        Serial.print("Velocidade minima atingida\n");
      }
    }
    if (msg.startsWith("velocidade ="))
    {
      int tamanho = msg.length();
      String extracao = msg.substring(6, tamanho);
      int valorVelocidade = extracao.toint();

      if (valorVelocidade >= 0 && valorVelocidade <= 100)
        tempo = map(valorVelocidade, 0, 100, 1000, 50);
      else
        Serial.println("Valores aceitos apenas entre 0 e 100");
    }
    else
      Serial.print("Comando nao reconhecido\n");
  }

  unsigned long tempoAtual = millis();
  static unsigned long tempoInicial = 0;
  if (tempoAtual - tempoInicial > tempo && piscaLed)
  {
    estadoLed = !estadoLed;
    tempoInicial = tempoAtual;
  }
  digitalWrite(pinLed, estadoLed);
}
#include <Arduino.h>
#include <BluetoothSerial.h>

BluetoothSerial SerialBT;
#define pinLed 2

void setup()
{
  Serial.begin(9600);
  pinMode(pinLed, OUTPUT);
  SerialBT.begin("SlaveEspirro");

  if (!SerialBT.begin("SlaveEspirro", false))
  {
    Serial.println("Erro ao iniciar Bluetooth como Slave");
  }
  else
    Serial.println("Aguardando Conexao Bluetooth");
}

void loop()
{
  if (Serial.available())
  {
    String comandoEnviado = Serial.readStringUntil('\n');
    comandoEnviado.trim();
    SerialBT.println(comandoEnviado);
  }

  if (SerialBT.available())
  {
    String comandoRecebido = SerialBT.readStringUntil('\n');
    comandoRecebido.trim();
    comandoRecebido.toLowerCase();
    Serial.printf("Comando recebido: %s\n\r", comandoRecebido);

    bool estadoLed = false;
    bool piscaLed = false;
    static int frequenciaLed = 50;

    if (comandoRecebido.equals("liga"))
    {
      estadoLed = true;
    }

    if (comandoRecebido.equals("desliga"))
    {
      estadoLed = false;
      piscaLed = false;
    }

    if (comandoRecebido.equals("pisca"))
    {
      estadoLed = true;
      piscaLed = true;
    }

    if (comandoRecebido.equals("+"))
    {
      frequenciaLed -= 50;
      if (frequenciaLed < 50)
      {
        frequenciaLed = 50;
        Serial.println("Velocidade maxima atingida");
      }
    }

    if (comandoRecebido.equals("-"))
    {
      frequenciaLed += 50;
      if (frequenciaLed > 500)
      {
        frequenciaLed = 500;
        Serial.println("Velocidade minima atingida");
      }
    }

    else
    {
      Serial.println("Comando nao reconhecido");
    }

    static unsigned long tempoAtual = millis();
    static unsigned long tempoInicial = 0;
    if (tempoAtual - tempoInicial > frequenciaLed && piscaLed)
    {
      estadoLed = !estadoLed;
      tempoInicial = tempoAtual;
    }
    digitalWrite(pinLed, estadoLed);
  }
}
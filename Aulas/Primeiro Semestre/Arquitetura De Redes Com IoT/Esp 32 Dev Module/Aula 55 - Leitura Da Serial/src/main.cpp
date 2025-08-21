#include <Arduino.h>
#include "BluetoothSerial.h"

//*Uma vez lido o buffer, o buffer some

#define pinLed 2

//* INSTANCIAS DE OBJETOS
BluetoothSerial SerialBT;
String palavra = "";

void setup()
{
  pinMode(pinLed, OUTPUT);
  SerialBT.begin("ESPCracolandia6969666");
  SerialBT.println("Digite algo no monitor serial");
}

void loop()
{
  static bool pisca = false;
  static bool conectado = false;
  if (SerialBT.hasClient())
  {
    if (!conectado)
    {
      conectado = true;
      SerialBT.println("Conexao Bluetooth estabelecida com sucesso!");
    }
  }
  while (SerialBT.available())
  {
    char caractere = SerialBT.read();
    if (caractere == '\n' || caractere == '\r')
    {
      SerialBT.println(palavra);
      if (palavra.equals("liga"))
      {
        digitalWrite(pinLed, HIGH);
      }
      else if (palavra.equals("desliga"))
      {
        digitalWrite(pinLed, LOW);
        pisca = 0;
      }
      else
      {
        SerialBT.println("Comando nao reconhecido");
      }
      palavra = "";
    }

    else if (caractere != '\r')
    {
      palavra += caractere;
    }

    /*if (caractere == 'L')
    {
      digitalWrite(pinLed, HIGH);
      Serial.println("Led Ligado");
    }
    else if (caractere == 'D')
    {
      digitalWrite(pinLed, LOW);
      Serial.println("Led Desligado");
    }
    else
    {
      Serial.printf("Voce digitou %c, digite apenas L ou D\n\r", caractere);
    }*/
  }
}
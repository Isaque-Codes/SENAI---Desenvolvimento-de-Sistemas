#include <Arduino.h>
#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

//! ESP MASTER
void setup()
{
  Serial.begin(9600);
  SerialBT.begin("ESPirata", true);

  (SerialBT.connect("ESPirro"));
  if (SerialBT.connect("ESPirro"))
  {
    Serial.println("Conectado ao dispositivo com sucesso");
  }
  else
  {
    Serial.println("F");
    while (true)
      ; // Trava o ESP
  }
  SerialBT.print("liga");
  Serial.println("Enviado a mensaagem");
}

void loop()
{
  unsigned long timeout = millis() + 3000;
  while (millis() < timeout)
  {
    String comando;
    comando = Serial.readStringUntil('\r');

    if (comando.equals("liga"))
    {
      SerialBT.print("liga");
    }

    if (comando.equals("desliga"))
    {
      SerialBT.print("desliga");
    }

    if (comando.equals("pisca"))
    {
      SerialBT.print("pisca");
    }

    if (comando.equals("stoPisca"))
    {
      SerialBT.print("stoPisca");
    }

    if (SerialBT.available())
    {
      String resposta = SerialBT.readStringUntil('\r');
      SerialBT.printf("%c", resposta);
      break;
    }
  }
}

/*
//! ESP Slave

void setup()
{
  Serial.begin(9600);
  SerialBT.begin("ESPirro");

  Serial.println("Esperando uma conexao Bluetooth");
  pinMode(pinLed, OUTPUT);
}

void loop()
{
  {
    if (SerialBT.available())
    {
      String mensagem = SerialBT.readStringUntil('\n');
      Serial.printf("Mensagem recebida: %s", mensagem);

      if (mensagem.equals("ping"))
      {
        SerialBT.print("pong\n\r");
      }
      if (mensagem.equals("liga"))
      {
        digitalWrite(pinLed, HIGH);
        SerialBT.print("Led ligado\n\r");
      }

      if (mensagem.equals("desliga"))
      {
        digitalWrite(pinLed, LOW);
        SerialBT.print("Led desligado\n\r");
      }

      if (mensagem.equals("pisca"))
      {
        while (true)
        {
          digitalWrite(pinLed, HIGH);
          delay(250);
          digitalWrite(pinLed, LOW);
          delay(250);
          SerialBT.print("Led piscando\n\r");
          mensagem = SerialBT.readStringUntil('\n');
          if (mensagem.equals("stoPisca"))
            break;
        }
      }
    }
  }
}
  */

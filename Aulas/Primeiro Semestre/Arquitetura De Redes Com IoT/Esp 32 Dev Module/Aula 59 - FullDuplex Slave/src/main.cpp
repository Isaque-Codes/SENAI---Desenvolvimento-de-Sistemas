#include <Arduino.h>
#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

void setup()
{
  Serial.begin(9600);

  if (!SerialBT.begin("MasterEspirro", true))
  {
    Serial.println("Erro ao iniciar o BT no modo Master");
  }

  if (SerialBT.connect("SlaveEspirro"))
  {
    Serial.println("Conectado com sucesso ao SlaveEspirro");
  }
  else
  {
    Serial.println("Falha ao se conectar ao SlaveEspirro");
  }
}

void loop()
{
  if (Serial.available())
  {
    String comando = Serial.readStringUntil('\n');
    comando.trim();
    SerialBT.println(comando);
  }

  if (SerialBT.available())
  {
    String comandoReceptor = SerialBT.readStringUntil('\n');
    comandoReceptor.trim();
    Serial.printf("Comando recebido: %s\n\r", comandoReceptor);

    if (comandoReceptor.equals("liga"))
    {
    }
    else if (comandoReceptor.equals("desliga"))
    {
    }
    else if (comandoReceptor.equals("pisca"))
    {
    }
    else
    {
      Serial.println("Comando nao reconhecido");
    }
  }
}
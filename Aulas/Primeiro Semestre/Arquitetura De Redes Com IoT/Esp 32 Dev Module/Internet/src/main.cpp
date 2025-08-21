#include <Arduino.h>
#include <ezTime.h>
#include "internet.h"

Timezone tempo;

void setup()
{
  Serial.begin(9600);
  conectaWiFi();

  waitForSync();
  tempo.setLocation("America/Sao_Paulo");
}

void loop()
{
  checkWiFi();
  Serial.println(tempo.dateTime());     // Nome do dia da semana, dia do mes, mes, ano, hora, minuto, segundo, getposix
  Serial.println(tempo.day());          // Dia do mes
  Serial.println(tempo.month());        // Mes do ano
  Serial.println(tempo.yearISO());      // Ano
  Serial.println(tempo.dayOfYear());    // Dia do ano
  Serial.println(tempo.hour());         // Hora (0-24)
  Serial.println(tempo.hourFormat12()); // Hora (0-12)
  Serial.println(tempo.minute());       // Minuto da hora
  Serial.println(tempo.second());       // Segundo do minuto
  Serial.println(tempo.getPosix());     // Porra nenhuma
  Serial.println(tempo.isAM());         // booleana, 1 para AM
  Serial.println(tempo.isPM());         // booleana, 1 para PM
  Serial.println(tempo.now());          // Segundos passados desde 1970
  Serial.println(tempo.ms());           // Milissegundos em ciclos de 0-999
  Serial.println(tempo.weekday());      // Numero do dia da semana
  Serial.println("______________________________________________________");
  delay(3000);
}

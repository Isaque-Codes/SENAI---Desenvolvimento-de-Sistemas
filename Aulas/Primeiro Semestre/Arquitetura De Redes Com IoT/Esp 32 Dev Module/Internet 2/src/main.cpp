#include <Arduino.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <ezTime.h>
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include "internet.h"

WiFiClient espClient;
PubSubClient client(espClient);
Timezone tempoLocal;
LiquidCrystal_I2C lcd(0x27, 20, 4);

const char *mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;
const char *mqtt_id = "esp32-senai134-isaque2";
const char *mqtt_topic_sub = "senai134/mesa08/infoTempUmid";
const char *mqtt_topic_pub = "";

void callback(char *, byte *, unsigned int);
void mqttConnect(void);
void tratamentoMsg(String);
void mostraDisplay(float temp, float umid, time_t timestamp);
void templateDisplay(void);

void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  templateDisplay();
  conectaWiFi();

  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
  tempoLocal.setLocation("America/Sao_Paulo");
}

void loop()
{
  checkWiFi();
  if (!client.connected())
    mqttConnect();

  client.loop();
}

void callback(char *topic, byte *payload, unsigned int length)
{
  Serial.printf("mensagem recebida em %s: ", topic);

  String mensagem = "";
  for (unsigned int i = 0; i < length; i++)
  {
    char c = (char)payload[i];
    mensagem += c;
  }
  Serial.println(mensagem);

  tratamentoMsg(mensagem);
}

void mqttConnect()
{
  while (!client.connected())
  {
    Serial.println("Conectando ao MQTT...");

    if (client.connect(mqtt_id))
    {
      Serial.println("Conectado com sucesso");
      client.subscribe(mqtt_topic_sub);
    }

    else
    {
      Serial.print("falha, rc=");
      Serial.println(client.state());
      Serial.println("tentando novamente em 5 segundos");
      delay(5000);
    }
  }
}

void tratamentoMsg(String msg)
{
  String mensagem = msg;
  JsonDocument doc;
  DeserializationError erro = deserializeJson(doc, mensagem);

  if (erro)
  {
    Serial.println("Mensagem Recebida não esta no formato Json");
    return;
  }

  else
  {
    float temperatura, umidade;
    time_t timestamp;

    if (!doc["temp"].isNull())
      temperatura = doc["temp"];

    if (!doc["umid"].isNull())
      umidade = doc["umid"];

    if (!doc["timestamp"].isNull())
      timestamp = doc["timestamp"];

    mostraDisplay(temperatura, umidade, timestamp);
  }
}

// TODO ARRUMAR ISSO NUMA PROXIMA OPORTUNIDADE, MAS NÃO HOJE
void mostraDisplay(float temp, float umid, time_t time)
{
  float temperatura = temp;
  float umidade = umid;
  time_t timestamp = time;

  lcd.setCursor(6, 1);
  temperatura = constrain(temperatura, 0, 99);
  lcd.print(temperatura, 1);

  umidade = constrain(umidade, 0, 100);
  lcd.setCursor(6, 2);
  lcd.print(umidade, 1);

  lcd.setCursor(0, 3);
  tempoLocal.setTime(timestamp);
  lcd.print(tempoLocal.dateTime("d/m/Y H:i"));

  /* Tabela com os principais placeholders disponíveis
  Código	Significado	Exemplo
  Y	Ano com 4 dígitos	2025
  y	Ano com 2 dígitos	25
  m	Mês com 2 dígitos	05
  n	Mês sem zero à esquerda	5
  d	Dia do mês com 2 dígitos	29
  j	Dia do mês sem zero	9
  H	Hora (formato 24h, 2 dig.)	08
  G	Hora (24h, sem zero)	8
  h	Hora (formato 12h, 2 dig.)	08
  g	Hora (12h, sem zero)	8
  i	Minutos com 2 dígitos	30
  s	Segundos com 2 dígitos	09
  A	AM ou PM (maiúsculo)	AM
  a	am ou pm (minúsculo)	am
  D	Dia da semana abrev. (inglês)	Thu
  l	Nome completo do dia (inglês)	Thursday
  M	Mês abreviado (inglês)	May
  F	Nome completo do mês	May
  z	Dia do ano (0 a 365)	148
  W	Semana do ano (ISO-8601)	22
  T	Abreviação do fuso horário	BRT
  O	Diferença para UTC (num)	-0300
  */
}

void templateDisplay()
{
  lcd.home();
  lcd.print("Ambiente Monitorado");

  lcd.setCursor(0, 1);
  lcd.print("Temp:     C"); // (6,1)

  lcd.setCursor(0, 2);
  lcd.print("Umid:     %"); // (6,1)
}
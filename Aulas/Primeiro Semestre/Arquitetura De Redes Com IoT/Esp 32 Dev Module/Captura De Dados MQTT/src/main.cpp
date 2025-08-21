#include "internet.h"
#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <ezTime.h>
#include <ArduinoJson.h>
#include <LiquidCrystal_I2C.h>

WiFiClient espClient;
PubSubClient client(espClient);
Timezone tempo;
LiquidCrystal_I2C lcd(0x27, 20, 4);

const char *mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;
const char *mqtt_id = "esp32-senai134-isaque2";
const char *mqtt_topic_sub = "senai134/mesa04/esp_publicando1";
const char *mqtt_topic_pub = "senai134/mesa03/esp_publicando";

void callback(char *, byte *, unsigned int);
void mqttConnect(void);

void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Aguardando dados...");
  conectaWiFi();

  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);

  waitForSync();
  tempo.setLocation("America/Sao_Paulo");
}

void loop()
{
  checkWiFi();

  if (!client.connected())
    mqttConnect();

  client.loop();
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

  JsonDocument doc;
  deserializeJson(doc, mensagem);

  static float umidade, temperatura;
  static unsigned long timestamp;

  if (!doc["umidade"].isNull())
  {
    umidade = doc["umidade"];
    lcd.setCursor(0, 0);
    lcd.print("Umidade: ");
    lcd.setCursor(9, 0);
    lcd.print(umidade);
    lcd.setCursor(14, 0);
    lcd.print("      ");
  }

  if (!doc["temperatura"].isNull())
  {
    temperatura = doc["temperatura"];
    lcd.setCursor(0, 1);
    lcd.print("Temperatura: ");
    lcd.setCursor(13, 1);
    lcd.print(temperatura);
    lcd.setCursor(18, 1);
    lcd.print(" C");
  }

  if (!doc["timestamp"].isNull())
  {
    timestamp = doc["timestamp"];
    lcd.setCursor(0, 2);
    lcd.print("timestamp: ");
    lcd.setCursor(11, 2);
    lcd.print(timestamp);
  }
}
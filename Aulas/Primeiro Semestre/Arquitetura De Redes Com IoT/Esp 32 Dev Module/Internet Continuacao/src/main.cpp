#include "internet.h"
#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <ezTime.h>
#include <ArduinoJson.h>
#include <Bounce2.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define pinLed 2
#define DHTPIN 4
#define DHTTYPE DHT22

WiFiClient espClient;
PubSubClient client(espClient);
Bounce botao = Bounce();
Timezone tempo;
DHT_Unified dht(DHTPIN, DHTTYPE);

const char *mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;
const char *mqtt_id = "esp32-senai134-isaque";
const char *mqtt_topic_sub = "senai134/mesa03/esp_inscrito";
const char *mqtt_topic_pub = "senai134/mesa03/esp_publicando";

bool envioMqtt = false;

bool estadoLed = false;
bool modoPisca = false;
unsigned long tempoEspera = 500;

float temperatura, umidade;
unsigned long dhtInterval = 1000;

void callback(char *, byte *, unsigned int);
void mqttConnect(void);
void controleLed(void);
void dhtSetup(void);
void dhtLoop(void);

void setup()
{
  Serial.begin(9600);
  pinMode(pinLed, OUTPUT);

  botao.attach(0, INPUT_PULLUP);

  conectaWiFi();

  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);

  waitForSync();
  tempo.setLocation("America/Sao_Paulo");

  pinMode(0, INPUT_PULLUP);

  dhtSetup();
}

void loop()
{
  checkWiFi();

  if (!client.connected())
    mqttConnect();

  client.loop();

  dhtLoop();

  static unsigned long tempoAnterior = 0;
  unsigned long tempoAtual = millis();

  JsonDocument doc;
  String mensagem;

  botao.update();

  if (tempoAtual - tempoAnterior > dhtInterval)
  {
    doc["temp"] = temperatura;
    doc["umid"] = umidade;
    envioMqtt = true;
    tempoAnterior = tempoAtual;
  }

  if (botao.changed())
  {
    doc["botao"] = !botao.read();
    envioMqtt = true;
  }

  if (envioMqtt)
  {
    doc["timestamp"] = tempo.now();
    serializeJson(doc, mensagem);
    Serial.println(mensagem);
    client.publish(mqtt_topic_pub, mensagem.c_str());
    envioMqtt = false;
  }

  controleLed();
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

  if (!doc["estadoLed"].isNull())
  {
    estadoLed = doc["estadoLed"];
    modoPisca = 0;
  }

  if (!doc["modoPisca"].isNull())
  {
    modoPisca = doc["modoPisca"];
  }

  if (!doc["velocidade"].isNull())
  {
    tempoEspera = doc["velocidade"];
  }

  if (!doc["intervalo"].isNull())
  {
    dhtInterval = doc["intervalo"];
  }
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

void controleLed()
{
  static unsigned long ultimaMudanca = 0;
  unsigned long agora = millis();

  if (modoPisca)
  {
    if (agora - ultimaMudanca > tempoEspera)
    {
      estadoLed = !estadoLed;
      ultimaMudanca = agora;
    }
  }

  digitalWrite(pinLed, estadoLed);
}

void dhtSetup()
{
  dht.begin();

  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  Serial.println(F("------------------------------------"));
  Serial.println(F("Temperature Sensor"));
  Serial.print(F("Sensor Type: "));
  Serial.println(sensor.name);
  Serial.print(F("Driver Ver:  "));
  Serial.println(sensor.version);
  Serial.print(F("Unique ID:   "));
  Serial.println(sensor.sensor_id);
  Serial.print(F("Max Value:   "));
  Serial.print(sensor.max_value);
  Serial.println(F("°C"));
  Serial.print(F("Min Value:   "));
  Serial.print(sensor.min_value);
  Serial.println(F("°C"));
  Serial.print(F("Resolution:  "));
  Serial.print(sensor.resolution);
  Serial.println(F("°C"));
  Serial.println(F("------------------------------------"));

  dht.humidity().getSensor(&sensor);
  Serial.println(F("Humidity Sensor"));
  Serial.print(F("Sensor Type: "));
  Serial.println(sensor.name);
  Serial.print(F("Driver Ver:  "));
  Serial.println(sensor.version);
  Serial.print(F("Unique ID:   "));
  Serial.println(sensor.sensor_id);
  Serial.print(F("Max Value:   "));
  Serial.print(sensor.max_value);
  Serial.println(F("%"));
  Serial.print(F("Min Value:   "));
  Serial.print(sensor.min_value);
  Serial.println(F("%"));
  Serial.print(F("Resolution:  "));
  Serial.print(sensor.resolution);
  Serial.println(F("%"));
  Serial.println(F("------------------------------------"));
}

void dhtLoop()
{
  unsigned long dhtTime = millis();
  static unsigned long dhtLastRead;
  if (dhtTime - dhtLastRead > dhtInterval)
  {
    //* LEITURA TEMPERATURA
    sensors_event_t event;
    dht.temperature().getEvent(&event);
    if (isnan(event.temperature))
    {
      Serial.println(F("Error reading temperature!"));
    }
    else
    {
      temperatura = (event.temperature);
      Serial.print(F("Temperature: "));
      Serial.print(event.temperature);
      Serial.println(F("°C"));
    }
    //* LEITURA UMIDADE
    dht.humidity().getEvent(&event);
    if (isnan(event.relative_humidity))
    {
      Serial.println(F("Error reading humidity!"));
    }
    else
    {
      umidade = (event.relative_humidity);
      Serial.print(F("Humidity: "));
      Serial.print(event.relative_humidity);
      Serial.println(F("%"));
    }
    dhtLastRead = dhtTime;
  }
}
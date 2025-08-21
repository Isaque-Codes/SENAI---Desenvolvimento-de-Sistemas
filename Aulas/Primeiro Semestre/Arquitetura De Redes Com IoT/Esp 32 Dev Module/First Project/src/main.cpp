#include <Arduino.h>

#define pinLed 2
#define pinButton 0

void setup()
{
  pinMode(pinLed, OUTPUT);
  pinMode(pinButton, INPUT);
}

void loop()
{
  bool estadoBotao = digitalRead(pinButton);
  if (!estadoBotao)
  {
    digitalWrite(pinLed, HIGH);
  }
  else
  {
    digitalWrite(pinLed, LOW);
  }
}
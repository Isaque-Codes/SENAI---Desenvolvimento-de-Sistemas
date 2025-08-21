#include <Arduino.h>

#define pinButton 4
#define pinLed 5

void setup()
{
  pinMode(pinButton, INPUT_PULLUP);
  pinMode(pinLed, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  //! 1 VARIAVEL DE CONTAGEM, 1 DE CONTAGEM DE TEMPO, 3 DE MANIPULACAO DE BOTAO, 2 DE MANIPULACAO DE TEMPO
  static int count = 0;
  unsigned long currentTime = millis();
  bool stateButton = digitalRead(pinButton);
  static bool previousStateButton = 1;
  static bool lastAction = 1;
  const unsigned long debounceTime = 50;
  static unsigned long previousDebounceTime = 0;

  //! INICIA O TRATAMENTO DE RUIDO DO BOTAO
  //* Marca quando uma mudanca de estado ocorre
  if (stateButton != previousStateButton)
  {
    previousDebounceTime = currentTime;
  }

  //* Verifica se a mudanca de estado esta estavel a tempo suficiente
  if ((currentTime - previousDebounceTime) > debounceTime)
  {
    if (stateButton != lastAction) //* Houve alteracao proposital no botao?
    {
      lastAction = stateButton;
      if (!stateButton)
      {
        count++; //* O botao foi pressionado
        Serial.println(count);
      }
      else
      {
        //* O botao foi solto
      }
    }
  }
  previousStateButton = stateButton;
  //! FINAL DO TRATAMENTO DE RUIDO DO BOTAO
}
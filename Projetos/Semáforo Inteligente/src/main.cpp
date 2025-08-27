#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

#define pinButton 4
#define pinLedRed 19
#define pinLedYellow 5
#define pinLedGreen 18

void setup()
{
  pinMode(pinButton, INPUT_PULLUP);
  pinMode(pinLedRed, OUTPUT);
  pinMode(pinLedYellow, OUTPUT);
  pinMode(pinLedGreen, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Light Phase:       ");
  lcd.setCursor(0, 2);
  lcd.print("Remaining Time: ");

  Serial.begin(115200);
}

void loop()
{
  //! TRATAMENTO DO SEMAFORO
  const unsigned long redTime = 1000;
  const unsigned long yellowTime = 1000;
  const unsigned long greenTime = 50000;

  static unsigned long beginTime = 0;
  unsigned long currentTime = millis();
  static long remainingTime = 0;
  static long updatedRemainingTime;

  static byte trafficLightPhase = 0;
  static bool alteredTime = false;
  static unsigned long progress;
  static unsigned long newGreenTime;

  if (trafficLightPhase == 0)
  {
    digitalWrite(pinLedYellow, LOW);
    digitalWrite(pinLedRed, HIGH);
    remainingTime = redTime - (currentTime - beginTime);

    if (remainingTime <= 0)
    {
      trafficLightPhase = 1;
      beginTime = currentTime;
    }
  }

  else if (trafficLightPhase == 1)
  {
    if (alteredTime == false)
    {
      digitalWrite(pinLedGreen, HIGH);
      digitalWrite(pinLedRed, LOW);
      remainingTime = greenTime - (currentTime - beginTime);
    }
    else
    {
      remainingTime = updatedRemainingTime - (currentTime - beginTime);
    }

    if (remainingTime <= 0)
    {
      trafficLightPhase = 2;
      alteredTime = false;
      beginTime = currentTime;
    }
  }

  else if (trafficLightPhase == 2)
  {
    digitalWrite(pinLedGreen, LOW);
    digitalWrite(pinLedYellow, HIGH);
    remainingTime = yellowTime - (currentTime - beginTime);

    if (remainingTime <= 0)
    {
      trafficLightPhase = 0;
      beginTime = currentTime;
    }
  } //! FIM DO TRATAMENTO DO SEMAFORO
  Serial.print("currentTime: ");
  Serial.println(currentTime);
  Serial.print("remainingTime: ");
  Serial.println(remainingTime);
  Serial.print("beginTime: ");
  Serial.println(beginTime);
  // delay(1000);

  //! TRATAMENTO DO BOTAO
  static int cont = 0;

  unsigned long time = millis();

  static unsigned long lastTime = 0;
  const byte debounceTime = 50;

  bool stateButton = digitalRead(pinButton);
  static bool lastStateButton = 1;
  static bool lastAction = 1;

  if (stateButton != lastStateButton)
  {
    lastTime = time;
  }

  if ((time - lastTime) > debounceTime)
  {
    if (stateButton != lastAction)
    {
      lastAction = stateButton;
      if (!stateButton && trafficLightPhase == 1 && alteredTime == false)
      {
        progress = (greenTime - remainingTime);

        if (remainingTime > (greenTime * 75) / 100)
        {
          alteredTime = true;
          newGreenTime = (greenTime * 60) / 100;
          remainingTime = newGreenTime - progress;
          updatedRemainingTime = remainingTime;
          beginTime = currentTime;
        }
        else if (remainingTime > (greenTime * 50) / 100 && remainingTime <= (greenTime * 75) / 100)
        {
          alteredTime = true;
          newGreenTime = (greenTime * 40) / 100;
          remainingTime = newGreenTime - progress;
          updatedRemainingTime = remainingTime;
          beginTime = currentTime;
        }
        else if (remainingTime > (greenTime * 25) / 100 && remainingTime <= (greenTime * 50) / 100)
        {
          alteredTime = true;
          newGreenTime = (greenTime * 20) / 100;
          remainingTime = newGreenTime - progress;
          updatedRemainingTime = remainingTime;
          beginTime = currentTime;
        }
      }
    }
  }
  lastStateButton = stateButton;
  //! FIM DO TRATAMENTO DO BOTAO

  //! TRATAMENTO DO LCD
  if (trafficLightPhase == 0)
  {
    lcd.setCursor(0, 0);
    lcd.print("Light Phase: RED   ");
    lcd.setCursor(0, 2);
    lcd.print("Remaining Time: ");
    lcd.setCursor(16, 2);
    lcd.print(remainingTime / 1000);
  }

  else if (trafficLightPhase == 1)
  {
    lcd.setCursor(0, 0);
    lcd.print("Light Phase: GREEN ");
    lcd.setCursor(0, 2);
    lcd.print("Remaining Time: ");
    lcd.setCursor(16, 2);
    lcd.print(remainingTime / 1000);
  }

  else if (trafficLightPhase == 2)
  {
    lcd.setCursor(0, 0);
    lcd.print("Light Phase: YELLOW");
    lcd.setCursor(0, 2);
    lcd.print("Remaining Time: ");
    lcd.setCursor(16, 2);
    lcd.print(remainingTime / 1000);
  } //! FIM DO TRATAMENTO DO LCD
}
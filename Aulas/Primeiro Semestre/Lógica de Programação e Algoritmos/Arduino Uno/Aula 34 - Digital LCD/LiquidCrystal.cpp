/* 11/03/2025

-Programar sistema que altere o estado do LED com o uso do botao.
-O sistema deve compreender quando o led esta ligado ou desligado.
-O estado atual do LED deve aparecer no visor lcd.
*/

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

const char pinLedA = 13;
const char pinLedB = 12;

const char pinBotaoA = 8;
const char pinBotaoB = 7;

void setup()
{
  pinMode(pinLedA, OUTPUT);
  pinMode(pinBotaoA, INPUT);

  pinMode(pinLedB, OUTPUT);
  pinMode(pinBotaoA, INPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0); // lcd.home [0,0]
  lcd.print("LED A: OFF");
  lcd.setCursor(0, 1); // coluna / linha
  lcd.print("LED B: OFF");
}

void loop()
{
  // LED A
  bool estadoBotaoA = digitalRead(pinBotaoA);
  static bool estadoAnteriorBotaoA = 0;
  static bool estadoLedA = 0;

  if (!estadoBotaoA && estadoAnteriorBotaoA)
  {
    estadoLedA = !estadoLedA; // botao pressionado
    digitalWrite(pinLedA, estadoLedA);
    lcd.setCursor(7, 0);
    if (estadoLedA)
      lcd.print("ON ");
    else
      lcd.print("OFF");
  }
  estadoAnteriorBotaoA = estadoBotaoA;

  // LED B
  bool estadoBotaoB = digitalRead(pinBotaoB);
  static bool estadoAnteriorBotaoB = 0;
  static bool estadoLedB = 0;

  if (!estadoBotaoB && estadoAnteriorBotaoB)
  {
    estadoLedB = !estadoLedB; // botao pressionado
    digitalWrite(pinLedB, estadoLedB);
    lcd.setCursor(7, 1);
    if (estadoLedB)
      lcd.print("ON ");
    else
      lcd.print("OFF");
  }
  estadoAnteriorBotaoB = estadoBotaoB;
}
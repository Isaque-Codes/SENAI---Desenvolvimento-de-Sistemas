#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); //*Instancia de objetos

void setup()
{
    Serial.begin(115200); // BaudRate
    lcd.init();
    lcd.backlight();
    lcd.print("Hello World");
}

void loop()
{
    static int contagem = 0;
    Serial.println(contagem++);
    delay(300);
}
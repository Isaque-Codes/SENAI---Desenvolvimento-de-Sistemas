/* 12/03/2025

MANIPULACAO DE 5 BOTOES COM 1 ENTRADA ANALOGICA, SELECAO E
REGULAÇAO DA FREQUENCIA DE 2 LEDS COM EXIBICAO DO MONITOR LCD
*/

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define valorBotao1 0
#define valorBotao2 145
#define valorBotao3 329
#define valorBotao4 505
#define valorBotao5 741

#define pinLedA 13
#define pinLedB 12

void setup()
{
  Serial.begin(9600);

  pinMode(pinLedA, OUTPUT);
  pinMode(pinLedB, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print(">LED A OFF");
  lcd.setCursor(1, 1);
  lcd.print("LED B OFF");
}

void loop()
{
  // VARIAVEL LOCAL DA SELECAO DO LED
  static bool posicao = 0;

  // VARIAVEIS LOCAIS DOS BOTOES
  static bool alteracao = 1;
  int valorLeitura = analogRead(A0);
  static int valorAnteriorLeitura = 1023;

  // VARIAVEIS LOCAIS DA FREQUENCIA ANALOGICA DOS LEDS
  static byte frequenciaLedA = 0;
  static byte frequenciaLedB = 0;

  // VARIAVEIS LOCAIS DO ACIONAMENTO DOS LEDS
  static bool estadoLedA = 0;
  static bool estadoLedB = 0;

  // TRATAMENTO DOS BOTOES
  // BOTAO 1 PRESSIONADO
  if (valorAnteriorLeitura == 1023 && valorLeitura == valorBotao1)
  {
    posicao = 0;
    alteracao = 1;
  }

  // BOTAO 2 PRESSIONADO
  else if (valorAnteriorLeitura == 1023 &&
           valorLeitura >= valorBotao2 * 0.9 &&
           valorLeitura <= valorBotao2 * 1.1)
  {
    posicao = 1;
    alteracao = 1;
  }

  // BOTAO 3 PRESSIONADO
  else if (valorAnteriorLeitura == 1023 &&
           valorLeitura >= valorBotao3 * 0.9 &&
           valorLeitura <= valorBotao3 * 1.1)
  {
    if ((!posicao) && estadoLedA)
    {
      if (frequenciaLedA > 0)
        frequenciaLedA -= 10;
      else if (frequenciaLedA == 0)
        estadoLedA == 0;
    }

    else if ((posicao) && estadoLedB)
    {
      if (frequenciaLedB > 0)
        frequenciaLedB -= 10;
      else if (frequenciaLedB == 0)
        estadoLedB == 0;
    }
    alteracao = 1;
  }

  // BOTAO 4 PRESSIONADO
  else if (valorAnteriorLeitura == 1023 &&
           valorLeitura >= valorBotao4 * 0.9 &&
           valorLeitura <= valorBotao4 * 1.1)
  {
    if (!posicao && estadoLedA)
    {
      if (frequenciaLedA < 100)
        frequenciaLedA += 10;
    }
    if (posicao && estadoLedB)
    {
      if (frequenciaLedB < 100)
        frequenciaLedB += 10;
    }
    alteracao = 1;
  }

  // BOTAO 5 PRESSIONADO
  else if (valorAnteriorLeitura == 1023 &&
           valorLeitura >= valorBotao5 * 0.9 &&
           valorLeitura <= valorBotao5 * 1.1)
  {
    if (!posicao)
    {
      estadoLedA = !estadoLedA;
      if (estadoLedA && frequenciaLedA == 0)
        frequenciaLedA = 10;
    }
    else
    {
      estadoLedB = !estadoLedB;
      if (estadoLedB && frequenciaLedB == 0)
        frequenciaLedB = 10;
    }
    alteracao = 1;
  }
  valorAnteriorLeitura = valorLeitura;
  // FIM DO TRATAMENTO DOS BOTOES

  if (alteracao)
  {
    alteracao = 0;

    // TRATAMENTO DO DISPLAY
    if (!posicao)
    {
      lcd.setCursor(0, 1);
      lcd.print(" ");
      lcd.setCursor(0, 0);
      lcd.print(">");
    }
    else
    {
      lcd.setCursor(0, 0);
      lcd.print(" ");
      lcd.setCursor(0, 1);
      lcd.print(">");
    }
    if (!estadoLedA)
    {
      lcd.setCursor(7, 0);
      lcd.print("OFF  ");
    }
    else
    {
      lcd.setCursor(7, 0);
      lcd.print(frequenciaLedA);
      lcd.print(" % ");
    }
    if (!estadoLedB)
    {
      lcd.setCursor(7, 1);
      lcd.print("OFF  ");
    }
    else
    {
      lcd.setCursor(7, 1);
      lcd.print(frequenciaLedB);
      lcd.print(" % ");
    } // FIM DO TRATAMENTO DO DISPLAY

    // TRATAMENTO DOS LEDS
    if (frequenciaLedA == 0)
    {
      digitalWrite(pinLedA, LOW);
    }
    else
    {
      analogWrite(pinLedA, frequenciaLedA);
    }

    if (frequenciaLedB == 0)
    {
      digitalWrite(pinLedB, LOW);
    }
    else
    {
      analogWrite(pinLedB, frequenciaLedB);
    }
  } // FIM DO TRATAMENTO DOS LEDS
}
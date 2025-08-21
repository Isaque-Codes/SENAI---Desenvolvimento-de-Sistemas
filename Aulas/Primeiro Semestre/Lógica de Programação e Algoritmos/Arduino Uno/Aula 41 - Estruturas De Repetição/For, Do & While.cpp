/* 20/03/2025

-1: Fazer um programa que calcule a tabuada de um numero e a
mostre no monitor serial.

-2: Fazer um programa que avalie um numero e verifique se este
numero esta dentro de um array, caso esse numero seja encontrado
mostre no console "Numero encontrado" caso contrario "Numero não
encontrado".

-3: Fazer um programa que acenda 3 leds um por um, mantenha-os
acesos, por 3 segundos e em seguida apague-os um por um

-4: Fazer um programa que acenda e apague 3 leds, de forma
progressiva, enquanto um botão estiver pressionado.
*/

#define pinLedRed 13
#define pinLedYellow 12
#define pinLedGreen 8

#define pinLedBlue 7
#define pinLedWhite 4
#define pinLedOrange 2

void setup()
{
  Serial.begin(9600);

  // EXERCICIO 1
  int numero = 7;
  int tabuada;

  for (int cont = 0; cont <= 9; cont++)
  {
    tabuada = numero * (cont + 1);
    Serial.println(tabuada);
    delay(500);
  } // FIM DO EXERCICIO 1

  // EXERCICIO 2
  int array[10] = {1, 3, 7, 5, 6, 9, 19, 44, 33, 55};
  int numeroComparado = 55;
  bool resultado = false;

  for (int X = 0; X < 10; X++)
  {
    if (numeroComparado == array[X])
    {
      resultado = true;
    }
  }

  if (resultado == true)
    Serial.println("Numero Encontrado");
  else
    Serial.println("Numero Nao Encontrado");
  // FIM DO EXERCICIO 2

  // EXERCICIO 3
  pinMode(pinLedRed, OUTPUT);
  pinMode(pinLedYellow, OUTPUT);
  pinMode(pinLedGreen, OUTPUT);

  int Leds1[3] = {13, 12, 8};

  for (int Z = 0; Z <= 2; Z++)
  {
    digitalWrite(Leds1[Z], HIGH);
    delay(1000);
  }
  for (int Z = 0; Z <= 2; Z++)
  {
    digitalWrite(Leds1[Z], LOW);
    delay(1000);
  } // FIM DO EXERCICIO 3

  // EXERCICIO 4
  int pinBotao = 11;
  pinMode(pinBotao, INPUT_PULLUP);
  bool estadoBotao;
  int pinLeds[3] = {7, 4, 2};
  for (int i = 0; i < 3; i++)
  {
    pinMode(pinLeds[i], OUTPUT);
  }

  do
  {
    estadoBotao = digitalRead(pinBotao);
    if (estadoBotao == LOW)
    {
      for (int i = 0; i < 3 && digitalRead(pinBotao) == LOW; i++)
      {
        digitalWrite(pinLeds[i], HIGH);
        delay(1000);
      }

      for (int i = 0; i < 3 && digitalRead(pinBotao) == LOW; i++)
      {
        digitalWrite(pinLeds[i], LOW);
        delay(1000);
      }
    }
    else
    {
      for (int i = 0; i < 3; i++)
      {
        digitalWrite(pinLeds[i], LOW);
      }
    }
  } while (true);
  // FIM DO EXERCICIO 4
}

void loop()
{
}
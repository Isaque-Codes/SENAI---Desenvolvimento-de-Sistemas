/* Criar programa que avalie um valor, o converta de um intervalo de
0 a 1023 para um novo intervalo de 0 a 100, em seguida colocar o
resultado entre os limites de 20 e 80. Caso o valor exceda os
limites, acenda um led de alerta e mostre no terminal a mensagem
"o valor X excedeu os limites, valor reajustado para Y"

-Acender o led caso o numero seja par.
*/

#define pinLED_WHITE 13

int Valor = 555;

int Resultado = 0;

int ResultadoFinal = 0;

void setup()
{
  Serial.begin(9600);

  pinMode(pinLED_WHITE, OUTPUT);

  Resultado = map(Valor, 0, 1023, 0, 100);
  Serial.println("Resultado: ");
  Serial.println(Resultado);

  if (Resultado < 20 || Resultado > 80)
  {
    digitalWrite(pinLED_WHITE, HIGH);
  }

  if ((Resultado % 2) == 0)
  {
    digitalWrite(pinLED_WHITE, HIGH);
  }
  
  ResultadoFinal = constrain(Resultado, 20, 80);
  Serial.println("Resultado Final: ");
  Serial.println(ResultadoFinal);
}

void loop()
{
}
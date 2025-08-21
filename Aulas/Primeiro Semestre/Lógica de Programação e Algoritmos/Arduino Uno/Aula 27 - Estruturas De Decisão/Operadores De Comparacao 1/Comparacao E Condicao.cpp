/* 25/02/2025

== Verifica se 2 valores sao iguais
!= Verifica se 2 valores sao diferentes
<  Verifica se e menor que
>  Verifica se e maior que
<= Verifica se e menor ou igual a
>= Verifica se e maior ou igual a

if (se algo) {fazer algo}
else if (se algo) {fazer algo)
else {fazer algo}
if (X & Y) E
if (X or [ou] || y) OU

switch (VariavelAvaliada)
{
case x: [caso seja x]
break ;
default:
}

bool condicao = true [ou] false
*/

//

int temperatura = 24;

int umidade = 71;

int dia = 1;

#define pinLED_RED 13
#define pinLED_ORANGE 8
#define pinLED_YELLOW 7
#define pinLED_GREEN 4
#define pinLED_BLUE 2

void setup()
{
  Serial.begin(9600);

  if (temperatura >= 30)
  {
    Serial.println("Esta quente pra canario");
  }
  else if (temperatura <= 30 & temperatura >= 24)
  {
    Serial.println("Se correr morre");
  }
  else if (temperatura <= 24 & temperatura >= 18)
  {
    Serial.println("Deus existe");
  }
  else if (temperatura <= 18 & temperatura >= 6)
  {
    Serial.println("Um milagre");
  }
  else
  {
    Serial.println("Impossivel");
  }

  if (temperatura < 12 || umidade > 70)
  {
    Serial.println("Alerta");
  }

  pinMode(pinLED_RED, OUTPUT);
  pinMode(pinLED_ORANGE, OUTPUT);
  pinMode(pinLED_YELLOW, OUTPUT);
  pinMode(pinLED_GREEN, OUTPUT);
  pinMode(pinLED_BLUE, OUTPUT);

  switch (dia)
  {
  case 1:
    Serial.print("Segunda-feira");
    digitalWrite(pinLED_RED, HIGH);
    break;
  case 2:
    Serial.print("Terca-feira");
    digitalWrite(pinLED_ORANGE, HIGH);
    break;
  case 3:
    Serial.print("Quarta-feira");
    digitalWrite(pinLED_YELLOW, HIGH);
    break;
  case 4:
    Serial.print("Quinta-feira");
    digitalWrite(pinLED_GREEN, HIGH);
    break;
  case 5:
    Serial.print("Sexta-feira");
    digitalWrite(pinLED_BLUE, HIGH);
    break;
  default:
    Serial.print("Fim de semana");
  }
}

void loop()
{
}
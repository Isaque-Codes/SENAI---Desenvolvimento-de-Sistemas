/* 26/02/2025

-Controle de temperatura: liga LED acima de 30 graus

-Bateria: aciona alerta quando bateria estiver entre 20% e 80%
*/

#define pinLED_BLUE 13
#define pinLED_GREEN 2
#define pinLED_YELLOW 4
#define pinLED_RED 7

float temperatura = 37;

float bateria = 33;

void setup()
{
  Serial.begin(9600);

  pinMode(pinLED_BLUE, OUTPUT);
  pinMode(pinLED_GREEN, OUTPUT);
  pinMode(pinLED_YELLOW, OUTPUT);
  pinMode(pinLED_RED, OUTPUT);

  if (temperatura > 30)
  {
    digitalWrite(pinLED_BLUE, HIGH);
    Serial.println("Temperatura superior a 30 graus");
  }

  if (bateria >= 60 & bateria < 80)
  {
    digitalWrite(pinLED_GREEN, HIGH);
    Serial.println("A bateria esta ok");
  }

  else if (bateria >= 40 & bateria < 60)
  {
    digitalWrite(pinLED_YELLOW, HIGH);
    Serial.println("A bateria esta diminuindo");
  }

  else if (bateria >= 20 & bateria < 40)
  {
    digitalWrite(pinLED_RED, HIGH);
    Serial.println("A bateria esta se esgotando");
  }
}

void loop()
{
}
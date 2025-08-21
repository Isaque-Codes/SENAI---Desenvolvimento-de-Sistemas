// Comentario Uni-linha
/* Comentario Multi-linha
19/02/2025
Autor: Isaque
Atividade: Semaforos paralelos simultaneos
Descricao: Primeiro codigo em C/C++
*/

#define pinLEDVERDE 13
#define pinLED_VERDE 2
#define pinLEDAMARELO 12
#define pinLED_AMARELO 4
#define pinLEDVERMELHO 8
#define pinLED_VERMELHO 7

#define tempoPisca_3s 3000
#define tempoPisca_2s 2000

void setup()
{
  pinMode(pinLEDVERDE, OUTPUT); // define pino como saida
  pinMode(pinLEDAMARELO, OUTPUT);
  pinMode(pinLEDVERMELHO, OUTPUT);

  pinMode(pinLED_VERDE, OUTPUT);
  pinMode(pinLED_AMARELO, OUTPUT);
  pinMode(pinLED_VERMELHO, OUTPUT);
}

void loop()
{
  digitalWrite(pinLEDVERDE, HIGH); // aciona pino
  digitalWrite(pinLED_VERMELHO, HIGH);
  delay(tempoPisca_3s);
  digitalWrite(pinLEDVERDE, LOW); // desaciona pino

  digitalWrite(pinLEDAMARELO, HIGH);
  delay(tempoPisca_2s);
  digitalWrite(pinLED_VERMELHO, LOW);
  digitalWrite(pinLEDAMARELO, LOW);

  digitalWrite(pinLED_VERDE, HIGH);
  digitalWrite(pinLEDVERMELHO, HIGH);
  delay(tempoPisca_3s);
  digitalWrite(pinLED_VERDE, LOW);

  digitalWrite(pinLED_AMARELO, HIGH);
  delay(tempoPisca_2s);
  digitalWrite(pinLED_AMARELO, LOW);
  digitalWrite(pinLEDVERMELHO, LOW);
}
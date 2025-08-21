/*12/03/2025

Programar sistema para medir a tensao eletrica que passa pelo
potenciometro, em milivolts.

O potenciometro tem 10 bytes, portanto, oscila entre 0 e 1023.
*/

#define pinAnalogico A0
double tensao;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int leituraA0 = analogRead(pinAnalogico);
  tensao = (leituraA0 / 204.6 * 1000);
  Serial.print("Tensao = ");
  Serial.print(tensao, 0);
  Serial.println("mV");
}
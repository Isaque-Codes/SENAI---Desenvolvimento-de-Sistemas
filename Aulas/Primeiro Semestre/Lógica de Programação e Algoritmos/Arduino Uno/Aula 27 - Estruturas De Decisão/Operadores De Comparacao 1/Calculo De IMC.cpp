// Calculo de IMC

float altura = 1.83;
float peso = 70;
float IMC;

void setup()
{
  Serial.begin(9600);

  IMC = peso / sq(altura);
  Serial.print("IMC = ");
  Serial.print(IMC);

  if (IMC >= 40)
  {
    Serial.println(": Obesidade morbida");
  }
  else if (IMC >= 30 & IMC <= 39.9)
  {
    Serial.println(": Obesidade");
  }
  else if (IMC >= 25 & IMC <= 29.9)
  {
    Serial.println(": Sobrepeso");
  }
  else if (IMC >= 20 & IMC <= 24.9)
  {
    Serial.println(": Peso normal");
  }
  else if (IMC >= 14.5 & IMC <= 20)
  {
    Serial.println(": Peso abaixo do normal");
  }
  else if (IMC <= 14.5)
  {
    Serial.print(": Desnutricao");
  }
}

void loop()
{
}
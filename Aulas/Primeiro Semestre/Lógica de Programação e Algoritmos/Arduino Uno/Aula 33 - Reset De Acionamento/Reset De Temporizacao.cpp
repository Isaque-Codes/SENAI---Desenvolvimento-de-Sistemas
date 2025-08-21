/* 10/03/2025

Como resetar o acionamento do botao

digitalRead: recebe valor da leitura
*/

#define pinBotao 10
#define pinLed 2

int contagem = 0;
bool estadoAnteriorBotao = 0;

void setup()
{
  Serial.begin(9600);

  pinMode(pinBotao, INPUT);
  pinMode(pinLed, OUTPUT);
}

void loop()
{
  bool estadoAtualBotao = digitalRead(pinBotao); // ou estadoAtualBotao == 1
  if (estadoAtualBotao && !estadoAnteriorBotao) // ou estadoAnteriorBotao == 0
  {
    contagem++;
    Serial.println(contagem);
  }
  estadoAnteriorBotao = estadoAtualBotao;

  if (contagem % 2 != 0)
    digitalWrite(pinLed, HIGH);
  else
    digitalWrite(pinLed, LOW);
}
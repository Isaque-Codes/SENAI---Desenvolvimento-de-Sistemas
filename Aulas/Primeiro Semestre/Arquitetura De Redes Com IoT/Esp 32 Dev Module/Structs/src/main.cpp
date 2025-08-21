#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

struct Pessoa
{
  char nome[20];
  int idade;
  float altura;
  bool calvice;
};

struct Rgb
{
  char nome[20];
  byte r;
  byte g;
  byte b;
};

Pessoa aluno;
Pessoa professor;

Rgb red;
Rgb yellow;
Rgb green;
Rgb blue;

void setup()
{
  Serial.begin(9600);

  strcpy(red.nome, "vermelhoEscuro");
  red.r = 148;
  red.g = 41;
  red.b = 30;

  strcpy(yellow.nome, "amarelo");
  red.r = 235;
  red.g = 191;
  red.b = 51;

  strcpy(green.nome, "verdeIntenso");
  red.r = 60;
  red.g = 216;
  red.b = 51;

  strcpy(blue.nome, "azul");
  red.r = 35;
  red.g = 114;
  red.b = 186;

  Serial.printf("Cor: %s, RGB: ", red.nome);
  Serial.printf("(%d, ", red.r);
  Serial.printf("%d, ", red.g);
  Serial.printf("%d)\n\r", red.b);

  Serial.printf("Cor: %s, RGB: ", yellow.nome);
  Serial.printf("(%d, ", yellow.r);
  Serial.printf("%d, ", yellow.g);
  Serial.printf("%d)\n\r", yellow.b);

  Serial.printf("Cor: %s, RGB: ", green.nome);
  Serial.printf("(%d, ", green.r);
  Serial.printf("%d, ", green.g);
  Serial.printf("%d)\n\r", green.b);

  Serial.printf("Cor: %s, RGB: ", blue.nome);
  Serial.printf("(%d, ", blue.r);
  Serial.printf("%d, ", blue.g);
  Serial.printf("%d)\n\r", blue.b);

  strcpy(aluno.nome, "Isaque");
  aluno.idade = 25;
  aluno.altura = 1.83;
  aluno.calvice = true;

  strcpy(professor.nome, "Odirlei");
  professor.idade = 47;
  professor.altura = 1.80;
  professor.calvice = true;

  Serial.printf("Meu nome eh: %s \n\r", aluno.nome);
  Serial.printf("E tenho %d anos \n\r", aluno.idade);
  Serial.printf("Tenho %.2f metros de altura\n\r", aluno.altura);
  Serial.printf("E %s calvo\n\r", aluno.calvice ? "sou" : "nao sou");

  Serial.printf("Meu nome eh: %s \n\r", professor.nome);
  Serial.printf("E tenho %d anos \n\r", professor.idade);
  Serial.printf("Tenho %.2f metros de altura\n\r", professor.altura);
  Serial.printf("E %s calvo\n\r", professor.calvice ? "sou" : "nao sou");
}

void loop()
{
}
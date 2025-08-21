/* 21/02/2025

TAMANHO DAS VARIAVEIS EM BYTES

int = 32767; em 32768 quebra
*/

bool teste1 = 48;
char teste2 = 137;
byte teste3 = 255;
int teste4 = 7;
unsigned int teste5 = 45;
long teste6 = 57;
unsigned long teste7 = 89;
float teste8 = 32;
double teste9 = 33;

void setup()
{
  // Serial.print (ln) para pular linha

  Serial.begin(9600);
  Serial.println("Tamanho dos tipos de variaveis em bytes");

  Serial.print("bool: ");
  Serial.println(sizeof(bool));
  // so aceita 0 e 1

  Serial.print("char: ");
  Serial.println(sizeof(char));
  // aceita letras 0 a 255

  Serial.print("byte: ");
  Serial.println(sizeof(byte));
  // 0 a 255

  Serial.print("int: ");
  Serial.println(sizeof(int));
  //-32768 a 32767
  //"int(X)_t: " [X: 8, 16, 32, 64] "uint(X)_t: "

  Serial.print("unsigned int: ");
  Serial.println(sizeof(unsigned int));
  // 0 a 65535

  Serial.print("long: ");
  Serial.println(sizeof(long));
  //-2.147.483.648 a 2.147.483.647

  Serial.print("unsigned long: ");
  Serial.println(sizeof(unsigned int));
  // 0 a 4.294.967.295

  Serial.print("float: ");
  Serial.println(sizeof(float));
  //-2.147.483.648 a 2.147.483.647
  // aceita virgula
  // maximo positivo 3,4028235 X 10*38
  // minimo positivo 1.175494 X 10*-38
  // minimo negativo 1.175494 X 10*-38
  // maximo negativo 3,4028235 X 10*38

  Serial.print("double: ");
  Serial.println(sizeof(double));
  //-2.147.483.648 a 2.147.483.647
}

void loop()
{
}
/* 24/02/2025

DECLARACAO DE VARIAVEIS GLOBAIS E SUAS OPERACOES ARITMETICAS

SOMA              X + Y
SUBTRACAO         X - Y
MULTIPLICACAO     X * Y
DIVISAO           X / Y
POTENCIACAO       pow (X , Y)
QUADRADO          sq (X)
RADICICACAO       sqrt (X)
MODULO            abs (X * -X ou -1)
RESTRICAO         constrain (X, -a, b)
REMAPEAMENTO      map (X, DeMenor, DeMaior, ParaMenor, ParaMaior)
ATRIBUICAO        X += a   /   Y -= b   ou   numeroX = numeroX +a
INCREMENTACAO     X++ [pos] ++X [pre]
DECREMENTACAO     X-- [pos] --X [pre]
RESTO             X % 2 [par] X % 3 [impar]
*/

int numeroA = 14;
int numeroB = 5;
int resultado = 0;
float resultadoReal = 0;

float Valor = 700;
float DeMenor = 0;
float DeMaior = 1000;
float ParaMenor = 0;
float ParaMaior = 10;

void setup()
{
  Serial.begin(9600);

  // SOMA (recebe: =)
  resultado = numeroA + numeroB;
  Serial.print("A soma do numero A com o B: ");
  Serial.println(resultado);

  // SUBTRACAO
  resultado = numeroB - numeroA;
  Serial.print("A subtracao do numero B pelo A: ");
  Serial.println(resultado);

  // MULTIPLICACAO
  resultado = numeroA * numeroB;
  Serial.print("A multiplicacao do numero A pelo B: ");
  Serial.println(resultado);

  // DIVISAO
  resultado = numeroA / numeroB;
  Serial.print("A divisao do numero A pelo B: ");
  Serial.println(resultado);
  resultado = numeroA % numeroB;
  Serial.print("E sobra: ");
  Serial.println(resultado);
  resultadoReal = (float)numeroA / (float)numeroB;
  Serial.print("Ou ");
  Serial.println(resultadoReal, 1); // limite de casas decimais

  // POTENCIACAO
  resultado = pow(numeroA, numeroB); //"a" elevado a "b"
  Serial.print("Numero A elevado pelo numero B: ");
  Serial.println(resultado);

  // QUADRADO
  resultado = sq(numeroA); // numero elevado ao quadrado
  Serial.print("Numero A elevado ao quadrado: ");
  Serial.println(resultado);

  // RADICIACAO
  resultado = sqrt(numeroA);
  Serial.print("Raiz quadrada do numero A: ");
  Serial.println(resultadoReal);

  // MODULO
  resultado = abs(numeroA * -numeroA);
  Serial.print("Modulo do numero A: ");
  Serial.println(resultado);

  // RESTRICAO
  resultado = constrain(numeroA, -3, 5); // restringe a variavel aos limites -3 e 5
  Serial.print("Valor restringido do numero A: ");
  Serial.println(resultado);

  // REMAPEAMENTO
  // VALOR DE MENOR/MAIOR PARA MENOR/MAIOR
  resultadoReal = map(numeroA, 0, 20, 0, 10);
  Serial.print("Remapeamento do numero A: ");
  Serial.println(resultado);
  // LOGICA DO REMAPEAMENTO
  // resultado = (Valor - DeMenor) * (ParaMaior-ParaMenor) + ParaMenor ;

  // OPERADORES DE ATRIBUICAO
  // numeroA = numeroA +5 ; OU
  numeroA += 5;
  Serial.println(numeroA += 5);

  numeroA -= 5;
  Serial.println(numeroA -= 5);

  // INCREMENTAR A VARIAVEL
  // numeroA = numeroA +1 ; OU
  numeroA++; // pos incremento
  Serial.println(numeroA);
  ++numeroA; // pre incremento
  Serial.println(numeroA);

  // DECREMENTAR A VARIAVEL
  // numeroA = numeroA -1 ; OU
  numeroA--; // pos incremento
  Serial.println(numeroA);
  --numeroA; // pre incremento
  Serial.println(numeroA);
}

void loop()
{
}
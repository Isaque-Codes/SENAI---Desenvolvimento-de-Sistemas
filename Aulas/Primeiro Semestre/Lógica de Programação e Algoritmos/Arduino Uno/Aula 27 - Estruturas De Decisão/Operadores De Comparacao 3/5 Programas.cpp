/* 27/02/2025

-Fazer programa que avalia numeros inteiros como positivo ou negativo

-Fazer programa que exiba nome, cargo e salario de funcionarios.
Se o salario for inferior a 1000 reais, acrescentar 10% no valor

-Fazer programa que acrescenta aumento de 30% a funcionarios com
salario inferior a 500 reais

-Fazer programa que defina o maior valor entre dois numeros

-Fazer programa que avalie 4 notas de alunos, calcule e imprima a
media aritmetica das notas. Media minima para aprovacao: 7,0
*/

int numero = -731;

float salario_1 = 1370;
float reajuste_1 = 0;

float salario_2 = 369;
float reajuste_2 = 0;

float valor_1 = 45678;
float valor_2 = 93157;

float nota_1 = 6.5;
float nota_2 = 5.7;
float nota_3 = 7.3;
float nota_4 = 6.9;
float media = 0;

void setup()
{
  Serial.begin(9600);

  // 1
  if (numero < 0)
  {
    Serial.print(numero);
    Serial.println(": NEGATIVO");
  }
  else
  { // if (numero >=0)
    Serial.print(numero);
    Serial.println(": POSITIVO");
  }

  // 2
  Serial.println("nome: joana");
  Serial.println("cargo: recepcionista");
  if (salario_1 >= 1000)
  {
    Serial.print("salario: ");
    Serial.println(salario_1);
  }
  else
  { // if (salario_1 <1000)
    reajuste_1 = (salario_1 * 110) / 100;
    Serial.print("salario reajustado: ");
    Serial.println(reajuste_1);
  }

  // 3
  Serial.println("nome: bernadete");
  Serial.println("cargo: engenheira quimica");
  if (salario_2 >= 500)
  {
    Serial.print("salario: ");
    Serial.println(salario_2);
  }
  else
  { // if (salario_2 <500)
    reajuste_2 = (salario_2 * 130) / 100;
    Serial.print("salario reajustado: ");
    Serial.println(reajuste_2);
  }

  // 4
  Serial.print("maior valor: ");
  if (valor_1 > valor_2)
  {
    Serial.println(valor_1);
  }
  else if (valor_2 > valor_1)
  {
    Serial.println(valor_2);
  }
  else
  { // if (valor_1 ==valor_2)
    Serial.println("ambos sao iguais");
  }

  // 5
  Serial.print("media aritmetica: ");
  media = (nota_1 + nota_2 + nota_3 + nota_4) / 4;
  Serial.print(media);
  if (media >= 7.0)
  {
    Serial.print(", Aprovado");
  }
  else
  { // if (media <7)
    Serial.print(", Reprovado");
  }
}

void loop()
{
}
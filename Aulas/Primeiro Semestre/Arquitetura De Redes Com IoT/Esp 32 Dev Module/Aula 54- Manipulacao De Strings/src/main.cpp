#include <Arduino.h>

/* -------------------------------------------------------------------------- */
/*                              AULA SOBRE STRING'S                             */
/* -------------------------------------------------------------------------- */

// * FORMAS DE ESCREVER PALAVRAS EM C

char palavra[10] = "OLA MUNDO";
char palavra2[100] = {'O', 'L', 'A', ' ', 'M', 'U', 'N', 'D', 'O', '\0'};

String palavra3 = "HOJE EH QUINTA";

void setup()
{
  Serial.begin(9600);
  Serial.println();

  Serial.println(palavra);
  Serial.println(palavra2);

  strcpy(palavra, "SENAI");

  if (strcmp(palavra, "SENAI") == 0) // SE FOR IGUAL RETORNA ZERO
  {
    Serial.println("SAO IGUAIS");
  }
  //!     ↓
  if (strncmp(palavra2, "OLA", 3) == 0)
  {
    Serial.println("As primeiras letras da palavra é OLA");
  }

  if (strstr(palavra2, "MUNDO"))
  {
    Serial.println("Palavra MUNDO detectada");
  }

  //* ----------------------------------------------------------------------------

  Serial.println(palavra3.length());          // retorna o numero de letras do objeto da classe String
  Serial.println(palavra3.charAt(8));         // retorna a oitava posicao da palavra
  Serial.println(palavra3.substring(8, 14));  // Retorna a 8° até a 14°posição
  Serial.println(palavra3.indexOf('U'));      // Retorna a posição da primeira ocorrência da letra procurada
  Serial.println(palavra3.lastIndexOf('E'));  // Retorna a posição da ultima ocorrência da letra procurada
  if (palavra3.equals("HOJE EH QUINTA") == 1) // Retorna verdadeiro se forem iguais
    Serial.println("São iguais");

  if (palavra3.equalsIgnoreCase("hoje eh quinta") == 1) // Retorna verdadeiro se forem iguais ignorando letras maiúsculas/minusculas
    Serial.println("São iguais");

  if (palavra3.startsWith("HOJE") == 1) // Retorna verdadeiro se a palavra começar com determinado texto
    Serial.println("Começa com HOJE");

  if (palavra3.endsWith("INTA") == 1) // Retorna Verdadeiro se a palavra terminar com determinado texto
    Serial.println("Termina com INTA");

  String valor = "123";
  int valorNumerico = valor.toInt(); // Converte o valor do texto em valor numerico de "123" para 123 (numero)

  String valor2 = "10.5";
  float valorNumerico2 = valor2.toFloat();

  //* EXEMPLO: transforme o numero do texto em valor numerico tipo inteiro

  String mensagem = "Valor = 50";

  int tamanho = mensagem.length(); // MEDIR O TAMANHO DO TEXTO

  String extracao = mensagem.substring(8, tamanho); // EXTRAIR O NUMERO INICIANDO EM UMA POSICAO CONHECIDA ATÉ O FIM DO TEXTO

  int numero = extracao.toInt(); // TRANSFORME O CONTEUDO EXTRAIDO EM UM NUMERO INTEIRO

  Serial.println(numero * 2); // UTILIZE O NUMERO SEM MODERAÇÃO... HAHAHA

  //! CONTINUANDO

  palavra3.toLowerCase(); // Alterar todas as letras para minusculas
  Serial.println(palavra3);
  palavra3.toUpperCase(); // Alterar todas para maiusculas
  Serial.println(palavra3);

  String textoLed = "Led = ON";
  Serial.println(textoLed);
  textoLed.replace("ON", "OFF"); // Substitui uma palavra no texto por outra
  Serial.println(textoLed);      //"Led = OFF";

  String novaFrase = "Texto      "; // varios espaços
  novaFrase.trim();                 // Remove os espaços do fim do texto

  novaFrase.concat(" adicionado"); // Adiciona um texto a string
  Serial.println(novaFrase);       // Texto adicionado
}

void loop()
{
}

char nome[20];
char nome2[20];

void setup()
{
  Serial.begin(9600);
  strcpy(nome, "Isaque"); //* Atribui string a uma cadeia de caracteres
  Serial.println(nome);

  strcat(nome, "Silva"); //* Concatena strings a um vetor
  Serial.println(nome);

  int tamanho = strlen(nome); //* Informa o tamanho do dado
  Serial.println(tamanho);

  //! Compara 2 strings e retorna ZERO se forem IGUAIS
  if (strcmp("IsaqueSilva", nome) == 0)
    Serial.println("Sao iguais");
  else
    Serial.println("Sao diferentes");

  if (strcmp("Isaque Silva", nome) == 0)
    Serial.println("Sao iguais");
  else
    Serial.println("Sao diferentes");

  //! COMPARA N caracteres a partir da esquerda entre 2 NOMES
  if (strncmp(nome, nome2, 6) == 0)
    Serial.println("Os 6 primeiros digitos sao iguais");
  else
    Serial.println("Os 6 primeiros digitos sao diferentes");

  //! CONCATENA informacoes em uma VARIAVEL
  char buffer[50];
  int temperatura = 25;
  sprintf(buffer, "Temperatura: %d°C", temperatura); //* Adiciona a um vetor um texto como um printf
  Serial.println(buffer);
}

void loop()
{
}
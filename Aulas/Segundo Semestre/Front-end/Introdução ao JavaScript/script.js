// Exercícios de Condicionais

// Nível Básico

// 1. Verificar maioridade:
// Peça ao usuário uma idade.
// Use um if-else para verificar se ele é maior ou menor de idade.

let idade = Number(prompt("Digite a sua idade.")) >= 18 ? alert("Maioridade.") : alert("Menoridade.");

// 2. Verificar se um número é positivo ou negativo:
// Peça ao usuário para inserir um número.
// Use um if-else para verificar se o número é positivo, negativo.
// OBS: Por hora considere o 0 como sendo um número negativo.

let numero = Number(prompt("Insira um valor numerico.")) > 0 ? alert("Valor positivo.") : alert("Valor negativo.");

// 3. Aprovação em uma prova:
// O usuário insere a nota de um aluno (0 a 100).
// Se a nota for maior ou igual a 60, exibir "Aprovado", senão "Reprovado".

let nota = Number(prompt("Insira sua nota.")) >= 60 ? alert("Aprovado.") : alert("Reprovado");

// 4. Verificar se um número é positivo, negativo ou zero:
// Peça ao usuário para inserir um número.
// Use um if-else para verificar se o número é positivo, negativo ou zero.

let numero2 = Number(prompt("Insira um valor numerico."));
if (numero2 > 0) {
    alert("Valor positivo.");
} else if (numero2 < 0) {
    alert("Valor negativo.");
} else if (numero2 === 0) {
    alert("O numero eh 0.");
}


// 5. Classificação de idade:
// Peça ao usuário para inserir sua idade.
// Exiba se ele é "Criança" (0-12), "Adolescente" (13-17) ou "Adulto" (18+).

let numero3 = Number(prompt("Insira a sua idade."));
if (numero3 >= 0 && numero3 <= 12) {
    alert("Crianca.");
} else if (numero3 >= 13 && numero3 <= 17) {
    alert("Adolescente.");
} else if (numero3 >= 18) {
    alert("Adulto.");
}

// 6. Verificar se um número é par ou ímpar:
// Peça ao usuário para inserir um número.
// Use o operador % para verificar se o número é divisível por 2.

let numero4 = Number(prompt("Insira um valor numerico."));
if (numero4 % 2 === 0) {
    alert("O numero eh par");
} else {
    alert("O numero eh impar.");
}

// Nível Intermediário

// 1. Calculadora simples:
// Peça dois números e uma operação (+, -, *, /).
// Use um if-else para calcular o resultado e exibi-lo.

let operador = String(prompt("Diga qual operacao quer realizar (Insira +, -, * ou /)"));
let valor1 = Number(prompt("Insira o primeiro valor a ser calculado."));
let valor2 = Number(prompt("Insira o segundo valor."));
let resultado;


// 2. Maior entre três números:
// O usuário insere três números.
// Use if-else para determinar e exibir o maior.

let numero5 = Number(prompt("Insira um numero."));
let numero6 = Number(prompt("Insira um numero diferente."));
let numero7 = Number(prompt("Insira outro numero diferente."));
if (numero5 > numero6 && numero5 > numero7) {
    alert("O maior numero eh: " + numero5);
} else if (numero6 > numero5 && numero6 > numero7) {
    alert("O maior numero eh: " + numero6);
} else if (numero7 > numero5 && numero7 > numero6) {
    alert("O maior numero eh: " + numero7);
} else {
    alert("Voce digitou numeros iguais.")
}

// 3. Desconto em compras:
// Se o valor da compra for maior que R$ 100, aplique 10% de desconto.
// Caso contrário, exiba o valor normal.

function calcularDesconto() {

}

// 4. Sistema de login simples:
// O usuário insere um nome de usuário e senha.
// Se usuario == "admin" e senha == "1234", exibir "Login bem-sucedido", caso contrário "Acesso negado".

function sistemaLogin() {

}

// Nível Avançado

// 1. Classificação de triângulos:
// O usuário insere três lados.
// Verifique se forma um triângulo e classifique como equilátero, isósceles ou escaleno.

function classificarTriangulo() {

}

// 2. Conversão de notas para conceitos:
// O usuário insere uma nota (0-100).
// Converta para conceitos: A (90-100), B (80-89), C (70-79), D (60-69), F (<60).

function converterNotaConceito() {

}

// 3. Cálculo de IMC:
// Peça peso e altura.
// Calcule o IMC e classifique como abaixo do peso, normal, sobrepeso ou obesidade.

function calcularIMC() {

}

// 4. Validação de ano bissexto:
// Peça um ano e verifique se é bissexto.
// Um ano é bissexto se for divisível por 4, mas não por 100, exceto se for divisível por 400.

function verificarAnoBissexto() {

}
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
} else if (numero2 == 0) {
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

if (numero4 % 2 == 0) {
    alert("O numero eh par");
} else {
    alert("O numero eh impar.");
}

// Nível Intermediário

// 1. Calculadora simples:
// Peça dois números e uma operação (+, -, *, /).
// Use um if-else para calcular o resultado e exibi-lo. (vou nada)

let operador = String(prompt("Diga qual operacao quer realizar (Insira +, -, * ou /)"));
let valor1 = Number(prompt("Insira o numerador."));
let valor2 = Number(prompt("Insira o denominador."));

switch (operador) {
    case "+":
        alert("O resultado da soma eh:" + (valor1 + valor2));
        break;
    case "-":
        alert("O resultado da subtracao eh:" + (valor1 - valor2));
        break;
    case "*":
        alert("O resultado da multiplicacao eh:" + (valor1 * valor2));
        break;
    case "/":
        alert("O resultado da divisao eh:" + (valor1 / valor2));
        break;
    default: alert("Insira os operadores aritmeticos solicitados");
}

// 2. Maior entre três números:
// O usuário insere três números.
// Use if-else para determinar e exibir o maior.

let numero5 = Number(prompt("Insira um numero."));
let numero6 = Number(prompt("Insira um numero diferente."));
let numero7 = Number(prompt("Insira outro numero diferente."));

if (numero5 > numero6 && numero5 > numero7) {
    alert("O maior numero eh: " + numero5);
} else if (numero6 > numero7) {
    alert("O maior numero eh: " + numero6);
} else {
    alert("O maior numero eh: " + numero7);
}

// 3. Desconto em compras:
// Se o valor da compra for maior que R$ 100, aplique 10% de desconto.
// Caso contrário, exiba o valor normal.

let preco = Number(prompt("Qual foi o valor da compra?"));

if (preco > 100)
    preco -= (preco * 0.1);
alert("O saldo da compra eh: " + preco);

// 4. Sistema de login simples:
// O usuário insere um nome de usuário e senha.
// Se usuario == "admin" e senha == "1234", exibir "Login bem-sucedido", caso contrário "Acesso negado".

let login = String(prompt("Insira o seu nome de usuario."));
let senha = String(prompt("Insira a sua senha."));

if (login == "admin" && senha == "1234") {
    alert("Login bem sucedido!");
} else {
    alert("Usuario ou senha incorretos.");
}

// Nível Avançado

// 1. Classificação de triângulos:
// O usuário insere três lados.
// Verifique se forma um triângulo e classifique como equilátero, isósceles ou escaleno.

let lado1 = Number(Prompt("Insira a medida de um lado do triangulo."));
let lado2 = Number(Prompt("Insira a medida do segundo lado."));
let lado3 = Number(Prompt("Insira a medida do terceiro lado."));

if (lado1 + lado2 >= lado3 || lado2 + lado3 >= lado1 || lado1 + lado3 >= lado2) {
    if (lado1 == lado2 && lado2 == lado3) {
        alert("O triangulo eh equilatero");
    } else if (lado1 == lado2 || lado2 == lado3 || lado1 == lado3) {
        alert("O triangulo eh isosceles");
    } else {
        alert("O triangulo eh escaleno");
    }
} else {
    alert("Um triangulo nao pode ser formado com essas medidas.");
}

// 2. Conversão de notas para conceitos:
// O usuário insere uma nota (0-100).
// Converta para conceitos: A (90-100), B (80-89), C (70-79), D (60-69), F (<60).

let nota1 = Number(prompt("Insira a sua nota (0 a 100)"));
let conceito;

if (nota >= 0 && nota <= 100) {
    if (nota1 >= 90 && nota1 <= 100) {
        conceito = "A";
    } else if (nota1 >= 80 && nota1 <= 89) {
        conceito = "B";
    } else if (nota1 >= 70 && nota1 <= 79) {
        conceito = "C";
    } else if (nota1 >= 60 && nota1 <= 69) {
        conceito = "D";
    } else {
        conceito = "F";
    } alert(`A classificacao da sua nota eh: ${conceito}`)
} else {
    alert("Insira uma nota valida.")
}

// 3. Cálculo de IMC:
// Peça peso e altura.
// Calcule o IMC e classifique como abaixo do peso, normal, sobrepeso ou obesidade.

let peso = parseFloat(prompt("Insira o seu peso."));
let altura = parseFloat(prompt("Insira a sua altura em centimetros."));
let imc = (peso / 100) / (altura * altura);
let imc1;

if (imc < 18.5) {
    imc1 = "abaixo do peso";
} else if (imc >= 18.5 && imc < 25.0) {
    imc1 = "peso normal";
} else if (imc >= 25.0 && imc < 30.0) {
    imc1 = "sobrepeso";
} else if (imc >= 30.0 && imc < 35.0) {
    imc1 = "obesidade grau 1";
} else if (imc >= 35.0 && imc < 40.0) {
    imc1 = "obesidade grau 2";
} else {
    imc1 = "obesidade morbida";
} alert(`Seu imc eh: ${imc}, ${imc1}`);

// 4. Validação de ano bissexto:
// Peça um ano e verifique se é bissexto.
// Um ano é bissexto se for divisível por 4, mas não por 100, exceto se for divisível por 400.

let ano = parent(prompt("Insira um ano para saber se ele eh bissexto."));

if (ano % 4) {
    if (ano % 100 != 0 || ano % 400 == 0) {
        alert("O ano eh bissexto.");
    }
} else {
    alert("O ano nao eh bissexto.");
}
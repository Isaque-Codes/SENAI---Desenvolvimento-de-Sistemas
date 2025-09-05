// TRATAMENTO DE STRINGS, CONSOLE E ALERT

let idade = 26;
let nome = "isaque";
console.log("Ola, meu nome eh " + nome + " e tenho " + idade + " anos.");

let mensagem = `Ola, meu nome eh ${nome}`;
alert(mensagem);
console.log(typeof (mensagem)); // Retorna String
console.log(typeof idade); // Aparentemente algumas funcoes nao requerem escopo para variaveis
let vazio;
console.log(typeof vazio); // Retorna undefined
let nulo = null;
console.log(typeof nulo); // Retorna Object

let golpe = prompt("Digite a senha do seu cartao:")
alert("Sua senha eh: " + golpe)

// ESTRUTURA CONDICIONAL
let temperatura = 20;
if (temperatura > 25) {
    console.log("Esta calor!")
} else {
    console.log("Esta frio!")
}

let nota = parseInt(prompt("Digite a nota:"))
if (nota > 6) {
    console.log("Aprovado(a)!")
} else if (nota >= 5 && nota < 6) {
    console.log("Esta de recuperacao!")
} else {
    console.log("Reprovado(a)!")
}

// IF TERNARIO
let saldo = 90;
let podeComprar = saldo >= 100 ? "Compra aprovada!" : "Saldo insuficiente."

// SWITCH CASE
let diaSemana = 3;
switch (diaSemana) {
    case 1: console.log("Domingo");
    case 2: console.log("Segunda-feira");
    case 3: console.log("Terca-feira");
        break;
    default: console.log("Dia invalido");
        break; // O break eh opcional em JS
}
// var = let
// var = variavel global (undefined, se inicializada antes de ser declarada)
// let = nao ocorre o mesmo citado acima

let valorA = 1;
let valorB = "1";
let resultado = valorA + valorB;
console.log(resultado)
// Ambos retornarao a string 11, caso seja soma, responsavel unica pela concatenacao
let valorC = "1";
let valorD = 1;
let resultado2 = valorC + valorD;
console.log(resultado2);

let variavel = "1";
console.log(variavel == 1); // retorna true
console.log(variavel === 1); // retorna false

console.log(1 + "bigorna"); // retorna 1bigorna. SE a soma for outra operacao, retorna NaN

console.log(NaN == NaN);
console.log(NaN === NaN);
console.log(typeof (NaN)); // WTF

console.log({} + []); // Retorna objeto, tambem na ordem inversa*/
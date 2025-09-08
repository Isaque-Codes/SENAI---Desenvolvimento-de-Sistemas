// Exercícios de Laço de Repetição

// Nível Básico

// 1. Contagem de 1 a 10:
// Use um for para exibir os números de 1 a 10 no console.

let N = 1;
for (i = N; i <= 10; i++) {
    console.log(`Numero: ${N}`);
}


// 2. Tabuada de um número:
// Peça um número ao usuário.
// Exiba a tabuada desse número de 1 a 10 usando um for.

let N2 = parseInt(prompt("Insira um numero para ver sua tabuada."));
for (i = N2; i <= (N * 10); i * N2) {
    console.log(`Numero: ${N2}`);
}

// 3. Soma dos primeiros N números naturais:
// Peça um número N ao usuário.
// Use um while ou for para somar os números de 1 até N.

let N3 = parseInt(prompt("Insira um valor numerico."));
let n3 = 0;
while (n3 <= N3) {
    n3++;
    console.log(`Contagem dos numeros naturais ate o valor: ${n3}`);
}

// Nível Intermediário

// 1. Exibir os números pares de 1 a 50:
// Use um for ou while para exibir apenas os números pares de 1 a 50.

for (i = 2; i <= 50; i += 2) {
    console.log(`Numeros pares de 0 a 50: ${i}`);
}

// 2. Jogo de adivinhação:
// Gere um número aleatório de 1 a 100.
// Peça ao usuário para adivinhar e use um while para continuar até ele acertar.
// Informe se o número inserido é maior ou menor que o correto.

let n4 = Math.floor(Math.random() * 100) + 1;
do {
    let N4 = parseInt(prompt("Adivinhe um numero de 0 a 100."));
    if (N4 >= n4) {
        alert("O numero misterioso eh maior.");
    } else {
        alert("O numero misterioso eh menor.");
    }
} while (N4 != n4)
alert("Parabens! Voce adivinhou o numero.");

// 3. Contagem regressiva:
// Peça um número ao usuário e exiba uma contagem regressiva até 0 usando um while.

let N5 = parseInt(prompt("Insira um numero positivo para contagem regressiva."));
while (N5 >= 0) {
    N5--;
    console.log(`Contagem decrescente: ${N5}`);
}

// Nível Avançado

// 1. Soma dos dígitos de um número:
// Peça ao usuário um número inteiro positivo.
// Use um while para somar seus dígitos.

let numero = (prompt("Insira um numero inteiro positivo qualquer"));
let sucesso = false;
do {

} while (!sucesso)

// 2. Fatorial de um número:
// Peça um número ao usuário.
// Use um for ou while para calcular o fatorial desse número.

let fatorial = parseInt(prompt("Insira um numero para calcular sua fatorial."));
let multiplicacao;
for (i = fatorial; i >= 1; i--) {
    if (i == 1) break;
    multiplicacao = i * (i - 1);
}
alert(`A fatorial de ${fatorial} eh: ${multiplicacao}.`);

// 3. Inverter um número:
// Peça um número ao usuário.
// Use um while para inverter seus dígitos (exemplo: 123 → 321).

function inverterNumero() {

}

// 4. Números perfeitos de 1 a 1000:
// Um número perfeito é aquele cuja soma de seus divisores (excluindo ele mesmo) é igual ao próprio número.
// Exemplo: 6 → 1 + 2 + 3 = 6.
// Use um for aninhado para encontrar e exibir esses números até 1000.

function numerosPerfeitos() {

}
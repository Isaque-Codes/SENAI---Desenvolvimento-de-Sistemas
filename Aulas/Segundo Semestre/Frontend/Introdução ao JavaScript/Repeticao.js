// ------- FOR -------
// Contando de N ate 0
let N = parseInt(prompt("Digite um numero."));

for (let i = N; i >= 0; i--) {
    console.log(i)
}

// ------- WHILE -------
// Executar soma
let soma = 0;
let i = 1;
while (1 <= 10) {
    soma += i;
    console.log(`O resultado atual eh: ${soma}`);
    i++;
}

// ------- DO WHILE -------
let numero = 1;

do {
    console.log(`Numero: ${numero}`);
    numero++;
} while (
    numero <= 20
)

// ------- FOREACH -------
let numeros = [1, 2, 3, 4, 5]
// --- Listando numeros---
numeros.forEach(function (numero) {
    console.log(`Numero: ${numero}`)
})
// Como seria com FOR
for (let i = 0; i < numeros.lenght; i++) {
    console.log(`Numero: {numeros[i]}`)
}

// --- Listando frutas ---
let frutas = ["Maca", "Banana", "uva", "pera"]

frutas.forEach(function (fruta) {
    console.log(fruta)
})
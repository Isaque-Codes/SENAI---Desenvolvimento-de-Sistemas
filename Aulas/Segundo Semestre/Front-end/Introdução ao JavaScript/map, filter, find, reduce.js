// ----- FILTER -----
// O filter serve para arrays

// Filtrar numeros >2
const numeros = [1, 2, 3, 4, 5, 6];
const maioresQueDois = numeros.filter(numero => numero > 2); // => Atua como function
console.log(maioresQueDois);

// Filtrar nomes
let nomes = ["Ana", "Bruno", "Carlos", "Eva", "Fernanda"];
let nomesLongos = nomes.filter(nome => nome.length > 5);
console.log(nomesLongos);

// Filtrar numeros pares
let numeros2 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
let pares = numeros2.filter(numero => numero % 2 === 0);
console.log(pares);

// Filtrar um objeto
let pessoas = [
    { nome: "Afonso", idade: 19 },
    { nome: "Suzana", idade: 22 },
    { nome: "Jurexcrivaldino", idade: 15 },
    { nome: "Xerofoscremildo", idade: 30 }
];

let adultos = pessoas.filter(pessoa => pessoa.idade >= 18);
console.log(adultos);

// ----- FIND -----
// Retorna o primeiro elemento da lista correspondente a condicao (UM FILTER QUE RETORNA O PRIMEIRO)

// Procurar um produto pelo preco
const produtos = [
    { id: 1, nome: "teclado", preco: 800 },
    { id: 2, nome: "mouse", preco: 50 },
    { id: 3, nome: "monitor", preco: 700 }
];

const produtoCaro = produtos.find(produto => produto.preco > 600);
console.log(produtoCaro);

// Encontrar primeiro numero maior que 10
let numeros3 = [5, 8, 12, 20, 33, 3, 15];
let encontrado = numeros3.find(numero => numero > 10);
console.log(encontrado);

// Buscar nome pela primeira letra
let nomes2 = ["Ana", "Bruno", "Carlos,", "Eva", "Catia"];
let nomeEncontrado = nomes2.find(nome => nome.startsWith("C"));
console.log(nomeEncontrado);

// ----- MAP -----
// Manipula arrays

// Multiplicar todos os numeros por 2
const numeros4 = [1, 2, 3, 4, 5];
const numerosDobrados = numeros.map(numero => numero * 2);
console.log(numerosDobrados);

// Criando array a partir de objetos
let pessoas2 = [
    { nome: "Afonso", idade: 19 },
    { nome: "Suzana", idade: 22 },
    { nome: "Jurexcrivaldino", idade: 15 },
    { nome: "Xerofoscremildo", idade: 30 }
];

let nomes3 = pessoas2.map(pessoa => pessoa.nome);
console.log(nomes3);

let mensagem = pessoas2.map(pessoa =>
    `${pessoa.nome} tem ${pessoa.idade} anos.`
)
console.log(mensagem);

// Deixar os nomes em maiusculo e adicionar sufixo
const nomes4 = ["ana", "bruno", "carla"];
const nomesMaiusculo = nomes4.map(nome => "Colaborador:" + nome.toUpperCase())
console.log(nomesMaiusculo);

// ----- REDUCE -----
// Reduz um array a um unico valor

// Somar todos os numeros do array
const numeros5 = [1, 2, 3, 4, 5]
const soma = numeros5.reduce((acumulador, numero) => acumulador + numero, 0);
console.log(soma);

// Verificar o maior numero do array
const numeros6 = [10, 5, 8, 20, 3];
const maiorNumero = numeros.reduce((max, numero) => {

    if (numero > max) {
        return numero;
    } else {
        return max;
    }
}, numeros[0]);
console.log(maiorNumero);
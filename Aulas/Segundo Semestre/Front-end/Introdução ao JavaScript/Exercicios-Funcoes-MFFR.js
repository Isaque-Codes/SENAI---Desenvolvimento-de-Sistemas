// Exercícios Map, Find, Filter e Reduce

// FILTER()

// 1. Dado o array const notas = [4, 7, 9, 3, 10, 5];, filtre apenas as notas maiores ou iguais a 7.

const notas = [4, 7, 9, 3, 10, 5];
const notasMaioresQue7 = notas.filter(notas => notas > 7);
console.log(notasMaioresQue7);

// 2. Dado o array const palavras = ["sol", "mar", "computador", "lua", "código"];, filtre apenas as palavras com mais de 4 letras.

const palavras = ["sol", "mar", "computador", "lua", "código"];
const comMaisDe4Letras = palavras.filter(palavra => palavra.length > 5);
console.log(comMaisDe4Letras);

// 3. Dado o array const animais = ["gato", "cachorro", "peixe", "elefante", "abelha"];, filtre apenas os animais cujo nome começa com a letra "c".

const animais = ["gato", "cachorro", "peixe", "elefante", "abelha"];
const comecaComC = animais.filter(animal => animal.startsWith("c"));
console.log(comecaComC);

// FIND()

// 1. Dado o array const filmes = ["Avatar", "Batman", "Vingadores", "Matrix", "Barbie"];, encontre o primeiro filme que começa com a letra "B".

const filmes = ["Avatar", "Batman", "Vingadores", "Matrix", "Barbie"];
const primeiroComB = filmes.find(filme => filme.startsWith("B"));
console.log(primeiroComB);

// 2. Dado o array const numeros = [2, 4, 6, 9, 12, 15];, encontre o primeiro número ímpar.

const numeros = [2, 4, 6, 9, 12, 15];
const primeiroImpar = numeros.find(numero => numero % 2 != 0);
console.log(primeiroImpar);

// 3. Dado o array const alunos = [{nome: "Ana", nota: 8}, {nome: "Carlos", nota: 5}, {nome: "Beatriz", nota: 9}];, encontre o primeiro aluno com nota maior ou igual a 7.

const alunos = [{ nome: "Ana", nota: 8 }, { nome: "Carlos", nota: 5 }, { nome: "Beatriz", nota: 9 }];
const maiorQue7 = alunos.find(nota => nota.nota >= 7);
console.log(maiorQue7);

// MAP()

// 1. Dado o array const temperaturas = [20, 25, 30, 15];, crie um novo array convertendo para Fahrenheit (C * 1.8 + 32).

const temperaturas = [20, 25, 30, 15];
const emFahrenheit = temperaturas.map(temp => (temp * 1.8) + 32);
console.log(emFahrenheit);

// 2. Dado o array const produtos = ["camisa", "calça", "sapato"];, crie um novo array com os nomes em maiúsculo e prefixo "Produto: ".

const produtos = ["camisa", "calça", "sapato"];
const alterados = produtos.map(produto => "Produto: " + produto.toUpperCase);
console.log(alterados);

// 3. Dado o array const numeros = [1, 2, 3, 4];, crie um novo array com cada número elevado ao quadrado (x ** 2).

const numeros2 = [1, 2, 3, 4];
const numeros2AoQuadrado = numeros2.map(numero => numero * numero);
console.log(numeros2AoQuadrado);

// REDUCE()

// 1. Dado o array const valores = [100, 200, 50, 150];, calcule o total (como se fosse uma soma de compras).

const valores = [100, 200, 50, 150];
const soma = valores.reduce((acumulador, soma) => acumulador + soma, 0);
console.log(soma);

// 2. Dado o array const palavras = ["JS", "é", "muito", "legal"];, use reduce para juntar tudo em uma única frase.

const palavras2 = ["JS", "é", "muito", "legal"];
const palavrasUnidas = palavras2.reduce((acumulador, palavra) => acumulador + " " + palavra);
console.log(palavrasUnidas);

// 3. Dado o array const numeros = [1, 2, 3, 4, 5];, use reduce para calcular a média.

const numeros3 = [1, 2, 3, 4, 5];
const media = numeros3.reduce((acumulador, media) => acumulador + media) / numeros3.length;
console.log(media);

// DESAFIOS (misturando funções)

// 1. Dado o array const livros = [{ titulo: "Dom Casmurro", paginas: 300 }, { titulo: "O Hobbit", paginas: 295 }, { titulo: "A Revolução dos Bichos", paginas: 112 }];
// - Filtre apenas os livros com mais de 200 páginas.
// - Crie um array apenas com os títulos.
// - Calcule o total de páginas de todos os livros.

const livros = [
    { titulo: "Dom Casmurro", paginas: 300 },
    { titulo: "O Hobbit", paginas: 295 },
    { titulo: "A Revolução dos Bichos", paginas: 112 }
];

const maisDe200Paginas = livros.filter(paginas => paginas.paginas > 200);
const apenasTitulos = livros.map(titulos => titulos.titulo);
const totalDePaginas = livros.reduce((acumulador, paginas) => acumulador + paginas.paginas, 0);

console.log(maisDe200Paginas);
console.log(apenasTitulos);
console.log(totalDePaginas);

// 2. Dado o array const carrinho = [{ produto: "Notebook", preco: 2500 }, { produto: "Mouse", preco: 100 }, { produto: "Teclado", preco: 200 }];
// - Use map para criar uma lista de strings no formato "Produto: X - R$ Y".
// - Use reduce para calcular o valor total da compra.
// - Use find para encontrar o produto chamado "Mouse".

const carrinho = [
    { produto: "Notebook", preco: 2500 },
    { produto: "Mouse", preco: 100 },
    { produto: "Teclado", preco: 200 }
];

const formatacao = carrinho.map(carrinho => "Prduto: " + carrinho.produto + ", RS$: " + carrinho.preco);
const valorTotal = carrinho.reduce((acumulador, valor) => acumulador + valor.preco, 0);
const mouse = carrinho.find(mouse => mouse.produto == "Mouse");

console.log(formatacao);
console.log(valorTotal);
console.log(mouse);
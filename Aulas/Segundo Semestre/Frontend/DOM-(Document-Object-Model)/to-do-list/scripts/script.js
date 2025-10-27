// Variavel para armazenar o form
const elForm = document.getElementById('form-tarefa');
console.log(elForm);

// Variavel para armazenar o titulo
const elTitulo = document.querySelector('#titulo');
console.log(elTitulo);

// Variavel pra armazenar o filtro de status
const elFiltroStatus = document.querySelector('#filtro-status');
console.log(elFiltroStatus);

// Variavel para armazenar o filtro de busca
const elFiltroBusca = document.querySelector('#filtro-busca');
console.log(elFiltroBusca);

// Variavel para armazenar a lista
const elLista = document.querySelector('#lista-tarefas');

// Variavel para armazenar o texto que aparece quando a lista esta vazia
const elVazio = document.querySelector('#vazio');

let tarefas = [
    { id: 1, titulo: "Estudar DOM", status: "pendente" },
    { id: 2, titulo: "Criar To-Do-List", status: "andamento" },
    { id: 3, titulo: "Praticar JavaScript", status: "concluida" }
]

// Adiciona um "ouvinte" para o evento de submit do formulario
elForm.addEventListener('submit', function (e) {
    // O "(e)" eh uma referencia de objeto de evento
    // Que o navegador cria sempre que algo aparece

    // Impede o comportamento padrao do formulario (recarregar a pagina)
    e.preventDefault();

    // Pega o value digitado no input e remove os espacos
    const titulo = elTitulo.value.trim();
    console.log("tag input: ", elTitulo);

    // Se o titulo estiver vazio, encerra a funcao aqui
    if (!titulo) return;
    console.log("Titulo: ", titulo);

    // Cria um objeto representando a nova tarefa
    // -id: recebe o numero do timestamp atual
    // -titulo: recebe o texto digitado pelo usuario
    // -status: comeca sempre como "pendente"

    const nova = { id: Date.now(), titulo: titulo, status: "pendente" };

    // Adiciona a nova tarefa dentro do array de tarefas
    tarefas.push(nova);
    console.log(tarefas);

    // Limpa o campo de texto do input
    elTitulo.value = "";

    // Chama a funcao render() para atualizar a lista de tarefas exibida na tela
    render();
})

// Renderizar a lista
function render() {
    // Termo digitado na busca - deixar em minusculo
    const termo = elFiltroBusca.value.toLowerCase();
    console.log("Termo digitado em minusculo: ", termo);

    // Valor selecionado no filtro de status
    const filtro = elFiltroStatus.value;
    console.log("Filtro de status: ", filtro);

    // Aplica filtro de status e busca
    const filtradas = tarefas.filter(function (t) {
        // Se o filtro for "todas", aceita qualquer status
        // Se nao, compara com t.status
        const okStatus = filtro === "todas" ? true : t.status === filtro;

        // Se houver um termo, verifica se o titulo o contem
        // Se o usuario digitar algo, so aceita a tarefa se for igual ao que o usuario digitou
        const okBusca = termo ? t.titulo.toLocaleLowerCase().includes(termo) : true;

        return okStatus && okBusca;
    })

    console.log(filtradas);

    // Limpar a lista antes de redesenhar
    elLista.innerHTML = "";

    // Cria os elementos da lista para cada tarefa filtrada
    filtradas.forEach(function (t) {
        // <li class"tarefa {status}" data-id={id}></li>
        const li = document.createElement('li');
        // class="tarefa concluida"
        li.className = "tarefa " + t.status;
        li.dataset.id = t.id;

        // Titulo da tarefa
        const h3 = document.createElement('h3');
        // <h3>Aula JavaScript</h3>
        h3.textContent = t.titulo;

        // Caixa de acoes (checkbox, select, botao remover)
        const acoes = document.createElement('div');
        acoes.className = "acao";

        // checkbox: marcar concluida/pendente
        const check = document.createElement('input');
        check.type = "checkbox";
        check.checked = t.status === "concluida";

        // Ao mudar o check, redesenha na tela
        check.addEventListener('change', function () {
            t.status = check.checked ? "concluida" : "pendente";
            render();
        })

        // Select de status: pendente / concluida / andamento
        const select = document.createElement('select');
        const listaSelect = ["pendente", "andamento", "concluida"];

        listaSelect.forEach(function (status) {
            const option = document.createElement('option');
            option.value = status;
            option.textContent = status.charAt(0).toUpperCase() + status.slice(1);

            if (t.status === status) option.selected = true;
            select.appendChild(option);
        })

        // Ao mudar o select, atualiza e redesenha na tela
        select.addEventListener('change', function () {
            t.status = select.value;
            render();
        })

        // Botao remover
        const botao = document.createElement('button');
        botao.textContent = "X";
        botao.className = "remover";

        botao.addEventListener('click', function () {
            tarefas = tarefas.filter(apagar => apagar.id !== t.id)
            render();
        })

        // Adicionando os filhos da div acoes
        acoes.appendChild(check);
        acoes.appendChild(select);
        acoes.appendChild(botao);

        // Adicionando os filhos do 'li'
        li.appendChild(h3);
        li.appendChild(acoes);

        // Adicionando os filhos do 'ul'
        elLista.appendChild(li);
    })

    // Texto aparece se o array de filtradas conter algo
    // Caso vazio, recebe display: none
    elVazio.style.display = filtradas.length ? "none" : "block";
}

// Filtrar
// Quando o usuario mudar a opcao de filtro por status
elFiltroStatus.addEventListener('change', render);

// Quando o usuario digitar algo no campo de busca
elFiltroBusca.addEventListener('input', render);

// Primeira renderizacao / atualizacao de informacoes
render();
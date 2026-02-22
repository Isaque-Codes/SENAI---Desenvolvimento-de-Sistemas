# 💾 Banco de Dados

O objetivo é construir uma base sólida em modelagem relacional, definição e manipulação de estruturas de dados, consultas avançadas e gerenciamento de integridade em bancos de dados relacionais (SQL Server).

> **Nota:** Os projetos aqui presentes foram desenvolvidos e executados no SQL Server (Management Studio). O foco deste material é a memorização do autor.

## Comandos: DDL, DQL E DML

### DDL – Linguagem de Definição de Dados

- `CREATE DATABASE Nome;`  
  Cria um novo banco de dados.

- `USE Nome;`  
  Seleciona o banco de dados ativo.

- `CREATE TABLE NomeTabela (Id INT PRIMARY KEY, ...);`  
  Cria tabela com chave primária simples.

- `CREATE TABLE NomeTabela (Id INT PRIMARY KEY, ..., CONSTRAINT NomeFk FOREIGN KEY (Coluna) REFERENCES TabelaPai(ColunaPai) ON DELETE CASCADE);`  
  Cria tabela com chave estrangeira em cascata.

- `CREATE TABLE NomeTabela (Id INT PRIMARY KEY IDENTITY(100,1), ...);`  
  Cria tabela com chave primária auto-incremento (IDENTITY).

- `ALTER TABLE NomeTabela ALTER COLUMN Coluna Tipo NOT NULL;`  
  Altera o tipo ou restrição de uma coluna existente.

- `ALTER TABLE NomeTabela DROP CONSTRAINT NomeConstraint;`  
  Remove uma constraint (PK, FK, etc.).

- `ALTER TABLE NomeTabela ADD CONSTRAINT NomeConstraint PRIMARY KEY (Coluna);`  
  Adiciona chave primária em tabela existente.

- `ALTER TABLE NomeTabela ADD CONSTRAINT NomeConstraint FOREIGN KEY (Coluna) REFERENCES TabelaPai(ColunaPai) ON DELETE CASCADE;`  
  Adiciona chave estrangeira com cascata em tabela existente.

- `EXEC sp_rename 'NomeAntigo', 'NomeNovo';`  
  Renomeia uma tabela.

- `EXEC sp_rename 'Tabela.ColunaAntiga', 'ColunaNova', 'COLUMN';`  
  Renomeia uma coluna.

- `EXEC sp_help 'NomeTabela';`  
  Mostra estrutura detalhada da tabela (campos, tipos, constraints).

### DQL – Linguagem de Consulta de Dados

- `SELECT * FROM NomeTabela;`  
  Retorna todos os registros e colunas.

- `SELECT Coluna1, Coluna2 FROM NomeTabela;`  
  Retorna apenas colunas específicas.

- `SELECT * FROM NomeTabela WHERE CondicaoNumerica > valor;`  
  Filtra por valor numérico maior.

- `SELECT * FROM NomeTabela WHERE CondicaoTexto = 'valor';`  
  Filtra por igualdade em texto.

- `SELECT COUNT(*) AS NomeAlias FROM NomeTabela;`  
  Conta o total de registros.

- `SELECT Campo, COUNT(*) AS Total FROM Tabela JOIN OutraTabela ON ... GROUP BY Campo;`  
  Conta ocorrências agrupadas com JOIN.

- `SELECT MIN(Campo), MAX(Campo) FROM NomeTabela;`  
  Retorna valor mínimo e máximo de um campo.

- `SELECT UPPER(Campo), LOWER(Campo) FROM NomeTabela;`  
  Converte texto para maiúsculo ou minúsculo.

- `SELECT LEN(Campo) FROM NomeTabela;`  
  Retorna o comprimento de uma string.

- `SELECT LEFT(Campo, n), RIGHT(Campo, n) FROM NomeTabela;`  
  Extrai caracteres do início ou fim da string.

- `SELECT REPLACE(Campo, 'Antigo', 'Novo') FROM NomeTabela;`  
  Substitui parte do texto.

- `SELECT CHARINDEX('texto', Campo) FROM NomeTabela;`  
  Retorna posição de uma substring.

- `SELECT CONCAT('Texto', Campo, ' mais texto') FROM NomeTabela;`  
  Concatena strings.

- `SELECT SUBSTRING(Campo, inicio, comprimento) FROM NomeTabela;`  
  Extrai substring a partir de posição.

- `SELECT RTRIM(Campo), LTRIM(Campo), TRIM(Campo) FROM NomeTabela;`  
  Remove espaços em branco das extremidades.

- `SELECT GETDATE();`  
  Retorna data e hora atuais do servidor.

- `SELECT DATEADD(unidade, quantidade, data) FROM NomeTabela;`  
  Adiciona ou subtrai intervalo de tempo a uma data.

- `SELECT DATEDIFF(unidade, data_inicio, data_fim) FROM NomeTabela;`  
  Calcula diferença entre duas datas.

- `SELECT FORMAT(data, 'dd/MM/yyyy') FROM NomeTabela;`  
  Formata data em padrão específico.

- `SELECT YEAR(data), MONTH(data), DAY(data) FROM NomeTabela;`  
  Extrai ano, mês e dia de uma data.

- `SELECT DATEPART(parte, data), DATENAME(parte, data) FROM NomeTabela;`  
  Extrai parte numérica ou nome de data (ano, mês, dia da semana).

- `SELECT * FROM Tabela1 INNER JOIN Tabela2 ON Tabela1.Chave = Tabela2.Chave;`  
  Retorna registros com correspondência em ambas tabelas.

- `SELECT * FROM Tabela1 LEFT JOIN Tabela2 ON Tabela1.Chave = Tabela2.Chave;`  
  Retorna todos da tabela esquerda + correspondências da direita.

- `SELECT * FROM Tabela1 RIGHT JOIN Tabela2 ON Tabela1.Chave = Tabela2.Chave;`  
  Retorna todos da tabela direita + correspondências da esquerda.

- `SELECT * FROM NomeTabela WHERE Campo BETWEEN valor1 AND valor2;`  
  Filtra faixa de valores.

- `SELECT * FROM NomeTabela WHERE Campo IN ('valor1', 'valor2');`  
  Filtra por lista de valores.

- `SELECT * FROM NomeTabela WHERE Campo LIKE '%padrao%';`  
  Filtra por padrão de texto (começa, termina ou contém).

- `SELECT * FROM NomeTabela WHERE Campo IS NOT NULL;`  
  Filtra registros que possuem valor (não nulo).

### DML – Linguagem de Manipulação de Dados

- `INSERT INTO NomeTabela VALUES (...), (...);`  
  Insere múltiplos registros.

- `UPDATE NomeTabela SET Coluna = novo_valor WHERE Condicao;`  
  Atualiza registros que atendem à condição.

- `DELETE FROM NomeTabela WHERE Condicao;`  
  Exclui registros que atendem à condição.
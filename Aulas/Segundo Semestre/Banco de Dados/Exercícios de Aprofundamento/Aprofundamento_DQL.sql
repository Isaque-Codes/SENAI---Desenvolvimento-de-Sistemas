CREATE DATABASE BIBLIOTECA2;
GO

USE BIBLIOTECA2;
GO

CREATE TABLE Autor (
	id_Autor INT PRIMARY KEY,
	nome VARCHAR(100) NOT NULL
	);
GO

CREATE TABLE Livro (
	id_Livro INT PRIMARY KEY,
	titulo VARCHAR(150) NOT NULL,
	ano INT,
	id_Autor INT NOT NULL,
	CONSTRAINT fk_livro_autor FOREIGN KEY (id_Autor) REFERENCES Autor(id_Autor) ON DELETE CASCADE
	);
GO

CREATE TABLE Leitor (
	id_Leitor INT PRIMARY KEY,
	nome VARCHAR(100) NOT NULL,
	email VARCHAR (120) UNIQUE
	);
GO

CREATE TABLE Emprestimo (
	id_Emprestimo INT PRIMARY KEY,
	id_Livro INT NOT NULL,
	id_Leitor INT NOT NULL,
	data_emprestimo DATE NOT NULL, 
	data_devolucao DATE,
	CONSTRAINT fk_empr_livro FOREIGN KEY (id_Livro) REFERENCES Livro(id_Livro) ON DELETE CASCADE,
	CONSTRAINT fk_empr_leitor FOREIGN KEY (id_Leitor) REFERENCES Leitor(id_Leitor) ON DELETE CASCADE
	);
GO

INSERT INTO Autor VALUES 
  (1,'Machado de Assis'),
  (2,'Clarice Lispector'),
  (3,'J. K. Rowling'),
  (4,'Shakespeare');
GO

INSERT INTO Livro VALUES 
	(1, 'Dom Casmurro', 1899, 1),
	(2, 'Memórias Póstumas de Brás Cubas', 1881, 1),
	(3, 'A hora da estrela', 1977, 2),
	(4, 'O sonho de uma noite de verão', 1600, 4),		
	(5, 'Harry Potter e o calice de fogo', 2000, 3);
GO

INSERT INTO Leitor VALUES
	(1, 'Thiago Oliveira' , 'thiago@gmail.com'),
	(2, 'Caique' , 'caique@gmail.com'),
	(3, 'Odirlei' , 'odi@gmail.com' ),
	(4, 'Kessia', 'kessia@gmail.com');
GO

INSERT INTO Emprestimo VALUES --id_emprestimo, id_livro, id_leitor, data_empr, data_dev
	(1, 5, 1, '2025-09-02', '2025-09-09'), -- Thiago pegou harry potter
	(2, 4, 4, '2025-08-27', '2025-09-05'), -- kessia pegou o sonho de uma noite
	(3, 1, 2, '2025-05-01', '2025-06-10'); --caique pegou Dom casmurro
GO

-- COUNT: Contar Total de Registros
SELECT * FROM Leitor;
SELECT COUNT(*) AS QtdLeitores FROM Leitor;

-- COUNT + GROUP BY (Para quando existem multiplos atributos)
SELECT * FROM Emprestimo;
SELECT l.nome, COUNT(e.id_emprestimo) AS QtdEmprestimo
FROM Emprestimo e
JOIN Leitor l ON l.id_leitor = e.id_leitor
GROUP BY l.nome;

-- MIN / MAX
SELECT Ano From Livro;

SELECT MIN(Ano) AS MenorAno FROM Livro;
SELECT MAX(Ano) AS MaiorAno FROM Livro;

-------------------------------------------------------------------
--             FUNCOES DE TEXTO
-------------------------------------------------------------------

-- LEN (Retorna quantidade de caracteres do atributo (INCLUI ESPACOS))
SELECT LEN('Kessia') AS TamanhoString;
SELECT nome, LEN(nome) FROM Autor;

-- UPPER (Maiusculo) / LOWER (Minusculo)
SELECT UPPER(nome) FROM Leitor;
SELECT LOWER(email) FROM Leitor;

-- LEFT / RIGHT (Le atributo a partir de)
SELECT LEFT(titulo, 5) AS Primeiros5 FROM Livro;
SELECT RIGHT(titulo, 5) AS Ultimos5 FROM Livro;

-- REPLACE (Trocar Caracteres) (Atributo, Valor Inicial, Valor Final)
SELECT REPLACE(titulo, 'Harry', 'Hermione')
FROM Livro;

-- CHARINDEX (Localizar a posicao de alguma palavra)
SELECT Titulo, CHARINDEX('de', titulo) AS PosicaoTexto
FROM Livro;

-- CONCAT (Concatenar textos)
SELECT CONCAT('Emprestimo ', e.id_Emprestimo, ' - Leitor: ', le.nome, ' - Livro: ', li.titulo)
FROM Emprestimo e
JOIN Leitor le ON le.id_Leitor = e.id_Leitor
JOIN Livro li ON li.id_Livro = e.id_Livro;

-- SUBSTRING (A PARTIR DO CARACTERE, ATE O CARACTERE)
SELECT SUBSTRING(titulo, 1, 10)
FROM Livro;

-- RTRIM (REMOVE ESPACO DAS EXTREMIDADES) (Direita) / LTRIN (Esquerda) / TRIM (Os 2 lados)
SELECT Nome, RTRIM(nome), LTRIM(nome), TRIM(nome)
FROM Leitor;

---------------------------------------------
--         FUNCOES DE DATA E HORA
---------------------------------------------

-- GETDATE (Dia e Horario Local (COM BASE NO IP DO SERVIDOR))
SELECT GETDATE();

-- SYSDATETIMEOFFSET
SELECT SYSDATETIMEOFFSET()
AT TIME ZONE 'E. South America Standard Time';

-- DATEADD (ADICIONA/SUBTRAI tempo extra dentro de data)
-- YEAR, MONTH, DAY, WEEK
SELECT id_Emprestimo, data_emprestimo,
DATEADD(YEAR, -7, data_emprestimo) AS PrevisaoDevolucao
FROM Emprestimo;

-- DATEDIFF (Diferenca Entre Datas)
SELECT id_emprestimo, data_emprestimo, data_devolucao,
DATEDIFF(DAY, data_emprestimo, ISNULL(data_devolucao, GETDATE()))
FROM Emprestimo;
-- (if data_devolucao == empty) {data_devolucao = GETDATE(dataAtual); data_devolucao = comparacao.data_emprestimo}

-- FORMAT (Formatar Datas)
SELECT * FROM Emprestimo;

SELECT
FORMAT (data_emprestimo, 'dd/MM/yyyy') AS Emprestimo,
FORMAT (data_devolucao, 'dd-MM-yy') AS Devolucao
FROM Emprestimo;

-- EXTRAIR ANO, MES E DIA DE DATA
SELECT YEAR(data_emprestimo) AS Ano,
MONTH(data_emprestimo) AS Mes,
DAY(data_emprestimo) AS Dia
FROM Emprestimo;

SET LANGUAGE Portuguese;
-- DATEPART / DATENAME (Resultado em NUMERO / NOME)
SELECT DATEPART(YEAR, data_emprestimo),
	   DATEPART(WEEKDAY, data_emprestimo) AS DiaSemana,
	   DATENAME(WEEKDAY, data_emprestimo) AS NomeDiaSemana,
	   DATENAME(MONTH, data_emprestimo) AS NomeMes
FROM Emprestimo;

--------------------------------------------------
--          OPERADORES DE COMPARACAO
--------------------------------------------------

-- IGUALDADE (=)
-- DIFERENCA (NOT LIKE)
-- MAIOR / MENOR QUE (> / <)
-- MAIOR / MENOR OU IGUAL (>= / <=)

SELECT id_emprestimo, data_emprestimo FROM Emprestimo
WHERE data_emprestimo <= '2925-09-01';

----------------------------------------------------
--           OPERADORES LOGICOS
----------------------------------------------------

-- E (AND)
SELECT emprestimo.id_Emprestimo, leitor.nome,
emprestimo.data_emprestimo, emprestimo.data_devolucao
FROM Emprestimo
JOIN Leitor ON Leitor.id_Leitor = Emprestimo.id_Leitor
WHERE MONTH(emprestimo.data_emprestimo) = 9
AND YEAR(emprestimo.data_emprestimo) = 2025;

-- OU (OR)
SELECT l.titulo, l.ano, a.nome
FROM Livro l
JOIN Autor a ON a.id_Autor = l.id_Autor
WHERE a.nome = 'Machado de Assis'
OR a.nome = 'Clarice Lispector';

-- NAO (NOT)
SELECT l.titulo, l.ano, a.nome
FROM Livro l
JOIN Autor a ON a.id_Autor = l.id_Autor
WHERE NOT a.nome = 'Machado de Assis'

---------------------------------------------
--           OPERADORES ESPECIAIS
---------------------------------------------

-- ENTRE (BETWEEN)
SELECT titulo, ano
FROM Livro
WHERE ano BETWEEN 1900 AND 2000;

-- IN (Verifica uma lista de valores)
SELECT * FROM Autor
WHERE nome IN ('Machado de Assis', 'Shakespeare');

-- LIKE
SELECT titulo
FROM Livro
WHERE titulo LIKE '%O%';
-- Se existe texto ANTES, DEPOIS OU AMBOS (%O, O% OU %O%)

-- IS [NOT] NULL
SELECT id_Emprestimo, id_livro, data_emprestimo
FROM Emprestimo
WHERE data_devolucao IS NOT NULL;
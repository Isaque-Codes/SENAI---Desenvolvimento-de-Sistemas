-- DDL - LINGUAGEM DE DEFINICAO DE DADOS

-- DROP DATABASE Clinica_Medica;

CREATE DATABASE Clinica_Medica;
GO -- EXECUTA COMANDOS UM POR UM

USE Clinica_Medica;
GO

-- TABELA PACIENTE
CREATE TABLE Paciente(
	CPF VARCHAR(14) PRIMARY KEY,
	Nome VARCHAR(40),
	Telefone VARCHAR(30),
	NumeroPlano INT,
	NomePlano VARCHAR(20),
	TipoPlano VARCHAR(10)
);
GO

-- INSERCAO PACIENTES
INSERT INTO Paciente VALUES
('111.111.111-11', 'irineu', '4002-8922', 1, 'a', '1a'),
('222.222.222-22', 'jurandir', '4003-8933', 2, 'b', '2b'),
('333.333.333-33', 'janjolao', '4004-8944', 3, 'c', '3c'),
('444.444.444-44', 'jaransca', '4005-8955', 4, 'd', '4d'),
('555.555.555-55', 'jurelma', '4006-8966', 5, 'e', '5e'),
('666.666.666-66', 'jureumar', '4007-8977', 6, 'f', '6f');
GO

-- TABELA MEDICO
CREATE TABLE Medico(
CRM INT PRIMARY KEY,
NomeMedico VARCHAR(30),
Especialidade VARCHAR(20)
);
GO

-- INSERCAO MEDICOS
INSERT INTO Medico VALUES
(111111, 'valdemiro', 'transplante'),
(222222, 'marcelo', 'exame'),
(333333, 'julia', 'cirurgia'),
(444444, 'arnaldo', 'medicacao'),
(555555, 'juremildo', 'coracao');
GO

-- TABELA CONSULTA
CREATE TABLE Consulta(
NumeroConsulta INT PRIMARY KEY IDENTITY(100, 1), -- AUTO-INCREMENTO. COMECA EM 100 E ACRESCENTARIA DE 1 EM 1
DataConsulta DATE,
HorarioConsulta TIME,
CRM_Medico INT FOREIGN KEY REFERENCES Medico(CRM),
CPF_Paciente VARCHAR(14) FOREIGN KEY REFERENCES Paciente(CPF) -- MESMO TIPO DE DADO DA CHAVE PRIMARIA CORRESPONDENTE
);
GO

-- INSERCAO CONSULTAS
INSERT INTO Consulta VALUES
('2025-01-01', '10:00:00', 111111, '111.111.111-11'),
('2025-02-02', '11:00:00', 222222, '222.222.222-22'),
('2025-03-03', '12:00:00', 333333, '333.333.333-33'),
('2025-04-04', '13:00:00', 444444, '444.444.444-44');
GO

-- BUSCA DE DADOS
SELECT * FROM Paciente;

SELECT NomeMedico, Especialidade FROM Medico;

-- DICIONARIO DE DADOS
SELECT * FROM sys.tables;

SELECT name, create_date, modify_date
FROM sys.tables;

-- VISUALIZAR INFORMACOES DAS COLUNAS DA TABELA
SELECT * FROM sys.columns
WHERE object_id = OBJECT_ID('Paciente');

SELECT * FROM sys.types;

-- INNER JOIN / JOIN (AMBOS SAO O MESMO)
SELECT C.NumeroConsulta, P.Nome, M.NomeMedico, C.DataConsulta, C.HorarioConsulta
FROM Consulta C -- USO DO INNER JOIN PARA BUSCAR ATRIBUTOS EM COMUM ENTRE TABELAS
INNER JOIN Paciente P ON C.CPF_Paciente = P.CPF
INNER JOIN Medico M ON C.CRM_Medico = M.CRM

-- LEFT JOIN
SELECT C.DataConsulta, M.NomeMedico, P.Nome AS 'NomePaciente' -- OU AS NomePaciente
FROM Paciente P
LEFT JOIN Consulta C ON P.CPF = C.CPF_Paciente
LEFT JOIN Medico M ON C.CRM_Medico = M.CRM

--RIGHT JOIN
SELECT M.NomeMedico, M.Especialidade, C.DataConsulta, P.Nome
FROM Consulta C
RIGHT JOIN Medico M ON C.CRM_Medico = M.CRM
RIGHT JOIN Paciente P ON C.CPF_Paciente = P.CPF

SELECT NumeroConsulta FROM Consulta WHERE CPF_Paciente = '111.111.111-11';

SELECT NumeroConsulta FROM Consulta WHERE CRM_Medico = 111111;

-- CONSULTA DE TODOS JUNTOS COM JOIN
SELECT tabelas.name AS Tabela, colunas.name AS Colunas,
tipo.name AS Tipo, colunas.max_length AS Tamanho,
colunas.is_nullable AS PermiteNulo
FROM sys.tables tabelas
JOIN sys.columns colunas ON tabelas.object_id = colunas.object_id
JOIN sys.types tipo ON colunas.user_type_id = tipo.user_type_id
ORDER BY tabelas.name, colunas.column_id

-- ATUALIZACAO DE DADOS
UPDATE Paciente SET NumeroPlano = 7
WHERE NumeroPlano = 1 OR NumeroPlano = 2 OR NumeroPlano = 3;

-- EXCLUSAO DE DADOS
DELETE FROM Paciente
WHERE CPF = '111.111.111-11' OR CPF = '222.222.222-22';
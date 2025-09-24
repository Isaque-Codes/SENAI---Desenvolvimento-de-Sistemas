CREATE DATABASE Secretaria;

USE Secretaria;

-- EU ESQUECI QUE ENTIDADES DEVEM TER NOMES NO SINGULAR
CREATE TABLE Alunos(
Id_Aluno INT PRIMARY KEY,
Nome NVARCHAR(100),
Idade INT,
Cidade NVARCHAR(100)
)

INSERT INTO Alunos VALUES
(1, 'Isaque', 25, 'São Paulo'),
(2, 'Janjolão', 44, 'Xique-Xique'),
(3, 'Ana', 18, 'São Caetano'),
(4, 'Joao', 14, 'Diadema'),
(5, 'Suzana', 29, 'São Paulo')

SELECT * FROM Alunos;

SELECT * FROM Alunos WHERE Idade > 20;

SELECT * FROM Alunos WHERE Cidade = 'São Paulo';
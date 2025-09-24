CREATE DATABASE BIBLIOTECA;

USE BIBLIOTECA;

CREATE TABLE Livros(
IdLivro INT PRIMARY KEY,
Titulo NVARCHAR(100),
Autor NVARCHAR(100),
AnoPublicacao INT
);

INSERT INTO Livros VALUES
(1, 'Receitas Incriveis', 'Ana Maria Braga', 2000),
(2, 'As cronicas lendarias', 'Petrovsky Sturley', 1964),
(3, 'Um cara criativo', 'Don Ramon', 1988),
(4, 'Diario', 'Hugo Chaves', 1994),
(5, 'Chapolin', 'Chaves', 1976);

SELECT * FROM Livros WHERE AnoPublicacao > 1980;

SELECT Titulo FROM Livros WHERE Autor = 'Petrovsky Sturley';

SELECT Titulo FROM Livros;
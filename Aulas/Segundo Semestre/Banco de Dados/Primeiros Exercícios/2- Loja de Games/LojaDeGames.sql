CREATE DATABASE GameStore;

USE GameStore;

CREATE TABLE Jogos(
IdJogo INT PRIMARY KEY,
Titulo NVARCHAR(100),
Genero NVARCHAR(100),
Preco DECIMAL(4,2)
);

INSERT INTO Jogos Values
(1, 'Bazuca War''s', 'Tiro', 99.99),
(2, 'Titans', 'RPG', 79.99),
(3, 'Leviatan', 'RPG', 69.99),
(4, 'Hell''s Gate', 'Guerra', 88.88),
(5, 'Colheita Infeliz', 'Puzzle', 44.49),
(6, 'Janjolão Adventures', 'Ação', 49.99);

SELECT * FROM Jogos WHERE Genero = 'RPG';

SELECT * FROM Jogos WHERE Preco > 50.00;

SELECT Titulo, Preco FROM Jogos;
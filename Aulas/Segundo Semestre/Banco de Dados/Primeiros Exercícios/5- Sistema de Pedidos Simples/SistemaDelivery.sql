CREATE DATABASE Restaurante;

USE Restaurante;

CREATE TABLE Pedidos(
IdPedido INT PRIMARY KEY,
Cliente NVARCHAR (100),
Produto NVARCHAR (100),
Quantidade INT
);

INSERT INTO Pedidos VALUES
(1, 'Juremildo', 'Churrasco de rato', 2),
(2, 'Jureqs', 'Uva passa', 20),
(3, 'Ana', 'Rocambole', 3),
(4, 'Joao', 'Peito de porco', 1),
(5, 'Mateus', 'Bisteca de bufalo', 1),
(6, 'Tiago', 'Figado de galinha', 2);

SELECT * FROM Pedidos WHERE Cliente = 'Mateus';

SELECT * FROM Pedidos WHERE Produto = 'Churrasco de rato';

SELECT Cliente, Quantidade, Produto FROM Pedidos;
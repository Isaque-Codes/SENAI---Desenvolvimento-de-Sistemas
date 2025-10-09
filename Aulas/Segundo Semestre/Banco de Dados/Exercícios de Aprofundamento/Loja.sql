CREATE DATABASE Loja
GO

USE Loja
GO

CREATE TABLE Cliente(
	ClienteId INT IDENTITY(100, 1),
	Nome      VARCHAR(100) NOT NULL,
	Email     VARCHAR (100) UNIQUE,
	CONSTRAINT Pk_Cliente PRIMARY KEY (ClienteId)
);
GO

CREATE TABLE Pedido(
	PedidoId	INT IDENTITY(100, 1),
	DataPedido  DATE NOT NULL,
	Valor		DECIMAL(10, 2),
	ClienteId INT,
	CONSTRAINT Pk_Pedido PRIMARY KEY (PedidoId),
	CONSTRAINT Fk_Pedido FOREIGN KEY (ClienteId)
	REFERENCES Cliente(ClienteId) -- ON DELETE CASCADE
);
GO

INSERT INTO Cliente VALUES -- (Nome, Email)
('Isaque Silva', 'isaque@senai.com'),
('Maria Silva', NULL),
('Victoria Sousa', 'email@email.com');
GO

INSERT INTO Pedido VALUES -- (DataPedido, Valor, ClienteId)
('2025-10-01', '100.80', 100),
('2025-09-10', '49.99', 100),
('2025-09-23', '350.00', 101);
GO

SELECT * FROM Cliente;
SELECT * FROM Pedido;

-- AJUSTAR EMAIL DE CLIENTE
UPDATE Cliente SET Email = 'gmail@email.com'
WHERE ClienteId = 101;

-- AJUSTAR VALOR DE PEDIDO
UPDATE Pedido SET Valor = Valor + '10.00'
WHERE PedidoId = 101;

-- RENOMEAR TABELA CLIENTE PARA FUNCIONARIO
EXEC sp_rename 'Cliente', 'Funcionario';
SELECT * FROM Funcionario;

-- RENOMEAR A COLUNA ClienteId
EXEC sp_rename 'Funcionario.ClienteId', 'FuncionarioId', 'COLUMN';
SELECT * FROM Funcionario;

-- ALTERAR TAMANHO DO TIPO DE DADO
ALTER TABLE Funcionario
ALTER COLUMN Nome VARCHAR(150) NOT NULL;

-- VER A ESTRUTURA DA TABELA
EXEC sp_help 'Funcionario';

-- DELETAR UM FUNCIONARIO
DELETE Funcionario
WHERE FuncionarioId = 100

-- APAGAR A CHAVE PRIMARIA DA TABELA PEDIDO
ALTER TABLE Pedido
DROP CONSTRAINT Pk_Pedido;

-- RECRIAR A CHAVE PRIMARIA
ALTER TABLE Pedido
ADD CONSTRAINT Pk_Pedido PRIMARY KEY (PedidoId)

-- ALTERAR TABELA PEDIDO
ALTER TABLE Pedido
DROP CONSTRAINT Fk_Pedido
-- RECRIAR FK COM ON DELETE CASCADE
ALTER TABLE Pedido
ADD CONSTRAINT Fk_Pedido_Cliente
FOREIGN KEY (ClienteId) REFERENCES Funcionario(FuncionarioId)
ON DELETE CASCADE
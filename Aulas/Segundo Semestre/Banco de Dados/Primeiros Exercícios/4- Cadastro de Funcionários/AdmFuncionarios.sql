CREATE DATABASE Administracao;

USE Administracao;

CREATE TABLE Funcionarios(
IdFuncionario INT PRIMARY KEY,
Nome NVARCHAR(100),
Cargo NVARCHAR(100),
Salario DECIMAL(10,2)
);

INSERT INTO Funcionarios VALUES
(1, 'Afonso', 'Inspetor', 1999.99),
(2, 'Juremildo', 'Gerente', 3999.99),
(3, 'Fernanda', 'Atendente', 1679.99),
(4, 'Vanderley', 'Repositor', 2039.00),
(5, 'Jeremias', 'Coordenador', 2559.39);

SELECT * FROM Funcionarios WHERE Salario > 3000.00;

SELECT * FROM Funcionarios WHERE Cargo = 'Coordenador';

SELECT Nome, Cargo FROM Funcionarios;
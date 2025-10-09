CREATE DATABASE Video_Streaming;
GO

USE Video_Streaming;
GO

-- =================================================================
-- 1. CRIACAO DAS TABELAS
-- =================================================================

-- Tabela Pai: Estudio
CREATE TABLE Estudio(
    Id_Est INT PRIMARY KEY,
    Nome_Est VARCHAR(40) UNIQUE NOT NULL
);
GO

-- Tabela Filha de Estudio: Serie
CREATE TABLE Serie(
    Id_Serie INT PRIMARY KEY,
    Titulo_Serie VARCHAR(40) NOT NULL,
    Id_Est INT,
    CONSTRAINT FK_Serie_Estudio FOREIGN KEY (Id_Est) REFERENCES Estudio(Id_Est)
);
GO

-- Tabela Filha de Serie: Episodio
CREATE TABLE Episodio(
    Id_Ep INT PRIMARY KEY,
    Titulo_Ep VARCHAR(40) NOT NULL,
    Id_Serie INT,
    CONSTRAINT FK_Episodio_Serie FOREIGN KEY (Id_Serie) REFERENCES Serie(Id_Serie)
);
GO

-- Tabela Independente: Usuario
CREATE TABLE Usuario(
    Id_User INT PRIMARY KEY,
    Nome_User VARCHAR(30) NOT NULL,
    Email VARCHAR(50) UNIQUE
);
GO

PRINT 'Tabelas criadas com sucesso!';
GO

-- =================================================================
-- 2. INSERCAO DE DADOS
-- =================================================================

-- TABELA ESTUDIO
INSERT INTO Estudio VALUES
(1, 'A'),
(2, 'B'),
(3, 'C'),
(4, 'D'),
(5, 'E'),
(6, 'F'),
(7, 'G'),
(8, 'H');
GO

-- TABELA SERIE
INSERT INTO Serie VALUES
(11, 'AA', 1),
(22, 'BB', 2),
(33, 'CC', 3),
(44, 'DD', 4),
(55, 'EE', 5),
(66, 'FF', 6),
(77, 'GG', 7),
(88, 'HH', 8);
GO

-- TABELA EPISODIO
INSERT INTO Episodio VALUES
(111, 'AAA', 11),
(112, 'AAB', 11),
(221, 'BBA', 22),
(222, 'BBB', 22),
(331, 'CCA', 33),
(332, 'CCB', 33),
(441, 'DDA', 44),
(551, 'EEA', 55),
(552, 'EEB', 55),
(661, 'FFA', 66),
(771, 'GGA', 77),
(881, 'HHA', 88);
GO

-- TABELA USUARIO
INSERT INTO Usuario VALUES
(1111, 'AAAA', 'aaaa@email.com'),
(2222, 'BBBB', 'bbbb@email.com'),
(3333, 'CCCC', 'cccc@email.com'),
(4444, 'DDDD', 'dddd@email.com'),
(5555, 'EEEE', 'eeee@email.com'),
(6666, 'FFFF', 'ffff@email.com'),
(7777, 'GGGG', 'gggg@email.com'),
(8888, 'HHHH', 'hhhh@email.com'),
(9999, 'IIII', 'iiii@email.com'),
(1010, 'JJJJ', 'jjjj@email.com'),
(11111, 'KKKK', 'kkkk@email.com'),
(1212, 'LLLL', 'llll@email.com');
GO

-- =================================================================
-- 3. MANIPULACAO DOS DADOS
-- =================================================================

SELECT EP.Titulo_Ep, S.Titulo_Serie, ES.Nome_Est, EP.Id_Ep, S.Id_Serie, ES.Id_Est
FROM Serie S
LEFT JOIN Estudio ES ON S.Id_Est = ES.Id_Est
RIGHT JOIN Episodio EP ON S.Id_Serie = EP.Id_Serie;

SELECT * FROM Usuario;
GO

UPDATE Usuario SET Nome_User = 'AAAAtualizado'
WHERE Nome_User = 'AAAA';
GO

DELETE FROM Usuario WHERE Nome_User = 'KKKK';
GO

EXEC sp_rename Usuario, Usuariooo;
GO

EXEC sp_rename 'Usuariooo.Nome_User', 'Nome_Usuario', 'COLUMN';
GO

ALTER TABLE Usuariooo ALTER COLUMN Nome_Usuario NVARCHAR(100) NOT NULL;
GO

-- Nao eh possivel adicionar colunas com NOT NULL
ALTER TABLE Usuariooo ADD Idade NVARCHAR(50);
GO

ALTER TABLE Serie
DROP CONSTRAINT FK_Serie_Estudio;
GO

ALTER TABLE Serie
ADD CONSTRAINT FK_Serie_Estudio
FOREIGN KEY (Id_Est) REFERENCES Estudio(Id_Est)
ON DELETE CASCADE;
GO

SELECT Id_Serie, Titulo_Serie FROM Serie WHERE Id_Est = 1;
SELECT Id_Ep, Titulo_Ep FROM Episodio WHERE Id_Serie = 11;
GO

DELETE FROM Estudio WHERE Id_Est = 1;
GO

SELECT Id_Serie, Titulo_Serie FROM Serie WHERE Id_Est = 1;
SELECT Id_Ep, Titulo_Ep FROM Episodio WHERE Id_Serie = 11;
GO

ALTER TABLE Episodio
DROP CONSTRAINT FK_Episodio_Serie;
GO

ALTER TABLE Episodio
ADD CONSTRAINT FK_Episodio_Serie
FOREIGN KEY (Id_Serie) REFERENCES Serie(Id_Serie)
ON DELETE CASCADE;
GO

DELETE FROM Estudio WHERE Id_Est = 1;
GO

SELECT * FROM Serie WHERE Id_Serie = 11;
SELECT * FROM Episodio WHERE Id_Serie = 11;
GO
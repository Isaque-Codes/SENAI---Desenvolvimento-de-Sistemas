#### Na saída do comando `ls -l`, cada linha descreve um arquivo ou diretório com a seguinte estrutura:

```
[TIPO][PERMISSÕES] [N_LINKS] [USUÁRIO] [GRUPO] [TAMANHO] [DATA] [NOME]
```

- **TIPO**: Indica o tipo de arquivo:
    
    |Símbolo|Tipo de Arquivo|
    |---|---|
    |`d`|Diretório|
    |`-`|Arquivo regular (texto, imagem, etc.)|
    |`l`|Link simbólico (atalho para outro arquivo)|
    |`s`|Socket (comunicação entre processos)|
    |`p`|Tubo (pipe, comunicação entre processos)|
    |`b`|Dispositivo de bloco (ex.: discos)|
    |`c`|Dispositivo de caractere (ex.: teclado)|
    
- **PERMISSÕES**: Define permissões de leitura (`r`), escrita (`w`) e execução (`x`) para dono, grupo e outros.
    
- **N_LINKS**: Número de links físicos associados ao arquivo.
    
- **USUÁRIO**: Proprietário do arquivo.
    
- **GRUPO**: Grupo proprietário do arquivo.
    
- **TAMANHO**: Tamanho do arquivo em bytes.
    
- **DATA**: Data e hora da última modificação.
    
- **NOME**: Nome do arquivo ou diretório.
    

**Exemplo**:

```
-rw-r--r-- 1 root root 47816 Dec 7 2017 bootstrap.log
```

- `-`: Arquivo regular
- `rw-r--r--`: Dono tem leitura/escrita, grupo e outros têm apenas leitura
- `1`: Um link físico
- `root`: Proprietário é root
- `root`: Grupo é root
- `47816`: Tamanho de 47.816 bytes
- `Dec 7 2017`: Modificado em 7 de dezembro de 2017
- `bootstrap.log`: Nome do arquivo
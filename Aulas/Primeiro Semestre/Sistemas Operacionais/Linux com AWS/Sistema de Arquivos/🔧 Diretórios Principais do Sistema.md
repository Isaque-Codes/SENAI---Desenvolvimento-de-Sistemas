- **`bin -> usr/bin`**  
    Link simbólico. Contém comandos essenciais (como `ls`, `cp`, `mv`) para todos os usuários. Agora geralmente movido para `/usr/bin`.
    
- **`sbin -> usr/sbin`**  
    Link simbólico. Guarda comandos administrativos (como `reboot`, `fdisk`), normalmente usados por `root`.
    
- **`lib -> usr/lib`**  
    Link simbólico. Armazena bibliotecas essenciais (como DLLs do Linux). Usadas por programas de `/bin` e `/sbin`.
    
- **`lib64 -> usr/lib64`**  
    Link simbólico para bibliotecas de 64 bits.
    
- **`usr/`**  
    Programas, bibliotecas e arquivos de leitura geral (ex: `/usr/bin`, `/usr/lib`, `/usr/share`). É onde fica "a maioria" dos softwares
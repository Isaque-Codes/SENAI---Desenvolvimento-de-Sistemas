using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace _4__Comparação
{
    public class Programador : Funcionario, ITrabalhador
    {
        public override void Trabalhar() => Console.WriteLine($"{Nome} esta programando...");

        public void ExecutarTarefa() => Console.WriteLine($"{Nome} concluiu uma tarefa.");
    }
}
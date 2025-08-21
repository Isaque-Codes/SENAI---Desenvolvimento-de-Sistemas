#include <arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

void lerSerial(char *buffer, int tamanhoMaximo);

//* VARIÁVEIS DA LEITURA DO TEOR DE CO
const int pinoFumaca = 34;
unsigned long ultimaLeituraCO = 0;
const unsigned long intervalo = 1000;

//* VARIÁVEIS DA LEITURA DA UMIDADE
const int pinoChuva = 35;
unsigned long ultimaLeituraChuva = 0;

void setup()
{
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  Serial.println("Sensor de fumaça iniciado...");
  Serial.println("Sensor de chuva iniciado...");
  Serial.println("Para ler o teor de umidade e a concentracao de CO, digite 'leitura'.");
  lcd.print("Chuva: ");
  lcd.setCursor(8, 0);
  lcd.print("Gases no ar:");
}

void loop()
{
  //* VARIÁVEIS QUE REGISTRAM OS VALORES DAS LEITURAS
  static int teorCO;
  static bool estaChovendo;

  //* LEITURA DO TEOR DE CO
  unsigned long tempoAtual = millis();

  if (tempoAtual - ultimaLeituraCO >= intervalo)
  {
    ultimaLeituraCO = tempoAtual;

    int leituraFumaca = analogRead(pinoFumaca);

    //? Mapeia para escala de 0 a 10
    float intensidadeCO = map(leituraFumaca, 300, 2000, 0, 10.0);
    intensidadeCO = constrain(intensidadeCO, 0, 10);
    teorCO = intensidadeCO;

    if (intensidadeCO > 0)
    {
      lcd.setCursor(9, 1);
      lcd.print(intensidadeCO);
      lcd.print("   ");

      if (intensidadeCO < 5.0)
      {
        lcd.setCursor(8, 2);
        lcd.print("Seguro      ");
        lcd.setCursor(8, 3);
        lcd.print("            ");
      }
      else if (intensidadeCO >= 5.0 && intensidadeCO < 7.5)
      {
        lcd.setCursor(9, 2);
        lcd.print("Alerta");
        lcd.setCursor(8, 3);
        lcd.print("Use EPI     ");
      }
      else if (intensidadeCO >= 7.5)
      {
        lcd.setCursor(9, 2);
        lcd.print("Perigo");
        lcd.setCursor(8, 3);
        lcd.print("Saia rapido!");
      }
    }
  }

  //* LEITURA DA UMIDADE
  if (tempoAtual - ultimaLeituraChuva >= intervalo)
  {
    ultimaLeituraChuva = tempoAtual;

    int leituraChuva = analogRead(pinoChuva);

    int intensidadeChuva = map(leituraChuva, 2500, 500, 0, 10);
    intensidadeChuva = constrain(intensidadeChuva, 0, 10);

    if (intensidadeChuva > 0)
    {
      lcd.setCursor(0, 1);
      lcd.print("Molhado");
      estaChovendo = true;
    }
    else
    {
      lcd.setCursor(0, 1);
      lcd.print("Seco   ");
      estaChovendo = false;
    }
  }

  //* EXECUCAO DE COMANDO DA STRING C FORMADA PELA FUNCAO "lerSerial"
  if (Serial.available()) //? Se houverem dados na UART
  {
    static char leitura[100]; //? String C que executa o comando
    lerSerial(leitura, 100);  //? Le os dados do buffer do pc e os envia ao buffer da UART, com enter

    if (strlen(leitura) > 0) //? So executa comandos se houver uma string completa (enter ja foi pressionado)
    {
      if (strcmp(leitura, "leitura") == 0) //? Se o comando foi "leitura"
      {
        sprintf(leitura, "Concentracao de CO: %d. Estado da umidade: %s.", teorCO, estaChovendo ? "Umido" : "Seco");
        Serial.println(leitura); //? Formata string com valores dos sensores e imprime na serial
        leitura[0] = '\0';       //? Limpa o buffer para a proxima leitura
      }
    }
  }
}

//* FUNÇÃO PARA LEITURA E ARMAZENAMENTO DA SERIAL
void lerSerial(char *buffer, int tamanhoMaximo)
{
  static int i = 0; //? Indice estatico: guarda a posicao atual de leitura entre chamadas da funcao

  while (Serial.available() > 0 && i < tamanhoMaximo - 1) //? Enquanto houverem dados na UART e espaco na string C
  {
    char caractere = Serial.read(); //? Le proximo caractere do buffer UART

    if (caractere == '\n' || caractere == '\r') //? Verifica se eh caractere de fim de linha (enter)
    {
      if (i > 0) //? Se ja recebeu caracteres validos antes do enter
      {
        buffer[i] = '\0'; //? Termina a string com o ponteiro "nulo"
        i = 0;            //? Reseta indice para proxima leitura
        return;           //? Retorna com comando completo
      }
      i = 0; //? Se o enter foi digitado sem caracteres, apenas reseta o indice para proxima leitura
    }
    else
    {
      buffer[i++] = caractere; //? Armazena caractere valido na string C
    }
  }
  buffer[i] = '\0'; //? Garante terminacao nula para strings parciais
}
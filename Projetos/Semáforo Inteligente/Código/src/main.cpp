#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

#define pinButton 4
#define pinLedRed 19
#define pinLedYellow 5
#define pinLedGreen 18

void setup()
{
  pinMode(pinButton, INPUT_PULLUP);
  pinMode(pinLedRed, OUTPUT);
  pinMode(pinLedYellow, OUTPUT);
  pinMode(pinLedGreen, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Light Phase:       ");
  lcd.setCursor(0, 2);
  lcd.print("Remaining Time: ");

  Serial.begin(115200);
}

void loop()
{
  // --- Variáveis do tempo de cada fase ---
  const unsigned long redTime = 1000;
  const unsigned long yellowTime = 1000;
  const unsigned long greenTime = 50000;

  // Variáveis de estado para o controle de tempo não-bloqueante (sem delay).
  static unsigned long beginTime = 0;         // Armazena o momento em que a fase atual começou.
  unsigned long currentTime = millis();       // Tempo atual, capturado uma vez por loop para consistência.
  static long remainingTime = 0;              // Tempo restante da fase atual.
  
  // Variáveis de estado para a lógica adaptativa.
  static byte trafficLightPhase = 0;          // Controla a fase atual (0: Vermelho, 1: Verde, 2: Amarelo).
  static bool alteredTime = false;            // Flag que indica se o tempo do sinal verde foi alterado pelo botão.
  static unsigned long progress;              // Armazena quanto tempo da fase verde já passou antes do botão ser pressionado.
  static unsigned long newGreenTime;          // O novo tempo de duração recalculado para a fase verde.
  static long updatedRemainingTime;           // O tempo restante ajustado após o recálculo.

  // --- Sessão da lógica da transição de fases ---
  if (trafficLightPhase == 0) // Fase Vermelha
  {
    digitalWrite(pinLedYellow, LOW);
    digitalWrite(pinLedRed, HIGH);
    remainingTime = redTime - (currentTime - beginTime);

    if (remainingTime <= 0)
    {
      trafficLightPhase = 1;
      beginTime = currentTime; // Reseta o cronômetro para a próxima fase.
    }
  }
  else if (trafficLightPhase == 1) // Fase verde (com lógica adaptativa)
  {
    // Se o tempo não foi alterado, usa o tempo padrão (greenTime).
    // Se foi alterado, usa o novo tempo recalculado (updatedRemainingTime).
    if (alteredTime == false)
    {
      digitalWrite(pinLedGreen, HIGH);
      digitalWrite(pinLedRed, LOW);
      remainingTime = greenTime - (currentTime - beginTime);
    }
    else
    {
      remainingTime = updatedRemainingTime - (currentTime - beginTime);
    }

    if (remainingTime <= 0)
    {
      trafficLightPhase = 2;
      alteredTime = false; // Reseta a flag para o próximo ciclo verde.
      beginTime = currentTime;
    }
  }
  else if (trafficLightPhase == 2) // Fase Amarela
  {
    digitalWrite(pinLedGreen, LOW);
    digitalWrite(pinLedYellow, HIGH);
    remainingTime = yellowTime - (currentTime - beginTime);

    if (remainingTime <= 0)
    {
      trafficLightPhase = 0;
      beginTime = currentTime;
    }
  }

  // --- Sessão de Tratamento do botão (Debounce e lógica adaptativa) ---
  unsigned long time = millis();

  // Variáveis de estado para o debounce do botão.
  static unsigned long lastTime = 0;          // Armazena o momento da última mudança de estado do botão.
  const byte debounceTime = 50;               // Tempo de espera para considerar o estado do botão estável.

  bool stateButton = digitalRead(pinButton);
  static bool lastStateButton = 1;            // Último estado lido do botão.
  static bool lastAction = 1;                 // Última ação confirmada (evita múltiplas ações por um único aperto).

  if (stateButton != lastStateButton)
  {
    lastTime = time;
  }

  // Ação só é executada se o estado do botão permaneceu estável pelo tempo de debounce.
  if ((time - lastTime) > debounceTime)
  {
    if (stateButton != lastAction)
    {
      lastAction = stateButton;
      // A lógica de recálculo só é acionada se o botão for pressionado (stateButton == LOW),
      // durante a fase verde (trafficLightPhase == 1) e se o tempo ainda não foi alterado neste ciclo.
      if (!stateButton && trafficLightPhase == 1 && alteredTime == false)
      {
        // Calcula quanto tempo do sinal verde já se passou.
        progress = (greenTime - remainingTime);

        // Lógica para reduzir o tempo do sinal verde.
        // Quanto mais cedo o botão for pressionado, maior a redução de tempo
        if (remainingTime > (greenTime * 75) / 100)
        {
          alteredTime = true;
          newGreenTime = (greenTime * 60) / 100;
          remainingTime = newGreenTime - progress;
          updatedRemainingTime = remainingTime;
          beginTime = currentTime; // Reseta o cronômetro com o novo tempo restante.
        }
        else if (remainingTime > (greenTime * 50) / 100 && remainingTime <= (greenTime * 75) / 100)
        {
          alteredTime = true;
          newGreenTime = (greenTime * 40) / 100;
          remainingTime = newGreenTime - progress;
          updatedRemainingTime = remainingTime;
          beginTime = currentTime;
        }
        else if (remainingTime > (greenTime * 25) / 100 && remainingTime <= (greenTime * 50) / 100)
        {
          alteredTime = true;
          newGreenTime = (greenTime * 20) / 100;
          remainingTime = newGreenTime - progress;
          updatedRemainingTime = remainingTime;
          beginTime = currentTime;
        }
      }
    }
  }
  lastStateButton = stateButton;

  // --- Sessão de atualização do Display LCD ---
  if (trafficLightPhase == 0)
  {
    lcd.setCursor(0, 0);
    lcd.print("Light Phase: RED   ");
    lcd.setCursor(0, 2);
    lcd.print("Remaining Time: ");
    lcd.setCursor(16, 2);
    lcd.print(remainingTime / 1000);
  }
  else if (trafficLightPhase == 1)
  {
    lcd.setCursor(0, 0);
    lcd.print("Light Phase: GREEN ");
    lcd.setCursor(0, 2);
    lcd.print("Remaining Time: ");
    lcd.setCursor(16, 2);
    lcd.print(remainingTime / 1000);
  }
  else if (trafficLightPhase == 2)
  {
    lcd.setCursor(0, 0);
    lcd.print("Light Phase: YELLOW");
    lcd.setCursor(0, 2);
    lcd.print("Remaining Time: ");
    lcd.setCursor(16, 2);
    lcd.print(remainingTime / 1000);
  }
}
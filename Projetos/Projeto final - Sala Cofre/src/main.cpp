// Exemplo de uso da classe FingerprintSensor

#include "sensorDeDigitais.h"

// Defina os pinos RX e TX do ESP32 que serão conectados ao sensor.
#define FINGERPRINT_RX_PIN 16
#define FINGERPRINT_TX_PIN 17

// Crie um objeto HardwareSerial para a comunicação com o sensor.
HardwareSerial mySerial(2);

// Crie o objeto do sensor de impressão digital
FingerprintSensor fingerSensor(&mySerial, 0x00000000, FINGERPRINT_RX_PIN, FINGERPRINT_TX_PIN);

void setup()
{
    if (!fingerSensor.begin(57600))
    {
        while (1)
        { // Trava o programa se o sensor nao for encontrado
            delay(1);
        }
    }
}

void loop()
{
    if (Serial.available())
    {
        char choice = Serial.read();
        switch (choice)
        {
        case '1':
            fingerSensor.enrollFingerprint();
            break;
        case '2':
            fingerSensor.verifyFingerprint();
            break;
        case '3':
            fingerSensor.deleteFingerprint();
            break;
        case '4':
            fingerSensor.getFingerprintCount();
            break;
        case 'm':
            fingerSensor.printMenu();
            break;
        default:
            Serial.println("Opcao invalida. Digite 'm' para o menu.");
            break;
        }
    }
}

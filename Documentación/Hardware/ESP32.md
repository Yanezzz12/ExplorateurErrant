# ESP32

El ESP32 es un microcontrolador de 32 bits desarrollado por Espressif Systems, diseñado para aplicaciones de sistemas embebidos, Internet de las Cosas (IoT), automatización y robótica. Incorpora un procesador de doble núcleo con una frecuencia de operación de hasta 240 MHz, conectividad Wi-Fi y Bluetooth integradas, además de una amplia variedad de periféricos, como entradas y salidas digitales, conversores analógico-digitales (ADC), convertidores digital-analógicos (DAC), temporizadores, interfaces de comunicación y módulos PWM. 


## Índice

- [Características](#características)
- [Mapa de pines](#pinout)
- [Pines PWM](#pines-pwm)
- [Resolución PWM](#resolución)
- [Ejemplo PWM](#implementación-base)
- [Evitar pines](#evitar-pines)


## Características

| Característica          | Nivel          |
| :---------------------: | :------------: |
| Microcontrolador        | ESP32-WROOM-32 |
| Voltaje de operación    | 3.3V           |
| Número de núcleos       | 2              |
| Frecuencia de operación | 240 MHz        |
| Resolución PWM          | 20 bits máximo |
| SRAM                    | 520 KB         |
| Canales PWM             | 16             |
| UART                    | 3              |
| SPI                     | 4 interfaces   |
| I2C                     | 2 interfaces   |
| I2S                     | 2 interfaces   |
| Temperatura operación   | −40 °C a 85 °C |

Notas:
- Arquitectura de 32 bits
- Comunicación inalámbrica Wifi y bluetooth
- Conversores ADC de 12 bits y DAC de 8 bits
- 2 SPI disponibles al usuario
- Existen modos de bajo consumo

## PINOUT

![[Pasted image 20260711180152.png|697]]

![[Pasted image 20260711175926.png]]

## Pines PWM

El ESP32 tiene 16 canales PWM independientes:

- GPIO 2
- GPIO 4
- GPIO 5
- GPIO 12
- GPIO 13
- GPIO 14
- GPIO 15
- GPIO 16
- GPIO 17
- GPIO 18
- GPIO 19
- GPIO 21
- GPIO 22
- GPIO 23
- GPIO 25
- GPIO 26
- GPIO 27
- GPIO 32
- GPIO 33

### Resolución

En un ESP32 la resolución máxima teórica es 20 bits (En el pin LEDC). 

No es recomendable utilizar la resolución máxima del PWM del microcontrolador, ya que una mayor resolución reduce la frecuencia máxima de la señal PWM y no proporciona beneficios significativos en el control de motores de corriente continua.

| Resolución | Nivel     | Aplicación      |
| :--------: | :-------: | :-------------: |
| 8 bits     | 256       | Motores DC      |
| 10 bits    | 1 024     | Servomotores    |
| 12 bits    | 4 096     | Iluminación LED |
| 16 bits    | 65 536    | -               |
| 20 bits    | 1 048 576 | -               |


### Implementación

```c
const int motorPWM = 18;

void setup() 
{
    // Frecuencia: 1000 Hz
    // Resolución: 8 bits
    ledcAttach(motorPWM, 1000, 8);
}

void loop() 
{
    // Duty Cycle = 50%
    ledcWrite(motorPWM, 128);
}
```

Implementación para motores

```c
const int motorPWM = 18;

void setup()
{
    // Frecuencia: 20 kHz
    // Resolución: 10 bits (0-1023)
    ledcAttach(motorPWM, 20000, 10);
}

void loop()
{
    // 25% de velocidad
    ledcWrite(motorPWM, 256);
    delay(2000);

    // 75%
    ledcWrite(motorPWM, 768);
    delay(2000);

    // Detener motor
    ledcWrite(motorPWM, 0);
    delay(2000);
}
```

### Evitar pines

- **GPIO 34, 35, 36 y 39**: **Solo de entrada**, por lo que **no pueden generar PWM**.
- **GPIO 6 al 11**: Conectados a la memoria flash interna y no deben usarse.
- **GPIO 0, 2, 12 y 15**: Pines de arranque.
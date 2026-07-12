# Cableado de motores con puente H y microcontrolador

Cableado de motores con puente H y microcontrolador, encoder no contemplado.

## Índice

- [Componentes](#componentes)
- [Ejemplo Arduino](#arduino)
- [Ejemplo ESP32](#esp32)
- [TODO](#todo)
- [Fuentes](#fuentes)

## Componentes

- Microcontrolador [ESP32](../Microcontroladores/ESP32.md)
- [Puente H](../MódulosControl/PuenteH.md)
- [Motores](../Actuadores/MotorDC.md)

## Cableado

![[HBridgeMotorsMicroConnection.png]]


## Ejemplos de uso

### Arduino

```c
// Motor 1
const int ENA = 10;
const int IN1 = 9;
const int IN2 = 8;

// Motor 2
const int ENB = 5;
const int IN1 = 7;
const int IN2 = 6;

void setup()
{
    // ENA y ENB de
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
}

void moveForward()
{
    // Dirección motor 1
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    // Velocidad motor 1
    analogWrite(ENA, 255);

    // Dirección motor 2
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);
    // Velocidad motor 2
    analogWrite(ENB, 255);
}

void stopMotors()
{   
    // Motor 1
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, 0);
    // Motor 2
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, 0);
}

void loop()
{
    moveForward();
    delay(5000);
    stopMotors();
    delay(2000);
}
```
### ESP32

(Buscar implementación en ESP32)

```c

```

## TODO

- Revisar validez de:
	- La caída de tensión hace que si al voltaje de entrada le llegan 12 V, el motor sólo tenga 9V?
	- Sí, exactamente. Esa es una de las principales limitaciones del L298N.
	- Si esto es verdad, requeriríamos de 15V para liberar el potencial del motor completamente, está por verse
- Construir un ejemplo para ESP32

Notas:
- El voltaje de entrada llega a los motores, tiene un rango de operación de 3V a 35V
- Si el jumper regulador está puesto, el puente H sirve para controlar motroes de 5V a 12V y habrá salida de 5V
- Si el jumper no está colocado, se pueden controlar motores de 12V a 35V y el pin debe recibir 5V para poder alimentar la parte lógica del driver
- ENA Y ENB DEBEN ser conectados a pines PWM


## Fuentes

https://www.taloselectronics.com/blogs/tutoriales/puente-h-doble-l298n
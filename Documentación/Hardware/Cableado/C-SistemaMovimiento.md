# Cableado de motores con puente H y microcontrolador

Cableado del sistema de movimiento con puentes H, microcontrolador y encoders.

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
- [Encoders](../Sensores/EncoderMDC.md)

## Cableado

![[Cableado2Motores.png]]

Para el control de 2 motores se utilizan 10 pines del ESP32

## Notas
Creo que es posible que un ESP32 se encargue del control de los 6 motores si movemos la carga de decisión de movimiento a otro microcontrolador.
Un ESP32 se encargaría de la lectura de encoders, el procesamiento del PID y enviar la señal PWM a los motores.





## TODO

Terminar y continuar
Poner un código
https://cursos.asimov.mx/curso_esp32/modulo_11/control-pid-de-velocidad-en-motor-dc.html
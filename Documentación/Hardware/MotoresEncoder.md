# Motores con encoder

Información y notas acerca del componente y su uso dentro del proyecto

# Índice 

- PINOUT
- Características y especificaciones
- Cableado con puente H [PuenteH](../Hardware/PuenteH.md)

## PINOUT

![[PinoutEncoder.png]]

| Color    | Cable            |
| :------: | :--------------: |
| Rojo     | Motor (-)        |
| Negro    | GND Encoder      |
| Amarillo | Sensor A Encoder |
| Verde    | Sensor B Encoder |
| Azul     | 3.3V/5V Encoder  |
| Gris     | Motor (+)        |

## Características y especificaciones

| Propiedad                     |    Valor    | Unidades |
| :---------------------------- | :---------: | :------: |
| Reducción                     |    45:1     |    1     |
| Velocidad sin carga           |     140     |   RPM    |
| Corriente sin carga           |    ≤ 70     |    mA    |
| Velocidad nominal             |     70      |   RPM    |
| Corriente nominal             |    ≤ 0.8    |    A     |
| Torque nominal                |    0.42     |   N m    |
| Corriente por bloqueo (stall) |     ≤ 2     |    A     |
| Par de bloqueo (stall)        |     8.5     |  kg·cm   |
| Resolución de sensor hall     | 493.9 ± 10% |   PPR    |


Cableado de motores con puente H L298N




![[HBridgeMotorsMicroConnection.png]]


Fuente: https://www.taloselectronics.com/blogs/tutoriales/puente-h-doble-l298n

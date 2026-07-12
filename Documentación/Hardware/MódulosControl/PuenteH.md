# Módulo de puente H L298N

El módulo de puente H sirve para controlar la dirección de giro de un motor a través de invertir la polaridad del voltaje aplicado en sus terminales.

La modulación de ancho de banda (PWM) en los pines ENA y ENB permite controlar también la velocidad angular de los motores.

## Índice:

- [Características](#características)
- [PINOUT](#pinout)
- [Fuente](#fuente)

## Características

|    Característica     |    Valor     |
| :-------------------: | :----------: |
|       Integrado       |    L298N     |
|    Voltaje entrada    |   5V - 35V   |
|    Voltaje lógico     |      5V      |
|   Corriente lógica    |    36 mA     |
|   Corriente máxima*   |      2A      |
| Corriente recomendada |  1A - 1.5A   |
|      Temperatura      | -20 ~ 135 °C |
|       Potencia        |     25 W     |
|   Número de canales   |      2       |
|         Peso          |     30 g     |
|      Dimensiones      | 43x43x27 mm3 |

Notas:
- Corriente máxima -> por canal 

## PINOUT

![[HBridgePinout.png]]

Notas:
- El voltaje de entrada llega a los motores, tiene un rango de operación de 3V a 35V
- Si el jumper regulador está puesto, el puente H sirve para controlar motroes de 5V a 12V y habrá salida de 5V
- Si el jumper no está colocado, se pueden controlar motores de 12V a 35V y el pin debe recibir 5V para poder alimentar la parte lógica del driver
- ENA Y ENB DEBEN ser conectados a pines PWM

## Fuente
https://www.taloselectronics.com/blogs/tutoriales/puente-h-doble-l298n
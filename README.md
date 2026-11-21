# Arduino Temperature & Humidity LCD Monitor

A microcontroller-based environmental monitoring project that reads real-time ambient temperature and humidity data and displays the values on an LCD screen.

## Overview

This project acquires temperature and relative humidity measurements from a digital sensor using an Arduino microcontroller and outputs formatted readings locally on an LCD display. It is designed as a simple, standalone hardware prototype for continuous local monitoring.

## Hardware & Components

* **Microcontroller:** Arduino Uno (or compatible board)
* **Temperature & Humidity Sensor:** [DHT11]
* **Display:** [16x2 Character LCD ]
* **Supporting Components:** Breadboard, jumper wires.

## Pinout / Wiring

Update the pins below to match your circuit and code:

| Component Pin | Arduino Pin | Notes |
| :--- | :--- | :--- |
| Sensor `VCC` | `5V` | |
| Sensor `GND` | `GND` | |
| Sensor `DATA` | `D2` | Include pull-up resistor if required by module |
| LCD `SDA` *(if I2C)* | `A4` | `SDA` on Uno |
| LCD `SCL` *(if I2C)* | `A5` | `SCL` on Uno |

## Software & Libraries

* **IDE:** Arduino IDE
* **Libraries Required:**
  * `DHT sensor library` (and `Adafruit Unified Sensor`, if applicable)
  * `LiquidCrystal` or `LiquidCrystal_I2C`

## Getting Started

1. Wire the sensor and LCD display to the Arduino on a breadboard according to your pinout.
2. Open the `.ino` sketch in the Arduino IDE.
3. Install the required libraries via **Sketch > Include Library > Manage Libraries...**.
4. Select your **Board** and **COM Port**, then click **Upload**.
5. Verify live temperature and humidity readings appear on the LCD display.


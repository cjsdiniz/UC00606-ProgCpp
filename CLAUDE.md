# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is an Arduino C++ course project (UC00606) — a weather station simulation running on the **Tinkercad simulator** (Arduino Uno R3). There is no local build system; code is developed as a `.ino` file and run entirely inside Tinkercad's web simulator.

**Deliverable filename:** `ArduinoSimulação.ino`

## Architecture

The program simulates a weather station using three sensors in Tinkercad:

| Sensor | Pin | Simulates |
|--------|-----|-----------|
| TMP36  | Analog (A1) | Temperature (°C) — `rawTemp * (5.0/1024.0)` then `(voltage - 0.5) * 100` |
| Potentiometer | Analog (A0) | Humidity — map `0–1023` to a realistic humidity range |
| DC Motor with Encoder | Digital | Wind speed (anemometer) — read encoder pulses/RPM |

Since Tinkercad sensors are simulated, the program uses **pre-defined arrays** of realistic values (not live sensor reads). Sensor readings are simulated by cycling through or indexing into these arrays.

### Required program structure

```cpp
void setup() {
  Serial.begin(9600);
  // ...
}
void loop() {
  // ...
}
```

### Menu system (via Serial Monitor)

The program must present a text menu with these options:
- **Option 1:** Load initial data (populate the temperature, humidity, wind speed arrays)
- **Option 2:** Display all sensor data
- **Option 3:** Exit / stop the program

### Mandatory language constructs

Every one of these must be used functionally, not just declared:
- `if/else` conditionals
- `switch/case`
- Arrays (for temperature, humidity, wind speed data sets)
- `for` loop and `while` or `do-while` loop
- Functions: at least one with a return value, one without, one with parameters

## TMP36 Temperature Formula

```cpp
int rawTemp = analogRead(tempPin);
float voltage = rawTemp * (5.0 / 1024.0);
float tempC = (voltage - 0.5) * 100;
```

## Data Realism Constraints

Initial data arrays must use realistic Portuguese ambient values:
- Temperatures: plausible ambient range (e.g., 10–35 °C)
- Humidity: coherent with temperature (e.g., higher humidity at moderate temps)
- Wind speed: plausible range (e.g., 0–50 km/h or equivalent RPM)

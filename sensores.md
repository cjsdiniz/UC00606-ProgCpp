# Sensores
| Tipo | Modelo | Função| Implementação |
|--------|------|-------|-----------|
| Temperature & Humidity |DHT11 / DHT22 | Measures ambient thermal energy and moisture. DHT22 is more precise.| Digital	Weather stations, home automation |
| Pressure | BMP180 / BMP280 | Measures atmospheric pressure and estimated altitude.Digital (I2C)|Altimeters, weather forecasting. |

| Sensor  | Function | Implementation Tip |
|--------|------|-------|-----------|
| Anemometer | Measures wind speed. | Usually uses a Hall effect sensor to count rotations. |
| DHT11 / DHT22 | Measures ambient thermal energy and moisture. | Digital | Weather stations, home automation |
| BME280 Environmental Sensor | Measures: Temperature, humidity, and barometric pressure |


- BME280 Environmental Sensor: The "gold standard" for small weather stations.
Measures: Temperature, humidity, and barometric pressure in one tiny module.
Why choose it: It is more accurate than basic DHT sensors and uses the I2C interface, which only requires two wires to the Arduino.


## Para Tinkercad
### EN
Physical Sensor  | Tinkercad Equivalent | Justification for Simulation
--------|------|-------|-----------
BME280 (Temp, Humidity, Pressure) | TMP36 + Potentiometer | Use TMP36 for temperature and a potentiometer to simulate changing barometric pressure or humidity values via analog input.
DHT11 / DHT22 (Temp & Humidity) | TMP36 | The TMP36 is the standard built-in temperature sensor in Tinkercad. It is analog, whereas DHT is digital, so the code logic will differ.
Anemometer (Wind Speed) | DC Motor with Encoder | Use the DC Motor with Encoder to simulate wind rotation. You can read the "RPM" or pulses from the encoder to represent wind speed.

### PT
Sensor físico  | Equivalente no Tinkercad | Justificação da simulação
--------|------|-------|-----------
BME280 (Temperatura, Humidade, Pressão) | TMP36 + potenciómetro | Utilize o TMP36 para a temperatura e um potenciómetro para simular valores variáveis de pressão barométrica ou humidade através de entrada analógica.
DHT11 / DHT22 (Temperatura e Humidade) | TMP36 | O TMP36 é o sensor de temperatura integrado padrão no Tinkercad. É analógico, enquanto o DHT é digital, pelo que a lógica do código será diferente.
Anemómetro (Velocidade do Vento) | Motor CC com Codificador | Utilize o Motor CC com Codificador para simular a rotação do vento. Pode ler as «RPM» ou os impulsos do codificador para representar a velocidade do vento.


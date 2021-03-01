# Weather Arduino Sensor

The purpose of this project is to build a weather station using Arduino that is capable of collecting temperature, humidity, atmospheric pressure, and altitude data. After collecting these data, it is shown on an OLED display and sent to a base station to store it.

## Sensors
This project was built with the use of an Arduino Nano (Arduino Uno can be used too) and the following sensors:

* **BME280** - Sensor capable of collecting temperature, humidity and pressure data. Altitude should be calculated based on the pressure reading.
* **OLED Graphic Display 128x64 with SSD1306 controller** - Graphical display used to show the collected data by BME280 sensor;
* **NRF24l01** - Wireless transceiver module used to transmit data collected by the sensor to the base station.

## Libraries
The following libraries were used to write the weather station software:

* **Adafruit BME280 Library**: Necessary to access the BME280 sensor by arduino;;
* **Adafruit Unified Sensor**: Dependency necessary to correctly use the Adafruit *BME280 Library*
* **RF24 by TMRh20**: Necessary to use the *NRF24l01* sensor;
* **RF24Network by TMRh20**: Necessary library to create a sensor network using the *NRF24l01* transceiver;
* **U8glib**: Necessary library to write text on the *OLED Graphic Display 128x64*

The libraries listed above must be installed through the **Library Manager** of **Arduino IDE**.

## Electrical Schematic
The figure bellow shows how the physical sensors must be connected on Arduino:

![Image of Arduino Eletronic Schematic](hackaton-arduino.png)

## Related Projects
This project only reads temperature, humidity, pressure, and altitude data and sends it to a base station. A dashboard was also built in HTML5, CSS3, and JS that displays these data to the user by consuming a REST API exposed by the base station. For more details about the base station or dashboard projects, visit:

* [Raspberry Pi Weather Base Station](https://github.com/profbrunolopes/weather-base-station)
* [Weather Station Dashboard](https://github.com/profbrunolopes/weather-dashboard)

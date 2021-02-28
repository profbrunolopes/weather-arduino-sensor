# Weather Arduino Sensor

O intuito deste projeto é construir uma estação metereológica com Arduino utilizando os seguintes sensores:
* **BME280** - Sensor de temperatura, umidade e pressão atmosférica;
* **OLED Graphic Display 128x64 with SSD1306 controller** - Display gráfico para exibir os dados coletado pelo BME280 em tempo real;
* **NRF24l01** - Wireless transceiver modulo utilizado para transmitir os dados da estação metereológica para a estação base.

Além dos componentes elétricos acima, foram utilizado as seguintes bibliotecas:

* **Adafruit BME280 Library**: Biblioteca necessária para utilização do sensor *BME280*;
* **Adafruit Unified Sensor**: Dependência necessária para a utilização correta da *Adafruit BME280 Library*
* **RF24 by TMRh20**: Biblioteca necessária para utilização do sensor *NRF24l01*;
* **RF24Network by TMRh20**: Biblioteca necessária para criação de uma rede de sensores com o *NRF24l01*;
* **U8glib**: Biblioteca necessária para utilizar o OLED *Graphic Display 128x64*

Todas as bibliotecas devem ser intaladas através do *gerenciador de bibliotecas* do Arduino IDE.

Abaixo segue o esquemático elétrico para montagem da estação metereológica com o Arduino:

![Image of Arduino Eletronic Schematic](hackaton-arduino.png)
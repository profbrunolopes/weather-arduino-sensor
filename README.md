# Weather Arduino Sensor

O intuito deste projeto é construir uma estação metereológica com Arduino capaz de coletar dados de temperatura, umidade, pressão atmosférica e altitude e enviar esses dados para uma estação base.

## Sensores
Para construir esse projeto foi utilizado um Arduino Nano (pode-se utilizar um Arduino Uno) com os seguintes sensores:
* **BME280** - Sensor de temperatura, umidade e pressão atmosférica;
* **OLED Graphic Display 128x64 with SSD1306 controller** - Display gráfico para exibir os dados coletado pelo BME280 em tempo real;
* **NRF24l01** - Wireless transceiver modulo utilizado para transmitir os dados da estação metereológica para a estação base.

## Bibliotecas
As biblioetcas listadas abaixo foram utilizadas na escrita so software:

* **Adafruit BME280 Library**: Biblioteca necessária para utilização do sensor *BME280*;
* **Adafruit Unified Sensor**: Dependência necessária para a utilização correta da *Adafruit BME280 Library*
* **RF24 by TMRh20**: Biblioteca necessária para utilização do sensor *NRF24l01*;
* **RF24Network by TMRh20**: Biblioteca necessária para criação de uma rede de sensores com o *NRF24l01*;
* **U8glib**: Biblioteca necessária para utilizar o OLED *Graphic Display 128x64*

Todas as bibliotecas devem ser intaladas através do *gerenciador de bibliotecas* do Arduino IDE.

## Esquematico elétrico
A figura abaixo exibe como os componentes elétricos foram conectados ao Arduino:

![Image of Arduino Eletronic Schematic](hackaton-arduino.png)

## Projetos relacionados

Este projeto apenas realiza a leitura de temperatura, umidade, pressão e altitude e envia esses dados para uma estação base. Também foi construido um dashboard em HTML5, CSS3 e JS que exibe esses dados para o usuário consumindo um API REST que a estação base expõe. Para maiores detalhes sobre o projeto da estação base ou do dashboard, acesse:
* [Raspberry Pi Weather Base Station](http://google.com)
* [Weather Station Dashboard](http://google.com)
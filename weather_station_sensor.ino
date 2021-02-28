#include <Wire.h>
#include <SPI.h>
#include <RF24.h>
#include <RF24Network.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <U8glib.h>

#define PressureAtSeaLevel_HPA (1013.25)

Adafruit_BME280 bme;
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NO_ACK);

RF24 radio(9, 10);
RF24Network network(radio);

const uint16_t this_node = 01;
const uint16_t other_node = 00;

struct payload_t {
  float temp;
  float umid;
  float pres;
  float alti;
};

void setupOled(){
  
  if (u8g.getMode() == U8G_MODE_R3G3B2){
    u8g.setColorIndex(255);
  } else if (u8g.getMode() == U8G_MODE_GRAY2BIT){
    u8g.setColorIndex(3);
  } else if (u8g.getMode() == U8G_MODE_BW){
    u8g.setColorIndex(1);
  } else if (u8g.getMode() == U8G_MODE_HICOLOR){
    u8g.setHiColorByRGB(255, 255, 255);
  }
  
}

void draw(float temp, float umid, float pres, float alti){
  
  char buf[15];
  String tempStr;
  u8g.setFont(u8g_font_8x13B);
  
  tempStr = "T: " + String(temp) + " *C";
  tempStr.toCharArray(buf, 15);
  u8g.drawStr(5, 15, buf);

  tempStr = "U: " + String(umid) + "%";
  tempStr.toCharArray(buf, 15);
  u8g.drawStr(5, 30, buf);

  tempStr = "P: " + String(pres) + " hPa";
  tempStr.toCharArray(buf, 15);
  u8g.drawStr(5, 45, buf);

  tempStr = "A: " + String(alti) + " m";
  tempStr.toCharArray(buf, 15);
  u8g.drawStr(5, 60, buf);

  
}

void setup() {
  Serial.begin(9600);
  bme.begin(0x76);
  setupOled();

  Serial.println(F("Wheater Station - v1.0"));

  SPI.begin();
  if (!radio.begin()) {
    Serial.println(F("Radio hardware not responding!"));
    while (1) {
      // hold in infinite loop
    }
  }
  radio.setDataRate(RF24_250KBPS);
  network.begin(/* Canal */ 120, /* Endereco do nó */ this_node);
  
}

void loop() {

  unsigned long start = millis();

  float temp = bme.readTemperature();
  float umid = bme.readHumidity();
  float pres = bme.readPressure() / 100.0F;
  float alti = bme.readAltitude(PressureAtSeaLevel_HPA);

  u8g.firstPage();

  do{
    draw(temp, umid, pres, alti);
  } while(u8g.nextPage());

  network.update();

  RF24NetworkHeader header(other_node);
  payload_t payload = {temp, umid, pres, alti};
  network.write(header, &payload, sizeof(payload));

  unsigned long stop = millis();
  
  delay(5000 - (stop - start));

}

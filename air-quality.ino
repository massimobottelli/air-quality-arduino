#include <Wire.h>
#include <MHZ19.h>
#include <SoftwareSerial.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"
#include "DHT.h"

#define WAIT 10000 // refresh, in millisec

// SSD1306 display
#define I2C_ADDRESS 0x3C
SSD1306AsciiWire oled;

// DHT-11 temperature and humidity sensor
#define DHTPIN 4
#define DHTTYPE DHT11
#define TOFFSET -1
#define HOFFSET 5

DHT dht(DHTPIN, DHTTYPE);

// CO2 sensor MH-Z19
#define RX_PIN 2
#define TX_PIN 3
#define BAUDRATE 9600
MHZ19 myMHZ19;
SoftwareSerial mySerial(TX_PIN, RX_PIN);

void setup() {

  Serial.begin(9600);

  // initialize DHT11 sensor
  dht.begin();

  // initialize MHZ19 sensor
  mySerial.begin(BAUDRATE);
  myMHZ19.begin(mySerial);
  myMHZ19.autoCalibration();

  // initialize display
  Wire.begin();         
  oled.begin(&Adafruit128x64, I2C_ADDRESS);
  oled.set400kHz();  
  oled.setFont(Adafruit5x7);  
}

void loop() {

  // read DHT11 sensor
  String t = String(dht.readTemperature() + TOFFSET, 1) + " C";
  String h = String(dht.readHumidity() + HOFFSET, 1) + " %";

  // read MHZ19 sensor
  int CO2;
  CO2 = myMHZ19.getCO2();

  // print on serial monitor
  Serial.print("CO2 (ppm): ");                      
  Serial.println(CO2);      

  Serial.print("Temp (°C): ");                      
  Serial.println(t);      

  Serial.print("Humidity (%): ");                      
  Serial.println(h);                              
  Serial.println();                              

  // print on OLED display
  oled.clear();  
  oled.set1X();
  oled.println("AIR QUALITY METER\n");
  oled.set2X();
  oled.print("CO2: ");
  oled.println(CO2);
  oled.print("T: ");
  oled.println(t);
  oled.print("H: ");
  oled.println(h);

  delay(WAIT);
  
}


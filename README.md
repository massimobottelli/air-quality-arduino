# Arduino Air Quality meter

DIY air quality meter based on Arduino UNO microcontroller, a carbon dioxide sensor and a temperature and humidity sensor

## Components:
* Arduino UNO
* SSD1306 OLED display
* MH-Z19 carbon dioxide sensor 
* DHT-11 temperature and humidity sensor

## Arduino IDE required libraries:
* SSD1306Ascii (Greiman) https://github.com/greiman/SSD1306Ascii
* MH-Z19 (Dempsey) https://github.com/WifWaf/MH-Z19
* DHT sensor library (Adafruit) https://github.com/adafruit/DHT-sensor-library

## Connections:

### Display > Arduino
* GND	> GND
* VDD	>	+5 V
* SCK	>	A5
* SDA	>	A4

### MH-Z19 > Arduino
* GND	>	GND
* VDD	>	+5 V
* Rx	>	2
* Tx	>	3

### DHT-11 > Arduino
* GND	>	GND
* VDD	>	+5 V
* Signal >	4

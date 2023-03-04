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

## Code comment

This code is for an air quality meter that measures the temperature, humidity, and carbon dioxide levels in the air.

The code includes several libraries that are required to interface with the sensors and display:

* Wire.h: for communication over the I2C bus
* MHZ19.h: for interfacing with the MH-Z19 CO2 sensor
* SoftwareSerial.h: for software serial communication with the MH-Z19 sensor
* SSD1306Ascii.h and SSD1306AsciiWire.h: for interfacing with the SSD1306 OLED display
* DHT.h: for interfacing with the DHT-11 temperature and humidity sensor

The code defines several constants and variables:

* WAIT: the delay between readings in milliseconds
* I2C_ADDRESS: the address of the OLED display on the I2C bus
* DHTPIN: the pin used to interface with the DHT-11 sensor
* DHTTYPE: the type of DHT sensor being used (DHT11)
* TOFFSET: a temperature offset value used to calibrate the DHT11 sensor
* HOFFSET: a humidity offset value used to calibrate the DHT11 sensor
* RX_PIN and TX_PIN: the pins used for software serial communication with the MH-Z19 sensor
* BAUDRATE: the baud rate used for communication with the MH-Z19 sensor
* myMHZ19: an instance of the MHZ19 class for interfacing with the CO2 sensor
* mySerial: an instance of the SoftwareSerial class for communicating with the MH-Z19 sensor
* dht: an instance of the DHT class for interfacing with the temperature and humidity sensor

The setup function initializes the serial communication, sensors, and OLED display. 
It sets the baud rate for the software serial communication, calibrates the CO2 sensor, and sets the font and communication speed for the OLED display.

The loop function reads the temperature, humidity, and CO2 levels from the sensors, prints them to the serial monitor, and displays them on the OLED display. 
It uses the DHT library to read the temperature and humidity, and the MHZ19 library to read the CO2 level. 
The OLED display is cleared and then the readings are printed using various print and println statements.

The delay function is used to wait for the specified time (WAIT) before taking another set of readings.

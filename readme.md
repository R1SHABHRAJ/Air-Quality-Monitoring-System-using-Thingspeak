# Air Quality Monitor System

This project uses an WiFi enabled board, a DHT11 sensor, an MQ135 sensor, and an LCD display to monitor the air quality and send the data to ThingSpeak.

## Hardware Requirements

- WiFi enabled board (ESP8266 or NodeMCU)
- DHT11 sensor (for temperature and humidity)
- MQ135 sensor (for air quality index)
- LCD display (16x2 with I2C interface)
- Breadboard and jumper wires


## Software Requirements

- Arduino IDE
- DHT library
- LiquidCrystal_I2C library
- WiFi library
- ThingSpeak library


## Code Explanation

The code for this project is divided into four sections:

- **Include libraries**: This section includes the necessary libraries for the project, such as DHT, LiquidCrystal_I2C, WiFi, and ThingSpeak.
- **Define constants**: This section defines the constants for the project, such as the pin numbers, the WiFi credentials, the ThingSpeak channel ID and API key, and the DHT type.
- **Setup function**: This section initializes the LCD display, the WiFi connection, the ThingSpeak client, the DHT sensor, and the serial monitor. It also displays a welcome message on the LCD.
- **Loop function**: This section reads the temperature, humidity, and air quality values from the sensors and sends them to ThingSpeak. It also displays the air quality status on the LCD based on the MQ135 reading.

## How to Use

To use this project, follow these steps:

1. Connect the hardware components according to the circuit diagram.
2. Install the required libraries in your Arduino IDE.
3. Modify the code with your own WiFi credentials, ThingSpeak channel ID and API key.
4. Upload the code to your Arduino board.
5. Open the serial monitor to view the sensor readings.
6. Open your ThingSpeak channel to view the data online.

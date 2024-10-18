# Green-House-Monitoring-System 🥦

This project is an IoT-based greenhouse monitoring system implemented using ESP8266, Blynk, and various sensors. It monitors soil moisture, CO2 levels, temperature, humidity, and light levels in a greenhouse environment. The system controls a water pump and a relay for turning on/off a bulb based on the sensor readings.

<img src="/Images and Demonstration Video/test.jpg">

## Features

- Real-time monitoring of soil moisture, CO2 levels, temperature, humidity, and light levels.
- Automatic control of the water pump based on soil moisture levels.
- Automatic control of a bulb based on light levels.
- Remote monitoring and control via the Blynk mobile app.

## Components Used

- ESP8266 microcontroller
- DHT11 temperature and humidity sensor
- Soil moisture sensor
- MQ135 CO2 sensor
- Light-dependent resistor (LDR)
- OLED display for local data display
- Relay module for controlling the bulb
- Water pump

## Video Demonstration
<video src="https://github.com/AvishkaVishwa/Green-House-Monitoring-System/raw/main/testing%20final%20phase.mp4" controls>

## System Overview

The system collects data from various sensors and sends it to the Blynk mobile app for real-time monitoring. Based on the sensor values:
- The water pump is activated when the soil moisture level is below a predefined threshold.
- A bulb is turned on/off based on the light levels detected by the LDR.

The system also displays the readings on an OLED display for local monitoring within the greenhouse.

## Installation and Setup

1. Connect the components as per the schematic.
2. Upload the code to the ESP8266 using the Arduino IDE.
3. Configure the Blynk app with the project’s Blynk authentication token.
4. Ensure the ESP8266 is connected to a stable Wi-Fi network.
5. Monitor and control the system using the Blynk app.

## How It Works

- **Soil Moisture Monitoring**: The soil moisture sensor continuously measures the moisture content. If the value drops below a set threshold, the water pump is activated.
- **Temperature and Humidity Monitoring**: The DHT11 sensor measures the greenhouse environment’s temperature and humidity and displays it on the OLED screen and Blynk app.
- **CO2 Monitoring**: The MQ135 sensor measures CO2 levels to monitor air quality.
- **Light Level Monitoring**: The LDR measures light levels, and a relay controls a bulb to maintain optimal lighting conditions.

## Future Enhancements

- Addition of a fan system for temperature control.
- Integration of a pH sensor for soil quality monitoring.
- Expansion to support multiple greenhouses.


[testPhaseVideo]: https://github.com/AvishkaVishwa/Green-House-Monitoring-System/raw/main/testing%20final%20phase.mp4
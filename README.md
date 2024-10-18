# Green-House-Monitoring-System 🥦
```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Greenhouse Monitoring System</title>
</head>
<body>
    <h1>Greenhouse Monitoring System</h1>
    <p>This project is an IoT-based greenhouse monitoring system implemented using ESP8266, Blynk, and various sensors. It monitors soil moisture, CO2 levels, temperature, humidity, and light levels in a greenhouse environment. The system controls a water pump and a relay for turning on/off a bulb based on the sensor readings.</p>
    <img src="/Images and Demonstration Video/test.jpg" alt="Greenhouse Monitoring System">

    <h2>Features</h2>
    <ul>
        <li>Real-time monitoring of soil moisture, CO2 levels, temperature, humidity, and light levels.</li>
        <li>Automatic control of the water pump based on soil moisture levels.</li>
        <li>Automatic control of a bulb based on light levels.</li>
        <li>Remote monitoring and control via the Blynk mobile app.</li>
    </ul>

    <h2>Components Used</h2>
    <ul>
        <li>ESP8266 microcontroller</li>
        <li>DHT11 temperature and humidity sensor</li>
        <li>Soil moisture sensor</li>
        <li>MQ135 CO2 sensor</li>
        <li>Light-dependent resistor (LDR)</li>
        <li>OLED display for local data display</li>
        <li>Relay module for controlling the bulb</li>
        <li>Water pump</li>
    </ul>

    <h2>Video Demonstration</h2>
    <a href="https://github.com/AvishkaVishwa/Green-House-Monitoring-System/raw/main/testing%20final%20phase.mp4">Watch the video demonstration</a>

    <h2>System Overview</h2>
    <p>The system collects data from various sensors and sends it to the Blynk mobile app for real-time monitoring. Based on the sensor values:</p>
    <ul>
        <li>The water pump is activated when the soil moisture level is below a predefined threshold.</li>
        <li>A bulb is turned on/off based on the light levels detected by the LDR.</li>
    </ul>
    <p>The system also displays the readings on an OLED display for local monitoring within the greenhouse.</p>

    <h2>Installation and Setup</h2>
    <ol>
        <li>Connect the components as per the schematic.</li>
        <li>Upload the code to the ESP8266 using the Arduino IDE.</li>
        <li>Configure the Blynk app with the project’s Blynk authentication token.</li>
        <li>Ensure the ESP8266 is connected to a stable Wi-Fi network.</li>
        <li>Monitor and control the system using the Blynk app.</li>
    </ol>

    <h2>How It Works</h2>
    <ul>
        <li><strong>Soil Moisture Monitoring</strong>: The soil moisture sensor continuously measures the moisture content. If the value drops below a set threshold, the water pump is activated.</li>
        <li><strong>Temperature and Humidity Monitoring</strong>: The DHT11 sensor measures the greenhouse environment’s temperature and humidity and displays it on the OLED screen and Blynk app.</li>
        <li><strong>CO2 Monitoring</strong>: The MQ135 sensor measures CO2 levels to monitor air quality.</li>
        <li><strong>Light Level Monitoring</strong>: The LDR measures light levels, and a relay controls a bulb to maintain optimal lighting conditions.</li>
    </ul>

    <h2>Future Enhancements</h2>
    <ul>
        <li>Addition of a fan system for temperature control.</li>
        <li>Integration of a pH sensor for soil quality monitoring.</li>
        <li>Expansion to support multiple greenhouses.</li>
    </ul>
</body>
</html>
```
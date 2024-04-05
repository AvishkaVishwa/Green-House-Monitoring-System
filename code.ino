#define BLYNK_TEMPLATE_ID "TMPL6Jk-vbFYB"
#define BLYNK_TEMPLATE_NAME "Greenhouse"
#define BLYNK_AUTH_TOKEN "Z9TaUjl1Gl68KVz4qZIZrK7cpsneYVKB"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define SOIL_SENSOR_CHANNEL 0
#define MQ135_SENSOR_CHANNEL 1
#define LDR_SENSOR_CHANNEL 2

#define SOIL_MOISTURE_VPIN V3
#define CO2_VPIN V2
#define TEMP_VPIN V0
#define HUMIDITY_VPIN V1
#define RELAY_BULB_PIN 10
#define PUMP D3

#define ANALOG_PIN A0
#define DHTPIN D4
#define DHTTYPE DHT11

#define S0 D0
#define S1 D5
#define S2 D6
#define S3 D7

int soilMoisturePercent  = 40;

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Dialog LTE";
char pass[] = "Lakdilu0414";

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  delay(100);

  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(RELAY_BULB_PIN, OUTPUT);
  pinMode(PUMP, OUTPUT);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(800);
  display.clearDisplay();

  Blynk.begin(auth, ssid, pass);
  dht.begin();
}

void loop() {
  Blynk.run();
  readSensors();
  delay(500); // Adjust as needed
}

void readSensors() {
  setMultiplexerChannel(SOIL_SENSOR_CHANNEL);
  delay(10); 
 int soilMoistureValue = analogRead(ANALOG_PIN);
  int soilMoisturePercent = map(soilMoistureValue, 0, 1023, 100, 0);
  if (soilMoisturePercent > 40){
    digitalWrite(PUMP,HIGH);
  }
  else {
   digitalWrite(PUMP,LOW); 
  }

  Blynk.virtualWrite(SOIL_MOISTURE_VPIN, soilMoisturePercent);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 10);
  display.println("Soil: " + String(soilMoisturePercent) + "%");
  Serial.print("Raw Soil Moisture Value: ");
  Serial.println(soilMoisturePercent);

setMultiplexerChannel(MQ135_SENSOR_CHANNEL);
delay(10); 
int mq135SensorValue = analogRead(ANALOG_PIN);
float co2LevelPercentage = (mq135SensorValue / 1023.0) * 100.0;
Blynk.virtualWrite(CO2_VPIN, co2LevelPercentage);
display.setCursor(0, 20);
display.println("CO2 Level: " + String(co2LevelPercentage) + " %");

  setMultiplexerChannel(LDR_SENSOR_CHANNEL);
  delay(10); // Stabilization delay
  int ldrValue = analogRead(ANALOG_PIN);
  if (ldrValue < 500){
    digitalWrite(RELAY_BULB_PIN,HIGH);
  }
  else{
    digitalWrite(RELAY_BULB_PIN,LOW);
  }
float temperature = dht.readTemperature();
float humidity = dht.readHumidity();
if (!isnan(temperature) && !isnan(humidity)) {
  Blynk.virtualWrite(TEMP_VPIN, temperature);
  Blynk.virtualWrite(HUMIDITY_VPIN, humidity);
  display.setCursor(0, 30);
  display.print("T: ");
  display.print(temperature);
  display.println("'C");
  display.print("H: ");
  display.print(humidity);
  display.println("%");
} else {
  Serial.println("Failed to read from DHT sensor!");
}
  display.display();
}
void setMultiplexerChannel(int channel) {
  digitalWrite(S0, bitRead(channel, 0));
  digitalWrite(S1, bitRead(channel, 1));
  digitalWrite(S2, bitRead(channel, 2));
  digitalWrite(S3, bitRead(channel, 3));
}

#define BLYNK_TEMPLATE_ID "TMPL32gdgkLI9"
#define BLYNK_TEMPLATE_NAME "Servo Control"
#define BLYNK_AUTH_TOKEN "GFJ7Bb7wBQB2oqPv-3Dw4LnRO89P7jLV"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>
#include <Wire.h>
#include <U8g2lib.h>

// WiFi & Blynk
char ssid[] = "Infinix GT30 Pro 5g";
char pass[] = "Aravinth30";

// ---- Servo Setup ----
Servo servo1, servo2;
int servo1Pin = D4;   // PWM pins
int servo2Pin = D5;
int currentAngle1 = 90, targetAngle1 = 90;
int currentAngle2 = 90, targetAngle2 = 90;

// ---- Blynk Virtual Pins ----
BLYNK_WRITE(V0) { targetAngle1 = param.asInt(); }
BLYNK_WRITE(V1) { targetAngle2 = param.asInt(); }

// ---- OLED Setup ----
// Explicitly set SDA = D2, SCL = D1
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE, /* SCL=*/ D1, /* SDA=*/ D2);

// ---- Simulated Sensor Variables ----
float simulatedTemp = 25.0; // start temperature
float simulatedHum = 50.0;  // start humidity

// Timing for OLED updates
unsigned long previousMillis = 0;
const long interval = 500; // update every 0.5 seconds

void setup() {
  Serial.begin(115200);
  
  // ---- Servo init ----
  servo1.attach(servo1Pin);
  servo1.write(currentAngle1);
  
  servo2.attach(servo2Pin);
  servo2.write(currentAngle2);
  
  // ---- Blynk init ----
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  
  // ---- OLED init ----
  u8g2.begin();
}

void loop() {
  Blynk.run();

  // ---- Smooth Servo 1 ----
  if(currentAngle1 < targetAngle1) { currentAngle1++; servo1.write(currentAngle1); delay(15); }
  else if(currentAngle1 > targetAngle1) { currentAngle1--; servo1.write(currentAngle1); delay(15); }

  // ---- Smooth Servo 2 ----
  if(currentAngle2 < targetAngle2) { currentAngle2++; servo2.write(currentAngle2); delay(15); }
  else if(currentAngle2 > targetAngle2) { currentAngle2--; servo2.write(currentAngle2); delay(15); }

  // ---- Non-blocking OLED update ----
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // Simulate temperature & humidity changes
    simulatedTemp += 0.1; if(simulatedTemp > 30) simulatedTemp = 25.0;
    simulatedHum += 0.5; if(simulatedHum > 70) simulatedHum = 50.0;

    Serial.print("Simulated Temp: "); Serial.print(simulatedTemp); 
    Serial.print(" °C  Hum: "); Serial.println(simulatedHum);

    // Display on OLED
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_ncenB14_tr);
    u8g2.drawStr(0, 15, "Temp & Humidity");

    char tempStr[16]; sprintf(tempStr, "Temp: %.1fC", simulatedTemp);
    u8g2.drawStr(0, 40, tempStr);

    char humStr[16]; sprintf(humStr, "Hum : %.1f%%", simulatedHum);
    u8g2.drawStr(0, 60, humStr);

    u8g2.sendBuffer();
  }
}
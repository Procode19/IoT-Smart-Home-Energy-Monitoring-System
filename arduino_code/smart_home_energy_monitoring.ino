#include <WiFi.h>
#include <HTTPClient.h>

// =====================================================
// WIFI CREDENTIALS
// =====================================================
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// =====================================================
// THINGSPEAK DETAILS
// =====================================================
String apiKey = "LSOSREQUEM282JS9";
const char* server = "http://api.thingspeak.com/update";

// =====================================================
// PIN DEFINITIONS
// =====================================================
#define GREEN_LED 23
#define YELLOW_LED 22
#define RED_LED 21
#define BUZZER 19
#define SENSOR_PIN 35

// =====================================================
// VARIABLES
// =====================================================
float voltage = 230.0;
float current = 0.0;
float power = 0.0;
float energy = 0.0;
float cost = 0.0;

String statusMessage = "";

// Alert Value for ThingSpeak
int alertValue = 0;

// Cost per electricity unit
float ratePerUnit = 8.0;

// Timers
unsigned long previousMillis = 0;
unsigned long lastThingSpeakUpdate = 0;

void setup() {

  Serial.begin(115200);

  // Pin Modes
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  // LEDs OFF initially
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(BUZZER, LOW);

  // =====================================================
  // CONNECT TO WIFI
  // =====================================================
  Serial.print("Connecting to WiFi");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected Successfully!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  Serial.println("\n====================================");
  Serial.println(" SMART HOME ENERGY MONITORING ");
  Serial.println("====================================");
}

void loop() {

  // =====================================================
  // SENSOR READING
  // =====================================================
  int sensorValue = analogRead(SENSOR_PIN);

  // Convert potentiometer to current (0–10A)
  current = (sensorValue / 4095.0) * 10.0;

  // =====================================================
  // POWER CALCULATION
  // =====================================================

  power = voltage * current;

  // =====================================================
  // ENERGY CALCULATION
  // =====================================================

  unsigned long currentMillis = millis();

  float hoursPassed =
      (currentMillis - previousMillis) / 3600000.0;

  previousMillis = currentMillis;

  energy += (power * hoursPassed) / 1000.0;

  // =====================================================
  // COST CALCULATION
  // =====================================================

  cost = energy * ratePerUnit;

  // =====================================================
  // ALERT LOGIC
  // =====================================================

  // LOW USAGE
  if (power < 500) {

    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BUZZER, LOW);

    statusMessage = "Normal Usage";
    alertValue = 1;
  }

  // MEDIUM USAGE
  else if (power >= 500 && power <= 1500) {

    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BUZZER, LOW);

    statusMessage = "Moderate Usage";
    alertValue = 2;
  }

  // HIGH USAGE
  else {

    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, HIGH);

    // Buzzer Alert
    digitalWrite(BUZZER, HIGH);
    delay(200);
    digitalWrite(BUZZER, LOW);

    statusMessage = "HIGH ENERGY ALERT";
    alertValue = 3;
  }

  // =====================================================
  // SERIAL MONITOR
  // =====================================================

  Serial.println("\n========== ENERGY REPORT ==========");

  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");

  Serial.print("Current: ");
  Serial.print(current, 2);
  Serial.println(" A");

  Serial.print("Power: ");
  Serial.print(power, 2);
  Serial.println(" W");

  Serial.print("Energy Used: ");
  Serial.print(energy, 4);
  Serial.println(" kWh");

  Serial.print("Estimated Cost: ₹");
  Serial.println(cost, 2);

  Serial.print("Status: ");
  Serial.println(statusMessage);

  Serial.println("===================================");

  // =====================================================
  // SEND DATA TO THINGSPEAK
  // =====================================================

  if (millis() - lastThingSpeakUpdate >= 16000) {

    if (WiFi.status() == WL_CONNECTED) {

      HTTPClient http;

      String url =
        String(server) +
        "?api_key=" + apiKey +
        "&field1=" + String(voltage, 2) +
        "&field2=" + String(current, 2) +
        "&field3=" + String(power, 2) +
        "&field4=" + String(energy, 4) +
        "&field5=" + String(cost, 2) +
        "&field6=" + String(alertValue);

      Serial.println("\nSending Data to ThingSpeak...");
      Serial.println(url);

      http.begin(url);

      int httpResponseCode = http.GET();

      if (httpResponseCode > 0) {
        Serial.print("ThingSpeak Response: ");
        Serial.println(httpResponseCode);
        Serial.println("Data Uploaded Successfully!");
      } else {
        Serial.print("Error Code: ");
        Serial.println(httpResponseCode);
      }

      http.end();
    }

    lastThingSpeakUpdate = millis();
  }

  delay(1000);
}
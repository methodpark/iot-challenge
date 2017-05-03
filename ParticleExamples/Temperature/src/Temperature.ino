// Connect Vin to 3-5VDC
// Connect GND to ground
// Connect SCL to I2C clock pin (D1 on Photon/Electron)
// Connect SDA to I2C data pin  (D0 on Photon/Electron)
//
// Use Putty or GNU/screen to see the output of the serial line
// screen /dev/ttyACM0 9600
// or http://blog.jongallant.com/2015/08/particle-photon-setup-windows-putty/
//
// You can see the temperature posted in the particle.io Console under "Logs"
// and you can create a Webhook that posts this value to whatever service you want

#include "Adafruit_Si7021.h"   // Use for Build IDE
// #include "Adafruit_Si7021.h"               // Use for local build
#include "MQTT.h"

#define GREEN_LED D2
#define RED_LED D3

void callback(char* topic, byte* payload, unsigned int length);

Adafruit_Si7021 sensor = Adafruit_Si7021();
MQTT client("10.10.100.232", 1883, callback);

void callback(char* topic, byte* payload, unsigned int length) {
  return;
}

void setup() {
  Serial.begin(9600);
  Serial.println("Si7021 test");
  sensor.begin();
  client.connect("particle");
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
}

void loop() {
  float temp_f = sensor.readTemperature();
  String temp = String(temp_f, 2);
  Serial.print("Humidity: "); Serial.println(sensor.readHumidity(), 2);
  Serial.print("Temperature: "); Serial.println(temp);

  // For webhooks
  Particle.publish("temp", temp);

  if (temp_f >= 29) {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
  } else {
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
  }

  // mqtt
  if (client.isConnected()) {
      client.publish("iotChallenge/temp",temp);
  }

  delay(5000);
}

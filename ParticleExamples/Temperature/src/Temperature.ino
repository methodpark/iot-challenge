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

Adafruit_Si7021 sensor = Adafruit_Si7021();
double t;

void setup() {
  Serial.begin(115200);
  Serial.println("Si7021 test");
  sensor.begin();
}

void loop() {
  float temp = sensor.readTemperature();
  Serial.print("Humidity: "); Serial.println(sensor.readHumidity(), 2);
  Serial.print("Temperature: "); Serial.println(temp, 2);
  Particle.publish("temp", String(temp));
  delay(10000);
}

#define ANALOG_IN A0
#define led1 D0

void setup() {
    Serial.begin(9600);
    pinMode(led1, OUTPUT);
}

void loop() {
    Serial.println(analogRead(ANALOG_IN));
    digitalWrite(led1, HIGH);
    delay(1000);
    digitalWrite(led1, LOW);
}

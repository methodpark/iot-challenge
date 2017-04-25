#define PIR_MOTION_SENSOR D0

void setup()
{
	pinMode(PIR_MOTION_SENSOR, INPUT);
	Serial.begin(9600);
}

void loop()
{
	if(motion())
		Serial.println("Motion detected!");
	else
		Serial.println("");
}

boolean motion()
{
	int sensorValue = digitalRead(PIR_MOTION_SENSOR);

	if(sensorValue == HIGH) {
		return true;
	} else {
		return false;
	}
}

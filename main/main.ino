#define buttonInputPin 2
#define debugPin 13

void setup() {
	pinMode(debugPin,OUTPUT);
	pinMode(buttonInputPin,INPUT);
	Serial.begin(9600);
}

void loop() {
	Serial.print(digitalRead(buttonInputPin));
	delay(100);
}

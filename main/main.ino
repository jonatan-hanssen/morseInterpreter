void setup() {
	pinMode(13,OUTPUT); // debug pin
	pinMode(2,INPUT); // the pin that reads the button
	Serial.begin(9600);
}

void loop() {
	Serial.print(digitalRead(2));
	delay(100);
}

#include <Arduino.h>
#line 1 "/home/jona/morseInterpreter/main/main.ino"
#line 1 "/home/jona/morseInterpreter/main/main.ino"
void setup();
#line 5 "/home/jona/morseInterpreter/main/main.ino"
void loop();
#line 1 "/home/jona/morseInterpreter/main/main.ino"
void setup() {
	pinMode(13,OUTPUT);
}

void loop() {
	digitalWrite(13,HIGH);
	delay(200);
	digitalWrite(13,LOW);
	delay(200);
}


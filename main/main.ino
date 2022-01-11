#define buttonInputPin 2
#define debugPin 13
#define pollRate 10 // 10 ms




// number of milliseconds a dash (-) should be. Anything
// shorter will be interpreted as a dot (.)
#define dashLengthInMs 300

// number of milliseconds a pause should be. This
// seperates letters
#define pauseLengthInMs 400

int dashLength;
int consecOne; // number of consecutive ones

int pauseLength;
int consecZero; // number of consecutive zeros
// probably no morse letter is longer than 10 symbols
char morseWord[10];

void setup() {
	// pin setup
	pinMode(debugPin,OUTPUT);
	pinMode(buttonInputPin,INPUT);
	Serial.begin(9600);

	// code setup
	dashLength = dashLengthInMs/pollRate;
	pauseLength = pauseLengthInMs/pollRate;
}

void loop() {

	Serial.print(digitalRead(buttonInputPin));
	delay(pollRate);
}

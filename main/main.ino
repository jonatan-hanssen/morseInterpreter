#define buttonInputPin 2
#define debugPin 13
#define pollRate 10 // 10 ms




// number of milliseconds a dash (-) should be. Anything
// shorter will be interpreted as a dot (.)
#define dashLengthInMs 300

// number of milliseconds a pause should be. This
// seperates letters
#define pauseLengthInMs 400

int dashLength; // number of consecutive ones needed for a dash
int consecOne = 0; // number of consecutive ones currently

int pauseLength; // number of consecutive ones needed for a pause
int consecZero = 0; // number of consecutive zeros
// probably no morse letter is longer than 10 symbols.
// We set this to only 2's so that we know when a letter has ended.
// A finished letter may look like this: [0,1,0,2,2,2,2,2,2,2]
// 0 is a dot and 1 is a dash
int morseWord[10] {2,2,2,2,2,2,2,2,2,2};
int morseWordCounter = 0;

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
	if (digitalRead(buttonInputPin) == 1) {
		// if this is true that must mean that we just changed from
		// not holding to holding the button
		if (consecZero > 0) {

		}
		consecOne += 1;
	}
	else {
		// if this is true that must mean that we just changed from
		// holding to not holding the button
		if (consecOne > 0) {

		}
		consecZero += 1;
	}
	delay(pollRate);
}

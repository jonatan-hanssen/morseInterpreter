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
char morseWord[10] {2,2,2,2,2,2,2,2,2,2};
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
		consecOne++;
	}
	else {
		// if this is true that must mean that we just changed from
		// holding to not holding the button
		if (consecOne > 0) {
			// we must now check if it was a dot or a dash, but first
			// we must check if we have exceeded the number of dots
			// and dashes for any valid morse letter
			if (morseWordCounter < 10) {
				Serial.print(morseWord);
				// we reset the morseWord array after printing it
				for (int i = 1; i < 10; i++) {
					morseWord[i] = 2;
				}
			}
			else {
			}
		}
		consecZero += 1;
	}
	delay(pollRate);
}

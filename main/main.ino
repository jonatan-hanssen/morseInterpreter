// This allows us to control a Hitachi HD44780 compatible LCD display
#include <LiquidCrystal.h>

#define buttonInputPin 7
#define debugPin 13
#define pollRate 10 // 10 ms

// The schematic for the LCD can be found here 
// https://docs.arduino.cc/learn/electronics/lcd-displays
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// number of milliseconds a dash (-) should be. Anything
// shorter will be interpreted as a dot (.)
#define dashLengthInMs 300

// number of milliseconds a pause should be. This
// seperates letters
#define pauseLengthInMs 400

int dashLength; // number of consecutive ones needed for a dash
int consecOne = 0; // number of consecutive ones currently

int pauseLength; // number of consecutive ones needed for a pause
int consecZero = 0; // number of consecutive zeroes
String morseWord = "";

// this is to handle scrolling of text
int printedSymbols = 0;

// I thought about using a hashtable, which makes sense and in theory might
// be faster but probably has way to much overhead for such a small list
String morseArray[36][2] = {
	{".-","A"},
	{"-...","B"},
	{"-.-.","C"},
	{"-..","D"},
	{".","E"},
	{"..-.","F"},
	{"--.","G"},
	{"....","H"},
	{"..","I"},
	{".---","J"},
	{"-.-","K"},
	{".-..","L"},
	{"--","M"},
	{"-.","N"},
	{"---","O"},
	{".--.","P"},
	{"--.-","Q"},
	{".-.","R"},
	{"...","S"},
	{"-","T"},
	{"..-","U"},
	{"...-","V"},
	{".--","W"},
	{"-..-","X"},
	{"--..","Z"},
	{"-----","0"},
	{".----","1"},
	{"..---","2"},
	{"...--","3"},
	{"....-","4"},
	{".....","5"},
	{"-....","6"},
	{"--...","7"},
	{"---..","8"},
	{"----.","9"},
};

void setup() {
	// circuitry setup
	pinMode(debugPin,OUTPUT);
	pinMode(buttonInputPin,INPUT);
	lcd.begin(16,2);
	// code setup
	dashLength = dashLengthInMs/pollRate;
	pauseLength = pauseLengthInMs/pollRate;
}

void loop() {
	if (printedSymbols > 11) {
		// why does LiquidCrystal not include a
		// variable for this function...
		lcd.scrollDisplayLeft();
		lcd.scrollDisplayLeft();
		lcd.scrollDisplayLeft();
		lcd.scrollDisplayLeft();
		printedSymbols = 7;
	}
	if (digitalRead(buttonInputPin) == 1) {
		consecZero = 0;
		consecOne++;
	}
	else {
		// if this is true that must mean that we just changed from
		// holding to not holding the button
		if (consecOne > 0) {
			if (consecOne > dashLength) {
				morseWord += "-";
			}
			else {
				morseWord += ".";
			}
			consecOne = 0;
		}
		consecZero += 1;
		if (consecZero > pauseLength && morseWord.length() > 0) {
			lcd.print(outputSymbol(morseWord));
			morseWord = "";
			printedSymbols++;
		}
	}
	delay(pollRate);
}

String outputSymbol(String morseWord) {
	for (int i = 0; i < 36; i++) {
		if (morseWord == morseArray[i][0]) {
			return morseArray[i][1];
		}
	}
	return "?";
}

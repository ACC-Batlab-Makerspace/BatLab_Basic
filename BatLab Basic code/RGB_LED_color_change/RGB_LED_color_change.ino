/* BatLab Basic Project Kit
/*
  Rotates through each differently colored LED 
  of the LED RGB. Each color is turned on for 2 seconds.
This sketch illustrates the use of an array, ledPin, to hold the pin numbers for each color of the LED.  This same code could be used for any number of separate LEDs – just change the numLEDs variable, the index number in the ledPin declaration, and add
pin number variables for each extra LED.
  
 */
 
// Defining the LED driver pins and some other
// variables.

const int numLEDs = 3;

int blueLEDPin  = 6;
int greenLEDPin = 5;
int redLEDPin   = 3;

int ledPin[3];
int ledPinIndex = 0;


void setup() 
{                
  // initialize the digital pins as outputs.
  ledPin[0] = blueLEDPin;
  ledPin[1] = greenLEDPin;
  ledPin[2] = redLEDPin;
  for (int i=0; i < numLEDs; i++)
     pinMode(i, OUTPUT); 
}

void loop()
{
  digitalWrite(ledPin[ledPinIndex%numLEDs], HIGH);
  delay(2000);               // wait for 2 seconds
  digitalWrite(ledPin[ledPinIndex%numLEDs], LOW);
  ledPinIndex++;
}


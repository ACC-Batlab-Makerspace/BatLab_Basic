/*
Basic musical instrument
*/

const int buttonPin = 7;   // pushbutton pin
const int ledPin =  13;    // LED pin
const int buzzerPin = 3;   // piezo buzzer pin
const int sensorPin = A0;  // potentiometer pin
int duration = 500; // this value determines how long in milliseconds the sound plays
int notes [8] = {262,294,330,349,392,440,494,523}; // frequency values of notes

void setup()
{
  // Set the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

  // Set the LED pin as an output:
  pinMode(ledPin, OUTPUT);      
  pinMode(buzzerPin, OUTPUT);
  
}

void loop()
{
  int sensorValue = 0;  // variable that stores the state of the potentiometer
  int outputValue = 0;
  int buttonState = 0;  // variable that stores the state of the button
  buttonState = digitalRead(buttonPin); // read in the state of the button
  sensorValue = analogRead(sensorPin); // read the value from the potentiometer:

  outputValue = map(sensorValue, 0, 1023, 0, 7); // translate input from potentiometer
                                                 // to a value from 0 to 7

  if (buttonState == LOW)  // if the button is being pushed
  {
    digitalWrite(ledPin, HIGH);  // turn the LED on
    tone(buzzerPin, notes[outputValue], duration); // play the sound
    delay(duration); // wait until sound is done playing
  }
  else
  {
    digitalWrite(ledPin, LOW);  // turn the LED off
  }
}

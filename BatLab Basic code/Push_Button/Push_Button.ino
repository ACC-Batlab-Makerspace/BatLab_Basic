/*
Push Button Example

Push buttons are a basic method of getting input from the user of a circuit. The value returned to the 
digital input pin on the Arduino is either a LOW or HIGH voltage value (ON or OFF).

When the button is pressed it completes the circuit between the two button pins used in this circuit. One
pin is connected to ground (GND), and the other is connected to a digital input on the Arduino (#2 in this
case), and to a 10k OHM "pullup" resistor connected to 5v. 

When the button is pressed (closed) the digital input receives a LOW voltage state, because the circuit
connects to ground through the button, causing a voltage drop. When the button is not pressed (open) the
"pullup" resistor allows a tiny voltage to trickle from the 5v connection, thus the digital input reads HIGH.

Note that we are using the Arduino as an intermediary between the button and the LED. All interaction between
the two is determined by our program.
*/

// Since we use the Arduino digital pin numbers several times in our program we will
// store those values as variables. If we wish to change the pin we are using, we will 
// only need to change the value in one place. If we do not use variables we would have
// to change the value in multiple locations, potentially causing havok in our program
// if we miss one.
// We use a 'const' because the value will not change while the program is running.

const int buttonPin = 2;  // pushbutton 1 pin
const int ledPin =  13;    // LED pin


void setup()
{
  // Set the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

  // Set the LED pin as an output:
  pinMode(ledPin, OUTPUT);      
}


void loop()
{
  int buttonState;  // variable that stores the state of the button

  buttonState = digitalRead(buttonPin);
  
  if (buttonState == LOW)  // if the button is being pushed
  {
    digitalWrite(ledPin, HIGH);  // turn the LED on
  }
  else
  {
    digitalWrite(ledPin, LOW);  // turn the LED off
  }
}

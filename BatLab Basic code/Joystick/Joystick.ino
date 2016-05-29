/* BatLab Basic Project Kit
Joystick example

The joystick outputs two analog voltages (VRx and VRy), and one digital signal SW for the pushbutton.
Connect VRx to Arduino analog 0 and VRy to Arduino analog 1

Connect one end of a 10K resistor to Arduino 5V and the other end to SW on the joystick and BUTTON_PIN on the Arduino
This "pull up" resistor ensures that a digitalRead of the BUTTON_PIN results in a HIGH when the button is not pressed (otherwise the value will "float" and be unpredictable).

*/

// Connections to joystick (change if you use different pins):

const int VERT_PIN = A0; // analog
const int HORIZ_PIN = A1; // analog
const int BUTTON_PIN = 2; // digital



// This sketch outputs serial data at 9600 baud (open Serial Monitor to view).

void setup()
{
  pinMode(BUTTON_PIN,INPUT);   // make the BUTTON_PIN line an input; no need for pinMode on the analog inputs

  Serial.begin(9600);    // set up serial port for output
}

void loop() 
{
  int vertical, horizontal, select;
  
  // read all values from the joystick
  
  vertical = analogRead(VERT_PIN); // will be 0-1023
  horizontal = analogRead(HORIZ_PIN); // will be 0-1023
  select = digitalRead(BUTTON_PIN); // will be HIGH (1) if not pressed, and LOW (0) if pressed
  
  // print out the values
  
  Serial.print("vertical: ");
  Serial.print(vertical,DEC);
  Serial.print(" horizontal: ");
  Serial.print(horizontal,DEC);
  Serial.print(" select: ");
  if(select == HIGH)
    Serial.println("not pressed");
  else
    Serial.println("PRESSED!");
}


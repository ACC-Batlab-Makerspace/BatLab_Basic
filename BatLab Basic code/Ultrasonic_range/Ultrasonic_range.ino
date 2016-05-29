 /* ACC BatLab Basic Project Kit 
  *  
HC-SR04 Ultrasonic Range Sensor example

Download the NewPing library here:

https://bitbucket.org/teckel12/arduino-new-ping/downloads

and install it using these instructions: 

https://www.arduino.cc/en/Guide/Libraries#toc4

For more information on the NewPing library, visit:

http://playground.arduino.cc/Code/NewPing

Hardware connections:

Connect ECHO pin to Arduino digital pin 11.
Connect TRIG pin to Arduino digital pin 12.
Connect VCC to Arduino 5V.
Connect GND to Arduino GND.

Open the serial monitor to see the distance to the nearest object.

*/

#include <NewPing.h>          //uses the NewPing library to do the work

const int TRIGGER_PIN = 12;
const int ECHO_PIN = 11;
const int MAX_DISTANCE = 200;   // maximum distance in cm to read


// Create an object called “sonar” of type “NewPing”
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);  

void setup() 
{

// Opens communications with the serial monitor; be sure to
// set the speed to 115200 in the monitor window, too (at lower right)
// If the speeds don’t match, you’ll just get garbage on the screen

  Serial.begin(115200);
 }

void loop() 

{
  delay(50);
  int uS = sonar.ping();  // returns value in microseconds
  Serial.print("Ping: ");
  Serial.print(uS / US_ROUNDTRIP_CM); //prints distance in cm
  Serial.println("cm");
}

 



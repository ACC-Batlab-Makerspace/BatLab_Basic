/*
Photo Resistor
*/

const int sensorPin = 0;
const int ledPin = 9;

int lightLevel;
  
void setup()
{
  // We'll set up the LED pin to be an output.
  // (We don't need to do anything special to use the analog input.)
  
  pinMode(ledPin, OUTPUT);
}


void loop()
{
  lightLevel = analogRead(sensorPin); // Reads in a value from 0 to 1023 from the analog input
  // Although the analogRead() function reads a value between 0 and 1023, the photoresistor will
  // hover between reading of 200 and 700. We use the map() function to transform this range
  // to a number between 0 and 255, which is a range that works well for this application.
  lightLevel = map(lightLevel, 200, 700, 0, 255);
  // It is possible for map to return a value outside of our desired range. The constrain() function
  // will make sure that the number is within the range of 0 to 255.
  lightLevel = constrain(lightLevel, 0, 255);

  // Write the value to the LED!
  analogWrite(ledPin, lightLevel);
}

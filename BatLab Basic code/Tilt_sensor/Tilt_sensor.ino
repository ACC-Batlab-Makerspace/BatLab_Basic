/* BatLab Basic Project Kit
 Tilt Sensor/switch example
Wiring note: the 10KΩ resistor is used here to "pull up" the signal to 5V when the switch is open(sensor is tilted), ensuring that the Arduino reads a HIGH in that case;  when the sensor is upright, the mercury closes the circuit and the signal is connected to ground, or 0V, so the Arduino then reads a LOW. Without the pull up resistor, the signal will "float" when the switch is open and you will get unpredictable results from reading the pin.

*/
  
const int sensorPin = 2; 
const int ledPin = 11; 

int ledState = HIGH; 
int reading; 
int previous = LOW;

long time = 0;
long debounce = 50;  //time in milliseconds to wait before changing the LED

void setup()
{
pinMode(sensorPin, INPUT);
digitalWrite(sensorPin, HIGH);
pinMode(ledPin, OUTPUT);
}

void loop()
{
  int switchState;
  reading = digitalRead(sensorPin);  //reading will be HIGH when switch is open

  // Debouncing in case the signal is noisy
  
  if (reading != previous) 
  {
    time = millis();  //the millis() function is like a time stamp
  } 

  // If the signal has changed in less than the debounce time, ignore it
  if ((millis() - time) > debounce) 
  {
    switchState = reading;
    
    if (switchState == HIGH)  //the sensor is tilted
      ledState = LOW;         //so turn the LED off
    else                      //the sensor is upright
      ledState = HIGH;        //so turn the LED on
  }
  digitalWrite(ledPin, ledState);  //send HIGH or LOW to the LED
  previous = reading;
}


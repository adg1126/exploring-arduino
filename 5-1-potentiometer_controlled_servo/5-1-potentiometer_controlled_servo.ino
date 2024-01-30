// C++ code
// Servo controlled potentiometer

#include <Servo.h>

const int SERVO = 9; 
const int POT = 0;

Servo servo1;
int potVal = 0;

void setup()
{
  servo1.attach(SERVO);
}

void loop()
{
  potVal = analogRead(POT);	// Read pot
  potVal = map(potVal, 0, 1023, 0, 179);	// Scale val to servo range
  servo1.write(potVal);		// Write val to servo
  delay(15);
  
}
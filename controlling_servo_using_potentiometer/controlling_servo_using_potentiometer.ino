#include <Servo.h>
Servo servo1;

int servoPin = 9;
int potPin = A0;

void setup() {
  // put your setup code here, to run once:
  servo1.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  int potVal = analogRead(potPin);
  int angle = map(potVal, 0, 1023, 0, 180);
  servo1.write(angle);
}

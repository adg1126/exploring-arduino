#include <Servo.h>
Servo servo1;

int servoPin = 9;
int buttonPin = 2;

boolean prevButton = LOW;     // Contains prev button state
boolean currentButton = LOW;  // Contains current button state
boolean isRotated = false; 

void setup() {
  // put your setup code here, to run once:
  servo1.attach(servoPin);
  pinMode(buttonPin, INPUT);
}

boolean debounce(boolean last) {
  boolean current = digitalRead(buttonPin);  // Read button state

  if (last != current) {
    delay(5);                       // Delay by 5ms
    current = digitalRead(buttonPin);  // Read button state again
  }

  return current;  // return current value
}

void loop() {
  // put your main code here, to run repeatedly:
  // int potVal = analogRead(potPin);
  // int angle = map(potVal, 0, 1023, 0, 180);
  // servo1.write(angle);

  currentButton = debounce(prevButton);  // Read debounce state
  if (prevButton == LOW && currentButton == HIGH) {
    isRotated = !isRotated;
  }

  prevButton = currentButton;

  if (isRotated) {
    servo1.write(180);
  } else {
    servo1.write(-180);
  }
}

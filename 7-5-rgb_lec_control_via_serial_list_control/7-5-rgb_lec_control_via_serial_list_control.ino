const int RED = 11;
const int GREEN = 10;
const int BLUE = 9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(10);

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    // Receive 3 ints over serial
    int val1 = Serial.parseInt();
    int val2 = Serial.parseInt();
    int val3 = Serial.parseInt();

    // Throws out anything that remains in the buffer after ints are read
    while (Serial.available()) {
      Serial.read();
    }

    // Constrain the received vals to be only from 0-100%
    int val1c = constrain(val1, 0, 100);
    int val2c = constrain(val2, 0, 100);
    int val3c = constrain(val3, 0, 100);

    // Map vals from % to analog vals
    int rval = map(val1c, 0, 100, 250, 0);
    int gval = map(val2c, 0, 100, 250, 0);
    int bval = map(val3c, 0, 100, 250, 0);

    // Set LED brightness
    analogWrite(RED, rval);
    analogWrite(GREEN, gval);
    analogWrite(BLUE, bval);

    // Report vals that were used to set the LED
    Serial.println("Red:  " + String(val1c) + "%");
    Serial.println("Green:  " + String(val1c) + "%");
    Serial.println("Blue:  " + String(val1c) + "%");
  }
}

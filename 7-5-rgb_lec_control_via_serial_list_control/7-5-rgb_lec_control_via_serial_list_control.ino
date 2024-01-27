//Sending Multiple Variables at Once
//Send Data in this format: <0-100>,<0-100>,<0,100)>\n
//Where the three numbers represent percentage brightness of R, G, B.

//Define LED Pins
const int RED = 11;
const int YELLOW = 10;
const int GREEN = 9;

void setup() {
  Serial.begin(9600);     //Serial Port at 9600 baud
  Serial.setTimeout(10);  //Serial timeout to wait for for int

  //Set pins as outputs
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);

  //Turn off the LED
  //It is common-anode, so setting the cathode pins to HIGH turns the LED off
  // digitalWrite(RED, HIGH);
  // digitalWrite(YELLOW, HIGH);
  // digitalWrite(GREEN, HIGH);
}

void loop() {
  //Read data when it's available in the buffer
  if (Serial.available() > 0) {
    //Expect to receive 3 integers over serial
    //parseInt will "block" until a valid integer is received
    //parseInt knows the full integer was received once a non-digit (comma or newline) is seen
    //parseInt only removes invalid characters before the found int, not after
    int val1 = Serial.parseInt();
    int val2 = Serial.parseInt();
    int val3 = Serial.parseInt();

    //Throw out anything that remains in the buffer after integers are read
    while (Serial.available()) {
      Serial.read();
    }

    //Constrain the received values to be only from 0 to 100%
    int val1c = constrain(val1, 0, 100);
    int val2c = constrain(val2, 0, 100);
    int val3c = constrain(val3, 0, 100);

    //Map the values from percentages to analog values
    int rval = map(val1c, 0, 100, 0, 255);  //first valid integer
    int yval = map(val2c, 0, 100, 0, 255);  //second valid integer
    int gval = map(val3c, 0, 100, 0, 255);  //third valid integer

    // set LED brightness
    analogWrite(RED, rval);
    analogWrite(YELLOW, yval);
    analogWrite(GREEN, gval);

    // Report Values that were used to set the LED
    Serial.println("Red:   " + String(val1c) + "%");
    Serial.println("Yellow: " + String(val2c) + "%");
    Serial.println("Green:  " + String(val3c) + "%\n");
  }
}
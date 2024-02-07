// C++ code
// Make light sequence animation

const int SER = 8; // Serial Output to Shift Register
const int LATCH = 9; // Shift Register Latch Pin
const int CLK = 10; // Shift Register Clock Pin
const int ULTRASONIC_DIST = 7; // Ultrasonic distance sensor pin


// Possible LED settings
int ledVals[9] = {0,1,3,7,15,31,63,127,255};	

// Min and max distance in cm
int minVal = 0;
int maxVal = 340;

void setup()
{
  // Set pins as outputs
  pinMode(SER, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(ULTRASONIC_DIST, INPUT);
}

void loop()
{
  /* for (int i =0; i < 14; i++) {
    digitalWrite(LATCH, LOW);	// Latch low -  start sending
    shiftOut(SER, CLK, MSBFIRST, seq[i]);	// Shift most signinifant bit first
    digitalWrite(LATCH, HIGH);	// Latch high - stop sending
    delay(200);	// Animation speed
  }
  
  int distance = getDistance();
  Serial.println(distance); 
  */ 
  int distance = getDistance();
  distance = map(distance, minVal, maxVal, 0, 8);
  distance = constrain(distance, 0, 8);
  
  digitalWrite(LATCH, LOW);	// Latch low - start sending
  shiftOut(SER, CLK, MSBFIRST, ledVals[distance]);	// Send data, MSB first
  digitalWrite(LATCH, HIGH);	// Latch high -  stop sending 
  delay(10); // Animation speed
}

long getDistance() {
  // Vars for distance sensor
  long duration, cm;
  
  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(ULTRASONIC_DIST, OUTPUT);
  digitalWrite(ULTRASONIC_DIST, LOW);
  delayMicroseconds(2);
  digitalWrite(ULTRASONIC_DIST, HIGH);
  delayMicroseconds(5);
  digitalWrite(ULTRASONIC_DIST, LOW);
  // The same pin is used to read the signal from the PING))): a HIGH pulse
  // whose duration is the time (in microseconds) from the sending of the ping
  // to the reception of its echo off of an object.
  pinMode(ULTRASONIC_DIST, INPUT);
  duration = pulseIn(ULTRASONIC_DIST, HIGH);

  // convert the time into a distance
  cm = microsecondsToCentimeters(duration);
  
  return cm;
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}
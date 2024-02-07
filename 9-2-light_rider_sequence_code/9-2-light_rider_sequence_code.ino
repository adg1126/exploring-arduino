// C++ code
// Make light sequence animation

const int SER = 8; // Serial Output to Shift Register
const int LATCH = 9; // Shift Register Latch Pin
const int CLK = 10; // SHift Register Clock Pin

// Sequence of LEDs
int seq[14] = {1,2,4,8,16,32,64,128,64,32,16,8,4,2};

void setup()
{
  // Set pins as outputs
  pinMode(SER, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLK, OUTPUT);
}

void loop()
{
  for (int i =0; i < 14; i++) {
    digitalWrite(LATCH, LOW);	// Latch low -  start sending
    shiftOut(SER, CLK, MSBFIRST, seq[i]);	// Shift most signinifant bit first
    digitalWrite(LATCH, HIGH);	// Latch high - stop sending
    delay(200);	// Animation speed
  }
}
// C++ code
// ALternating LED pattern on a shift register

const int SER = 8;	//Serial Output Shift Register
const int LATCH = 9;	// Shift Register Latch Pin
const int CLK = 10;	// SHift Register Clock Pin

void setup()
{
  // Set pins as outputs
  pinMode(SER, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLK, OUTPUT);
  
  digitalWrite(LATCH, LOW);	// Latch low
  shiftOut(SER, CLK, MSBFIRST, B10101010);	// Shift most significant bit first
  shiftOut(SER, CLK, MSBFIRST, B10101010);
  digitalWrite(LATCH, HIGH);	// Latch high - show patter
}

void loop()
{
  
}
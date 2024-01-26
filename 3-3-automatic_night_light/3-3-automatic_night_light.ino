const int YELLOW_LED = 9;
int PHOTO_RESISTOR = 0;  // Input pin A0
int val = 0;

const int LOWER_BOUND = 80;
const int UPPER_BOUND = 360;

void setup() {
  // put your setup code here, to run once:
  pinMode(YELLOW_LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(PHOTO_RESISTOR);
  
  if (val < LOWER_BOUND) {
    digitalWrite(YELLOW_LED, HIGH);
  } else if (val > UPPER_BOUND) {
    digitalWrite(YELLOW_LED, LOW);
  }
}

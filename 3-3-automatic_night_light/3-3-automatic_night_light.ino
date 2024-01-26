const int YELLOW_LED = 9;
int PHOTO_RESISTOR = 0;  // Input pin A0
int val = 0;

const int MIN_LIGHT = 80;
const int MAX_LIGHT = 380;

void setup() {
  // put your setup code here, to run once:
  pinMode(YELLOW_LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(PHOTO_RESISTOR);
  val = map(val, MIN_LIGHT, MAX_LIGHT, 255, 0);
  val = constrain(val, 0, 255);
  digitalWrite(YELLOW_LED, val);
}

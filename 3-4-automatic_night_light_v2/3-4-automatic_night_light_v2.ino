const int RED_LED = 9;
const int YELLOW_LED = 10;
const int GREEN_LED = 11;
const int BUTTON = 2;    // pin2
int PHOTO_RESISTOR = 0;  // Input pin A0
int val = 0;

const int MIN_LIGHT = 80;
const int MAX_LIGHT = 380;

boolean lastButton = LOW;
boolean currentButton = LOW;
int ledMode = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  Serial.begin(9600);
}

boolean debounce(boolean last) {
  boolean current = digitalRead(BUTTON);

  if (last != current) {
    delay(5);
    current = digitalRead(BUTTON);
  }

  return current;
}

void setColorBrightness(int mode) {
  val = analogRead(PHOTO_RESISTOR);
  val = map(val, MIN_LIGHT, MAX_LIGHT, 255, 0);
  val = constrain(val, 0, 255);
  
  if (mode == 1) {
    digitalWrite(RED_LED, val);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
  } else if (mode == 2) {
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, val);
    digitalWrite(GREEN_LED, LOW);
  } else if (mode == 3) {
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, val);
  } else {
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  currentButton = debounce(lastButton);              // Read debounced state
  if (lastButton == LOW && currentButton == HIGH) {  // If it was pressed...
    ledMode++;                                       // Increment the LED value
  }
  lastButton = currentButton;  
  
  // Reset button value
  // If you've cycled through the different options,
  // reset the counter to 0
  if (ledMode == 4) ledMode = 0;
  setColorBrightness(ledMode);
}

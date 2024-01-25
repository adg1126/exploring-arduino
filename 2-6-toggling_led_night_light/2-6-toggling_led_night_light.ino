// ALL DIGITAL INPUTS MUST HAVE A PULL DOWN RESISTOR CONNECTED TO GROUND
const int REDLED = 9;      // RED LED connected to pin 9
const int YELLOWLED = 10;  // YELLOW LED connected to pin 10
const int GREENLED = 11;   // GREEN LED connected to pin 11
const int BUTTON = 2;      // Button connected to pin 2

boolean prevButton = LOW;     // prev button state
boolean currentButton = LOW;  // current button state
int ledMode = 0;              // cycle between colors

void setup() {
  // put your setup code here, to run once:
  pinMode(REDLED, OUTPUT);
  pinMode(YELLOWLED, OUTPUT);
  pinMode(GREENLED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

// Debouncing function
// - to account for button spring bouncing instead of settling when pressed
// Takes prevButton state as
// Returns current debounced button state
boolean debounce(boolean last) {
  boolean current = digitalRead(BUTTON);  // Read button state

  if (last != current) {
    delay(5);                       // Delay by 5ms
    current = digitalRead(BUTTON);  // Read button state again
  }

  return current;  // return current value
}

// LED Mode Selection
void setMode(int mode) {
  if (mode == 1) {  // Red
    digitalWrite(REDLED, HIGH);
    digitalWrite(YELLOWLED, LOW);
    digitalWrite(GREENLED, LOW);
  } else if (mode == 2) {  // Yellow
    digitalWrite(REDLED, LOW);
    digitalWrite(YELLOWLED, HIGH);
    digitalWrite(GREENLED, LOW);
  } else if (mode == 3) {  // Green
    digitalWrite(REDLED, LOW);
    digitalWrite(YELLOWLED, LOW);
    digitalWrite(GREENLED, HIGH);
  } else {
    digitalWrite(REDLED, LOW);
    digitalWrite(YELLOWLED, LOW);
    digitalWrite(GREENLED, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  currentButton = debounce(prevButton);  // Read debounce state
  if (prevButton == LOW && currentButton == HIGH) {
    ledMode++;
  }

  prevButton = currentButton;
  
  if (ledMode == 4) {
    ledMode = 0;
  }

  setMode(ledMode);
}

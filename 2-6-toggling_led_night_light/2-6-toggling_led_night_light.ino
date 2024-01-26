// ALL DIGITAL INPUTS MUST HAVE A PULL DOWN RESISTOR CONNECTED TO GROUND
const int REDLED = 9;       // RED LED connected to pin 9
const int YELLOWLED = 10;   // YELLOW LED connected to pin 10
const int GREENLED = 11;    // GREEN LED connected to pin 11
const int COLORBUTTON = 3;  // Color Button connected to pin 3
const int BLINKBUTTON = 2;  // Blink Button connected to pin 2

boolean prevColorButton = LOW;     // prev button state
boolean currentColorButton = LOW;  // current button state
boolean prevBlinkButton = LOW;
boolean currentBlinkButton = LOW;
int ledColorMode = 0;  // cycle between colors

int activeLED = 0;
boolean isBlinking = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(REDLED, OUTPUT);
  pinMode(YELLOWLED, OUTPUT);
  pinMode(GREENLED, OUTPUT);
  pinMode(COLORBUTTON, INPUT);
  pinMode(BLINKBUTTON, INPUT);
}

// Debouncing function
// - to account for button spring bouncing instead of settling when pressed
// Takes prevButton state as
// Returns current debounced button state
boolean debounce(boolean last, int button) {
  boolean current = digitalRead(button);  // Read button state

  if (last != current) {
    delay(5);                       // Delay by 5ms
    current = digitalRead(button);  // Read button state again
  }

  return current;  // return current value
}



// LED Mode Selection
void setMode(int mode) {
  if (mode == 1) {  // Red
    digitalWrite(REDLED, HIGH);
    digitalWrite(YELLOWLED, LOW);
    digitalWrite(GREENLED, LOW);
    activeLED = REDLED;
  } else if (mode == 2) {  // Yellow
    digitalWrite(REDLED, LOW);
    digitalWrite(YELLOWLED, HIGH);
    digitalWrite(GREENLED, LOW);
    activeLED = YELLOWLED;
  } else if (mode == 3) {  // Green
    digitalWrite(REDLED, LOW);
    digitalWrite(YELLOWLED, LOW);
    digitalWrite(GREENLED, HIGH);
    activeLED = GREENLED;
  } else {
    digitalWrite(REDLED, LOW);
    digitalWrite(YELLOWLED, LOW);
    digitalWrite(GREENLED, LOW);
    activeLED = 12;
  }
}

void setBlink(boolean isBlinking, int led) {
  if (isBlinking == true) {
    digitalWrite(led, (millis() % 512) > 256);

  } else if (isBlinking == false) {
    digitalWrite(activeLED, HIGH);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  currentColorButton = debounce(prevColorButton, COLORBUTTON);  // Read debounce state
  if (prevColorButton == LOW && currentColorButton == HIGH) {
    ledColorMode++;
  }
  prevColorButton = currentColorButton;
  if (ledColorMode == 4) {
    ledColorMode = 0;
  }
  setMode(ledColorMode);

  currentBlinkButton = debounce(prevBlinkButton, BLINKBUTTON);  // Read debounce state
  if (prevBlinkButton == LOW && currentBlinkButton == HIGH) {
    isBlinking = !isBlinking;
  }
  prevBlinkButton = currentBlinkButton;

  setBlink(isBlinking, activeLED);
}

// ALL DIGITAL INPUTS MUST HAVE A PULL DOWN RESISTOR CONNECTED TO GROUND
const int LED = 9;     // LED connected to pin 9
const int BUTTON = 2;  // Button connected to pin 2

boolean prevButton = LOW;     // Contains prev button state
boolean currentButton = LOW;  // Contains current button state
boolean ledOn = false;        // Present state of LED (on/off)

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
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

void loop() {
  // put your main code here, to run repeatedly:

  currentButton = debounce(prevButton);  // Read debounce state
  if (prevButton == LOW && currentButton == HIGH) {
    ledOn = !ledOn;
  }

  prevButton = currentButton;
  digitalWrite(LED, ledOn);
}

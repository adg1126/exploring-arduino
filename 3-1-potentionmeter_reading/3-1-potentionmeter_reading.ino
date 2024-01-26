const int POT = 0;    // Pot on pin 0
int val = 0;          // Holds analog reading from circuit

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(POT);
  Serial.println(val);
  delay(500);
}

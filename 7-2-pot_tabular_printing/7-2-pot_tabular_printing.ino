const int POT = 0;  // Analog pin 0
int potVal = 0;
int potPercentage = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println("\nAnalog Pin\tRaw Value\tPercentage");
  Serial.println("------------------------------------------");
  for (int i = 0; i < 10; i++) {
    potVal = analogRead(POT);
    potPercentage = map(potVal, 0, 1023, 0, 100);  // Convert to percentage

    Serial.print("A0\t\t");
    Serial.print(potVal);
    Serial.print("\t\t");
    Serial.print(potPercentage);
    Serial.println("%");
    delay(1000);
  }
}

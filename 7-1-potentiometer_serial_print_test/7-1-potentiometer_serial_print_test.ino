const int POT = 0;  // Analog pin 0
int potVal = 0;
int potPercentage = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void printLine() {
  Serial.println();
}

template<typename T, typename... Types>
void printLine(T first, Types... other) {
  Serial.print(first);
  printLine(other...);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(POT);
  potPercentage = map(potVal, 0, 1023, 0, 100);  // Convert to percentage
  
  printLine("Anaqlog Reading: ", potVal);
  printLine("Percentage: ", potPercentage, "%");
  delay(1000);
}

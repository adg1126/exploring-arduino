// C++ code
// LCD with Progress Bar

#include <LiquidCrystal.h>

const int TEMP_PIN = 0; //Analog pin 0
const int BUZZER = 9; // Buzzer on pin 9

// Upper and lower limit temp in Celsius
int maxTemp = 60;
int minTemp = 15;

boolean isBuzzing = false;

// Initialize the library with the number of the interface pins
// LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

//Custom degree char
byte degree[8] = {
  B00110,
  B01001,
  B01001,
  B00110,
  B00000,
  B00000,
  B00000,
  B00000,
};

void setup()
{
  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2);
  pinMode(BUZZER, OUTPUT); 
  lcd.createChar(0, degree);
  Serial.begin(9600);
}

void loop()
{
  int currentTemp = readTemp();
 
  if (currentTemp >= maxTemp) {
    lcd.setCursor(0,1);
    lcd.print("Too hot ");
    
    isBuzzing = true;
  } else if (currentTemp <= minTemp) {
    lcd.setCursor(0,1);
    lcd.print("Too cold");
    
    isBuzzing = true;
  } else {
    isBuzzing = false;
  }
  
  renderTemp(currentTemp);  
  setBuzzer();
  
  Serial.println(isBuzzing);
}

void setBuzzer() {
  if (isBuzzing == true) {
    tone(BUZZER, 1000);
    delay(500);
    noTone(BUZZER);
  } else if (isBuzzing == false) {
    noTone(BUZZER); 
  }
}

void renderTemp(int temp) {
  String tempS = String(temp);
  int strLength = tempS.length();
  
  //Move cursor to second line12-3-lcd_with_temperature
  lcd.setCursor(0,0);
  lcd.print("Temperature: ");
  
  if (strLength == 1) {
    lcd.print(tempS);
    lcd.write((byte)0);
    lcd.setCursor(15, 0);
    lcd.print("  ");
  } else if (strLength == 2) {
    lcd.print(tempS);
    lcd.write((byte)0);
  } else if (strLength == 3) {
    lcd.setCursor(12, 0);
    lcd.print(tempS);
    lcd.write((byte)0);
  }
  
  lcd.setCursor(0,1);
  lcd.print("");  
}

int readTemp() {
  int reading = analogRead(TEMP_PIN);
  
  // Convert that reading into voltage
  // Replace 5.0 with 3.3, if you are using a 3.3V Arduino
  float voltage = reading * (5.0 / 1024.0);

  // Convert the voltage into the temperature in Celsius
  float tempC = (voltage - 0.5) * 100;
  return tempC;
}
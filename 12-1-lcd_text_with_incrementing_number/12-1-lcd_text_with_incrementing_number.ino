// C++ code
// LCD text with incrementing number

#include <LiquidCrystal.h>

// Start time at 0
int time = 0;

// Initialize the library with the number of the interface pins
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup()
{
  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2);
  // Print message on LCD
  lcd.print("AD's Display");
}

void loop()
{
  lcd.setCursor(0,1);
  lcd.print(time);
  delay(1000);
  time++;
}
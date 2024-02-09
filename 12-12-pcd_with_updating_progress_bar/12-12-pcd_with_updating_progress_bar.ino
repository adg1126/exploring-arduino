// C++ code
// LCD with Progress Bar

#include <LiquidCrystal.h>

// Initialize the library with the number of the interface pins
// LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

//Create the progress bar characters
byte p20[8] = {
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
};
byte p40[8] = {
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
};
byte p60[8] = {
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
};
byte p80[8] = {
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
};
byte p100[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};

void setup()
{
  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2);
  // Print message on LCD
  lcd.print("AD's Display");
  
  //Make progress characters
  lcd.createChar(0, p20);
  lcd.createChar(1, p40);
  lcd.createChar(2, p60);
  lcd.createChar(3, p80);
  lcd.createChar(3, p100);
}

void loop()
{
  //Move cursor to second line
  lcd.setCursor(0,1);
  //Clear the line each time it reaches the end
  //with 16 spaces
  lcd.print("                ");
  
  //Iterate through each character on the second line
  for (int i=0; i<16; i++) {
    //Iterate through each progress val for each char
    for (int j= 0; j<5; j++) {
      lcd.setCursor(i, 1);	//Move cursor to this location
      lcd.write(j);	//Update progress bar
      delay(100);
    }
  }
}
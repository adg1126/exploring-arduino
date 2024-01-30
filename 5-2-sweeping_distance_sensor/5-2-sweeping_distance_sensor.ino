#include <Servo.h>

// C++ code
// Sweeping distance sensor

const int SERVO = 0;
const int IR = 0;
const int LED1 = 3;
const int LED2 =5;
const int LED3 = 6;
const int LED4 = 11;

Servo servo1;
int dist1 = 0;	// quadrant 1 dist
int dist2 = 0;	// quadrant 2 dist
int dist3 = 0;	// quadrant 3 dist
int dist4 = 0;	// quadrant 4 dist

void setup()
{
  servo1.attach(SERVO);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
}

void loop()
{
  // Sweep servo into 4 regions and change the LEDs
  dist1 = readDistance(15);	// Measure IT dist at 15 degrees
  analogWrite(LED1, dist1);	// Adjust LED brightness
  delay(300);
  
  dist2 = readDistance(65);	// Measure IT dist at 65 degrees
  analogWrite(LED2, dist2);	// Adjust LED brightness
  delay(300);
  
  dist3 = readDistance(115);	// Measure IT dist at 115 degrees
  analogWrite(LED3, dist3);	// Adjust LED brightness
  delay(300);
  
  dist4 = readDistance(165);	// Measure IT dist at 165 degrees
  analogWrite(LED2, dist4);	// Adjust LED brightness
  delay(300);
}

int readDistance(int pos) {
  servo1.write(pos);
  delay(600);
  int dist = analogRead(IR);
  dist = map(dist, 50, 500, 0, 255);
  dist = constrain(dist, 0, 255);
  return dist;
}
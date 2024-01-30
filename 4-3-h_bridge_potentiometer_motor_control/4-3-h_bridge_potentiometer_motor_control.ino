//H-bridge Motor Control
const int EN_9=9;   //Half Bridge 1 Enable
const int EN_10 = 10; // Half Bridge 3 Enable
const int MC1=3;  //Motor Control 1
const int MC2=2;  //Motor Control 2
const int MC3 = 5;	// Motor Control 3
const int MC4 = 4;	// Motor Control 4
const int POT=0;  //POT on Analog Pin 0

int val = 0;      //for storing the reading from the POT
int velocity = 0; //For storing the desired velocity (from 0-255)

void setup()
{
    pinMode(EN_9, OUTPUT);
  	pinMode(EN_10, OUTPUT);
    pinMode(MC1, OUTPUT);
    pinMode(MC2, OUTPUT);
    brake(); //Initialize with motor stopped
  	Serial.begin(9600);
}

void loop()
{
    val = analogRead(POT);
  	Serial.println(val);
 
    //go forward
    if (val > 562)
    {
        velocity = map(val, 563, 1023, 0, 255);
        forward(velocity);
    }
 
    //go backward
    else if (val < 462)
    {
        velocity = map(val, 461, 0, 0, 255);
        reverse(velocity);
    }
 
    //brake
    else
    {
        brake();
    }
}

//Motor goes forward at given rate (from 0-255)
void forward (int rate)
{
  digitalWrite(EN_9, LOW);
  digitalWrite(EN_10, LOW);
  digitalWrite(MC1, HIGH);
  digitalWrite(MC2, LOW);
  digitalWrite(MC3, HIGH);
  digitalWrite(MC4, LOW);
  analogWrite(EN_9, rate);
  analogWrite(EN_10, rate);
}

//Motor goes backward at given rate (from 0-255)
void reverse (int rate)
{
  digitalWrite(EN_9, LOW);
  digitalWrite(EN_10, LOW);
  digitalWrite(MC1, LOW);
  digitalWrite(MC2, HIGH);
  digitalWrite(MC3, LOW);
  digitalWrite(MC4, HIGH);
  analogWrite(EN_9, rate);
  analogWrite(EN_10, rate);
}

//Stops motor
void brake ()
{
  digitalWrite(EN_9, LOW);
  digitalWrite(EN_10, LOW);
  digitalWrite(MC1, LOW);
  digitalWrite(MC2, LOW);
  digitalWrite(MC3, LOW);
  digitalWrite(MC4, LOW);
  analogWrite(EN_9, HIGH);
  analogWrite(EN_10, HIGH);
}
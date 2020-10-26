//Embedded system for Controlling a DC motor with LDR using L293D IC and display status of motor in 16x2 LCD display.
//Coaded by- Anirban Bhattacharjee, Dept of Instrumentation & USIC, Gauhati University, Assam


#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


int enA = 9;
int in1 = 8;
int in2 = 7;
int LDR = A0;
int val = 0;


void setup() 
{
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
 
  
  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
   
  
}

void loop()
{
 
  val = analogRead(LDR);
  Serial.print("LDR Value is: ");
  Serial.println(val);
  delay(1000);

  if (val>700)
  { 
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("MOTOR IS ON");
  
    analogWrite(enA, 255);
  // Turn on motor A & B
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  }
else
{
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("MOTOR IS OFF");
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  }
}

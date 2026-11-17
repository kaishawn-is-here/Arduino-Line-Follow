#include <LiquidCrystal.h>

// Definitions Arduino pins connected to input H Bridge 
const int IN1 = A3;  
const int IN2 = 3; 
const int IN3 = 11; 
const int IN4 = 12; 

int seconds = 0;

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() 
{ 
 // Set the output pins 
 pinMode(IN1, OUTPUT); 
 pinMode(IN2, OUTPUT); 
 pinMode(IN3, OUTPUT); 
 pinMode(IN4, OUTPUT); 

 lcd.begin(16,2);
 lcd.print("Time (second):");
} 

void loop() 
{ 
  if (seconds < 10){
    digitalWrite(IN1, HIGH); 
    digitalWrite(IN2, LOW); 
    digitalWrite(IN3, LOW); 
    digitalWrite(IN4, HIGH); 

    lcd.setCursor(0,1);
    lcd.print(seconds);
    delay(1000);
    seconds += 1;
  }
 
  else{
    digitalWrite(IN1, HIGH); 
    digitalWrite(IN2, HIGH); 
    digitalWrite(IN3, LOW); 
    digitalWrite(IN4, LOW);

    lcd.setCursor(0,1);
    lcd.print("Stopped");
  } 
}

#include <LiquidCrystal.h>
const int rs = 2 , en = 3 , d4 = 4 , d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
// Define The sensors 
#define GAS A0
#define PIR A1 
#define FIRE 10 
#define BUZZER A2 

// variable to store the the values of sensors
int pirValue = 0 ;
int gasValue = 0 ; 
int fireValue = 0; 

void setup() {
pinMode(PIR , INPUT );
pinMode(GAS , INPUT);
pinMode(FIRE, INPUT);
pinMode(BUZZER,OUTPUT);
lcd.begin(20, 4);
lcd.setCursor(4, 1);
lcd.print("Arduino Home");
lcd.setCursor(2, 2);
lcd.print("-Home Security-");
delay(1500);
lcd.clear();
}
void loop() {
fireValue = digitalRead(FIRE) ; 
pirValue = analogRead(PIR);
gasValue = analogRead(GAS);
// All sensors is safe 
 if (fireValue == 0 && pirValue < 650 && gasValue < 620 ){
   delay(100);
   lcd.clear();
   lcd.setCursor(4, 1);
   lcd.print ("You are safe");
   noTone(BUZZER);
   }
// All sensors are active. 
 else if (fireValue == 1 && pirValue >= 650 && gasValue >= 620 ){
   delay(100);
   lcd.clear();
   tone(BUZZER,1500);
   lcd.setCursor(2,0);
   lcd.print ("Alarm");
   lcd.setCursor(2,1);
   lcd.print ("FIRE");
   lcd.setCursor(2,2);
   lcd.print ("GAS");
   lcd.setCursor(2,3);
   lcd.print ("MOTION");            
   }
// Fire sensor is active. 
 else if (fireValue == 1 && pirValue < 650 && gasValue < 620 ){
   delay(100);
   lcd.clear();
   tone(BUZZER,500);
   lcd.setCursor(6,1);
   lcd.print ("Alarm");  
   lcd.setCursor(6,2);
   lcd.print ("FIRE");
   }
// Pir sensor is active.
 else if (fireValue == 0 && pirValue >= 650 && gasValue < 620){
   delay(100);
   lcd.clear();
   tone(BUZZER,500);
   lcd.setCursor(6,1);
   lcd.print ("Alarm");  
   lcd.setCursor(6,2);
   lcd.print ("MOTION");     
   }
// Gas sensor is active. 
 else if (fireValue == 0 && pirValue < 650 && gasValue >= 620){
   delay(100);
   lcd.clear();
   tone(BUZZER,500);
   lcd.setCursor(6,1);
   lcd.print ("Alarm");  
   lcd.setCursor(7,2);
   lcd.print ("GAS");     
   }
// Fire and Motion sensors are active. 
 else if (fireValue == 1 && pirValue >= 650 && gasValue < 620){
   delay(100);
   lcd.clear();
   tone(BUZZER,1000);
   lcd.setCursor(6,1);
   lcd.print ("Alarm"); 
   lcd.setCursor(7,2);
   lcd.print ("FIRE");    
   lcd.setCursor(6,3);
   lcd.print ("MOTION");     
   } 
// Fire and Gas sensors are active. 
 else if (fireValue == 1 && pirValue < 650 && gasValue >= 620){
   delay(100);
   lcd.clear();
   tone(BUZZER,1000);
   lcd.setCursor(6,0);
   lcd.print ("Alarm"); 
   lcd.setCursor(7,1);
   lcd.print ("FIRE");    
   lcd.setCursor(7,2);
   lcd.print ("GAS");     
   }  
// Motion and Gas sensors are active.    
 else if (fireValue == 0 && pirValue >= 650 && gasValue >= 620){
   delay(100);
   lcd.clear();
   tone(BUZZER,1000);
   lcd.setCursor(6,0);
   lcd.print ("Alarm"); 
   lcd.setCursor(7,1);
   lcd.print ("GAS");
   lcd.setCursor(6,2);
   lcd.print ("Motion");    
   }
      }
 

#include<LiquidCrystal.h>
#include<math.h>

#define trigPin 10
#define echoPin 9

LiquidCrystal lcd(12,11,5,4,3,2);
void setup()
{
  lcd.begin(16,2);
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
void loop()
{
  long duration, distance, distanceInch;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  distanceInch = duration*0.0133/2;
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Distance:");
  lcd.setCursor(0,1);
  lcd.print(distance);
  lcd.print("cm");
 
//  lcd.print("Dist:");
//  lcd.print(distanceInch);
//  lcd.print("inch");
//  lcd.print((celsius * 9)/5 + 32);
//  lcd.print("F");
  Serial.println(distance);
  delay(1000);
}

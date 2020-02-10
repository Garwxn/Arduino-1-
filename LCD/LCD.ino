#include <LiquidCrystal.h>
LiquidCrystal LCD(10,9,5,4,3,2);

int trigPin=13;
int echoPin=11;
float pingTime;
float targetDistance;
float speedofSound=776.5;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  LCD.begin(16,2);
  LCD.setCursor(0,0);
  LCD.print("Target Distance: ");
   
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);

  pingTime = pulseIn(echoPin, HIGH);
  pingTime = pingTime/1000000.;
  pingTime = pingTime/3600.;
  targetDistance = speedofSound*pingTime;
  targetDistance = targetDistance/2;
  targetDistance = targetDistance*160934;

  LCD.setCursor(0,1);
  LCD.print("                ");
  LCD.setCursor(0,1);
  LCD.print(targetDistance);
  LCD.print(" cm"); 
  delay(250);
}

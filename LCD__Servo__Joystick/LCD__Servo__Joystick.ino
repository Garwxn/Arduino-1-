#include <NewPing.h>
#include <Servo.h>
#include <LiquidCrystal.h>
LiquidCrystal LCD(10,9,5,4,3,2);

int VRx = A0;
int VRy = A1;
int SW = 8;

int servoPin = 6;

int trig = 13;
int echo = 12;
int distance;

//100 = maxDistance
NewPing sonar(trig, echo, 100);
Servo servo;

int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  servo.attach(servoPin);
  
  LCD.begin(16,2);

pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
  
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
 
  
long duration, distance;
digitalWrite(trig, LOW);
delayMicroseconds(2);
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);
duration = pulseIn(echo, HIGH);
distance = (duration/2) / 29.1;
if (distance < 5) {
Serial.println("the distance is less than 5");
servo.write(180);
}
else {
servo.write(0);
}
if (distance > 180 || distance <= 0){
Serial.println("The distance is more than 180");
}
else {
Serial.print(distance);
Serial.println(" cm");
}
delay(50);
 
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  SW_state = digitalRead(SW);
  mapX = map(xPosition, 0, 1023, -100, 100);
  mapY = map(yPosition, 0, 1023, -100, 100);

  Serial.print("X: ");
  Serial.print(mapX);
  Serial.print("Y: ");
  Serial.print(mapY);
  Serial.print("Button: ");
  Serial.print(SW_state);

  LCD.setCursor(0,0);
  LCD.print("X: ");
  LCD.setCursor(0,1);
  LCD.print(mapX);

//  LCD.clear(100);
  
  LCD.setCursor(0,0);
  LCD.print("Y: ");
  LCD.setCursor(0,1);
  LCD.print(mapY);

//  LCD.clear(100);
  
  LCD.setCursor(0,0);
  LCD.print("Button: ");
  LCD.setCursor(0,1);
  LCD.print(SW_state);
  delay(100);

//  LCD.clear(100);
}

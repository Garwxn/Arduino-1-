#include <Servo.h>
Servo myPointer;

int val;
int servoPin = 6;


void setup() {
  // put your setup code here, to run once:
myPointer.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
val = analogRead(1);
val = map(val, 0, 1023, 0, 180);
myPointer.write(val);
delay(15);
}

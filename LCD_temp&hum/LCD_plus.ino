#include <LiquidCrystal.h>
#include <SimpleDHT.h>
LiquidCrystal LCD(10,9,5,4,3,2);

int trigPin=13;
int echoPin=11;
float pingTime;
float targetDistance;
float speedofSound=776.5;

float temperature;
float humidity;
int pinDHT11 = 7;
SimpleDHT11 dht11(pinDHT11);

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  LCD.begin(16,2);

   
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

   byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    LCD.print("Read DHT11 failed, err="); LCD.println(err);delay(1000);
    return;
  }

  LCD.setCursor(0,0);
  LCD.print("Target Distance: ");
  LCD.setCursor(0,1);
  LCD.print(targetDistance);
  LCD.print(" cm"); 
  delay(1000);

  LCD.clear();

  LCD.setCursor(0,0);
  LCD.print("Temperature: ");
  LCD.setCursor(0,1);
  LCD.print(temperature);
  LCD.print(" *C");
  delay(1000);

  LCD.clear();

  LCD.setCursor(0,0);
  LCD.print("Humidity: ");
  LCD.setCursor(0,1);
  LCD.print(humidity);
  LCD.print(" H");
  delay(1000);

  LCD.clear();

}

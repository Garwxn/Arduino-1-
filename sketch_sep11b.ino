
int LED=10;  //Declare brightLEDPin to pin 10
int LEDred=6;  //Declare redLEDPin to pin 6
int brightOnTime=250;  //Turn brightLEDPin on, set to 250
int brightOffTime=250;  //Turn brightLED off, set to 250
int redTimeOn=250;  //Turn redLED on, set to 250
int redTimeOff=250;  //Turn redLED off, set to 250
int numbrightblink=5;  //Number of times for brightLED to blink
int numredblink=5;  //Number of times for redLED to blink
String redmessage="The red LED is Blinking";  //Declaring a String Variable
String brightmessage="The bright LED is Blinking";  //Declaring a String Variable
int writeValuebright;  //Declare variable for writeValuebright
int writeValuered;  //Declare variable for writeValuered


void setup() {
  Serial.begin(9600);  
  pinMode(LEDred,OUTPUT);  //Tell Arduino that redLED is an output pin
  pinMode(LED,OUTPUT);  //Tell Arduino that brightLED is an output pin
  
  Serial.println("What Number do you want to write to the bright LED (0-255)? ");  //Prompt User for Input
  while (Serial.available()==0){ }  //wait for User Input
  writeValuebright = Serial.parseInt();  //Read user Input
  
  Serial.println("What Number do you want to write to the red LED (0-255)? ");  //Prompt User for Input
  while (Serial.available()==0){ }  //Wait for User Input
  writeValuered = Serial.parseInt();  //Read user Input
}

void loop() {
  
  Serial.println(brightmessage);
  int j=1;
  while (j<=numbrightblink) {  //Start our while loop
    Serial.print( "You are on Blink #: ");
    Serial.println(j);
    analogWrite(LED, writeValuebright);  //Apply Analog voltage to pin
    delay(brightOnTime);  //Leave on for brightOnTime
    analogWrite(LED, 0);  //Turn bright LED off
    delay(brightOffTime);  //Leave off for brightOffTime
    j=j+1;

}
Serial.println("");
Serial.println(redmessage);
for (int j=1; j<=numredblink; j=j+1) {  //Start our loop for
  Serial.print("You are on blink #: ");
  Serial.println(j);
  analogWrite(LEDred, writeValuered);  //Apply analog voltage to pin
  delay(redTimeOn);  //Leave on for redTimeOn
  analogWrite(LEDred, 0);  //Turn red LED off
  delay(redTimeOff);  //Leave off for redTimeOff
}
Serial.println(" ");
}

int trigPin = 7;  //Define the pins that you will work with
int echoPin = 8;
int LEDR = 10;
int LEDV = 11;
float Speed = 0.0343;  // Sound speed at cm/us
long duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);  //Define digital pin 7 as an output

   pinMode(echoPin, INPUT);   //Define digital pin 8 as an input

   pinMode(LEDR, OUTPUT);   //Define digital pin 10 as an output

   pinMode(LEDV, OUTPUT);   //Define digital pin 11 as an output

   digitalWrite (LEDR , LOW);  // Define digital pin 10 in a low status

   digitalWrite (LEDV , LOW);  //Define digital pin 11 in a low status
}

void loop() {
  digitalWrite(trigPin, LOW);        // Make sure that the TRIG is deactivated

   delayMicroseconds(2);              // Make sure that the TRIG is in LOW

   digitalWrite(trigPin, HIGH);       // Activate the output pulse 
   delayMicroseconds(10);             // Wait for 10µs, the pulse remains active during this time

   digitalWrite(trigPin, LOW);        //Stop the pulse and wait for ECHO 

   duration = pulseIn(echoPin, HIGH) ; // pulseIn measures the time since the defined pin (echoPin) changes its status from low to high (from 0 to 1)

   distance = Speed* duration / 2;   //Divide by 2 because we want to have only the “go” time, not the “go and back” time
                                       // and divide by 29,1 because 1 is divided by the sound speed (1/SpeedSound) at cm/us

   if ( distance < 20){
       digitalWrite (LEDR , HIGH);     //If the sensor detects a distances less than 20 cm the red LED turns on

       digitalWrite (LEDV , LOW);      //and turns off the green LED

}
  else if (distance>20) {
         digitalWrite (LEDR , LOW);    // turn off the red LED
         digitalWrite (LEDV , HIGH);   //turn on the green LED }
}
}

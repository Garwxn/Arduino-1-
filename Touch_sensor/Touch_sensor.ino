//Touch Sensor LED

 #define ctsPin 2 

 int ledPin = 13;
 int ledRed = 5;
 
 void setup()
 {  
     Serial.begin(9600);
       pinMode(ledPin, OUTPUT);
       pinMode(ledRed, OUTPUT);
       pinMode(ctsPin, INPUT);
     } 
  void loop() 
    { 
      int ctsValue = digitalRead(ctsPin); 
      if (ctsValue == HIGH)
        {  
           digitalWrite(ledPin, HIGH);
           digitalWrite(ledRed, HIGH);  
           Serial.println("TOUCHED");
           }  
     else
        {    
         digitalWrite(ledPin,LOW);
         digitalWrite(ledRed,LOW);
             Serial.println("not touched"); 
          }  
      delay(0.9);  
      }

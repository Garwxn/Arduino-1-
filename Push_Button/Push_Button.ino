
const int buttonPin = 8;     // the number of the pushbutton pin
const int ledPin =  9;      // the number of the LED pin
const int button = 10;
const int LED = 11;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int buttonValue = 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

  pinMode(LED, OUTPUT);

  pinMode(button, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  buttonValue = digitalRead(button);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }

   if (buttonValue == HIGH) {
    // turn LED on:
    digitalWrite(LED, HIGH);
  } else {
    // turn LED off:
    digitalWrite(LED, LOW);
  }
}

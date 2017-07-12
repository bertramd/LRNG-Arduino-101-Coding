int LEDPin = 13;          //initializes LEDPin as the pin the LED is connected to
int waitTimeOn = 1000;    //initializes a variable that sets the time the LED is on
int waitTimeOff = 1000;   //initializes a variable that sets the time the LED is off

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LEDPin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LEDPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(waitTimeOn);            // how long the LED is on
  digitalWrite(LEDPin, LOW);    // turn the LED off by making the voltage LOW
  delay(waitTimeOff);           // how long the LED is off
}

int LEDPin = 9;
int onTime = 1000;
int offTime = 500;
int numBlinks = 4;
int brightness = 0;
int fadeAmount = 5;

void setup() {
  pinMode(LEDPin, OUTPUT);

}

void loop() {
  for (int i = 1; i <= numBlinks; i = i + 1)
  {
    digitalWrite(LEDPin, HIGH);
    delay(onTime);
    digitalWrite(LEDPin, LOW);
    delay(offTime);  
  }
  for (brightness = 0; brightness <= 255; brightness = brightness + fadeAmount)
  {
    analogWrite(LEDPin, brightness);
    delay(30);
  }
}


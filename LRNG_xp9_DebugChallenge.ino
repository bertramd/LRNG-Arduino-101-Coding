const int LEDPin = 9;   //Pin 9
int onTimeShort = 500; //LED on for .5 seconds
int offTimeShort = 250; //LED off for .25 seconds
int onTimeLong = 1000; //LED on for 1 second
int offTimeLong = 500; //LED off for .5 seconds
int brightness = 0; //The brightness should start at 0
int fadeAmount = 5;  //Increment the pulse brightness by 5
String longMessage = "Long Blink";
String pulseMessage = "Pulse";
String shortMessage = "Short Blink";

void setup() {
  Serial.begin(9600);
  pinMode(LEDPin, OUTPUT);
  digitalWrite(LEDPin, LOW);
}

void loop() {
  Serial.println("Blink or pulse?");
  while(Serial.available() == 0){ //Wait for User Input
  }
  if(Serial.readString() != "blink" || Serial.readString() != "pulse"){
    Serial.println("Your response was invalid. Blink or pulse?");
  }
  if(Serial.readString() == "blink"){
    Serial.println("Long or short?");
    while(Serial.available() == 0){ //Wait for User Input
    }  
    if(Serial.readString() == "long"){
      blinkLong();
    }
    if(Serial.readString() == "short"){
      blinkShort();
    }
    else{ //this "else" can be replaced with the below if statement
      Serial.println("Your response was invalid. Long or short?");
    }
    /*
     if (Serial.readString() != "Long" || Serial.readString() != "Short"){
       Serial.println("Your response was invalid. Long or short?");
     }
     */
  }   
  if(Serial.readString() == "pulse"){
    pulse();
  }
}

void blinkLong(){
  Serial.println(longMessage); //Can be placed anywhere within the function
  digitalWrite(LEDPin, HIGH);
  delay(onTimeLong);
  digitalWrite(LEDPin, LOW);
  delay(offTimeLong);
}

void pulse(){
  Serial.println(pulseMessage); //Can be placed anywhere within the function
  for (brightness = 0; brightness <= 255; brightness = brightness + fadeAmount)
  {
    analogWrite(LEDPin, brightness);
    delay(30);
  }
}

void blinkShort(){
  Serial.println(shortMessage); //Can be placed anywhere within the function
  digitalWrite(LEDPin, HIGH);
  delay(onTimeShort);
  digitalWrite(LEDPin, LOW);
  delay(offTimeShort);
}


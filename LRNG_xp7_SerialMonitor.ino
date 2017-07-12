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
 //Note: i can be replaced with any variable
 //the counter must have int before it the first time it is used
 int i = i + 1;    //can also be written: int i++;
 /* Counter can also be written as an if statement:
  * if (int i <= 10){
  *   i = i + 1;
  * }  
  * else{
  *   i = 0
  * }
  */
  for(i = 0; i <= 10; i = i + 1){ 
  /* other answers: 
   * for(i == 0; i < 11; i = i + 1){
   * for(i == 0; i < 11; i++){
  */
    /* the following conditions can be in any order as long as they are written: 
     * if..if..else 
     * if..else if..else 
     * if..if..if
     * and the conditional operators match the functions
     */
    if(i >= 1 && i <= 3){ //other answer: if(i > 0 && i < 4){...
      blinkLong();
    }
    else if(i >= 4 && i <= 7 || i == 9){  //other answer: else if(i > 5 && i < 8 || i == 9){...
      pulse();
    }
    else {  //if the above is an if statment: if (i == 8 || i == 10){...}
      blinkShort();
    }
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


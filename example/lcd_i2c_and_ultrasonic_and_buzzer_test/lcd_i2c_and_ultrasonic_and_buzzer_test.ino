// |———————————————————————————————————————————————————————| 
// |  made by Arduino_uno_guy 11/13/2019                   |
// |   https://create.arduino.cc/projecthub/arduino_uno_guy|
//  |———————————————————————————————————————————————————————|


#include <LiquidCrystal_I2C.h>

#include  <Wire.h>

//initialize the liquid crystal library
//the first parameter is  the I2C address
//the second parameter is how many rows are on your screen
//the  third parameter is how many columns are on your screen
LiquidCrystal_I2C lcd(0x27,  16, 2);
const int trigPin = 9;  
const int echoPin = 10; 
float duration, distance;
int buzzer = 8 ;

void setup() {
  pinMode(trigPin, OUTPUT);  
	pinMode(echoPin, INPUT);  
	Serial.begin(9600);
  //initialize lcd screen
  lcd.init();
  // turn on the backlight
  lcd.backlight();

  pinMode (buzzer, INPUT);
  digitalWrite (buzzer, LOW) ; //no tone
  //Serial.begin(9600);
}

void loop() {
  lcd.clear();
  // tell the screen to write on the top row
  lcd.setCursor(0,0);
  // tell the screen to write “hello, from” on the top  row
  lcd.print("Hello, From Ethan");
  // tell the screen to write on the bottom  row
  lcd.setCursor(0,1);
  // tell the screen to write “Arduino_uno_guy”  on the bottom row
  // you can change whats in the quotes to be what you want  it to be!
  //lcd.print("Arduino is here");
  
  digitalWrite(trigPin, LOW);  
	delayMicroseconds(2);  
	digitalWrite(trigPin, HIGH);  
	delayMicroseconds(10);  
	digitalWrite(trigPin, LOW); 
  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  lcd.print("Distance: " + String(distance));

  if(distance < 30) {
    tone(buzzer,400,100);
  } else {
    noTone(buzzer);
  }
  //wait  for a second
  delay(distance);
}

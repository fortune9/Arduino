// https://www.youtube.com/watch?v=a_8G_rGZbB0

#define trigPin 9
#define echoPin 10
int buzz = 8;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  //instead of parenthesis () put angle bracket as YouTube description does not allow angle bracket
  if (distance <= 10){ 
    tone(buzz,400,100);
  } else {
    noTone(buzz);
  }
  delay(50);
}
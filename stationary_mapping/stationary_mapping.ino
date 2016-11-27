#include <Servo.h>  
Servo myservo;

void setup() {

  Serial.begin(9600);
  pinMode(14, OUTPUT);
  pinMode(15, INPUT);
  pinMode(18,OUTPUT);
  pinMode(19,INPUT);
  myservo.attach(10);
  myservo.write(0);         
  delay(5000);
}

void loop() {
 
 for (int pos = 0; pos <=180; pos += 2) { 
    myservo.write(pos);       
    ultra(1,14,15,pos);
    ultra(2,18,19,pos+180);
  }
  for (int pos = 180; pos >= 0; pos -= 2) { 
    myservo.write(pos);       
    ultra(1,14,15,pos);
    ultra(2,18,19,pos+180);
  }
}

void ultra(int num,int trigPin,int echoPin,int angle){
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW); 
  Serial.print(pulseIn(echoPin, HIGH));
  Serial.print(",");
  Serial.println(angle);
  delay(10);
}





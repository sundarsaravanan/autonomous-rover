#include<Servo.h>
#include<AFMotor.h>
Servo wheel_servo;
Servo ultra_servo;
AF_DCMotor right(4);
AF_DCMotor left(1);
float pingTime; 
float targetDistance; 
float speedOfSound=776.5;
float l=0;
void setup() {
  Serial.begin(9600);
  wheel_servo.attach(9);
  wheel_servo.write(100);
  ultra_servo.attach(10);
  ultra_servo.write(90);
  
  pinMode(14, OUTPUT);
  pinMode(15, INPUT);
  delay(5000);
  
  Serial.println("Start...");
  while(Serial.available()==0);
  Serial.println(l);
}

void loop() {
  digitalWrite(14, LOW);
  delayMicroseconds(2); 
  digitalWrite(14, HIGH); 
  delayMicroseconds(5);
  digitalWrite(14, LOW); 
  pingTime = pulseIn(15, HIGH);  
  pingTime=pingTime/1000000; 
  pingTime=pingTime/3600; 
  targetDistance= speedOfSound * pingTime;  
  targetDistance=targetDistance/2; 
  targetDistance= targetDistance*63360*2.54;   
  if(targetDistance < 10.0 ){
    right.run(RELEASE);
    left.run(RELEASE);
    l=l+targetDistance;
    Serial.println(l);
    delay(5000);
   
  }
  else{
    wheel_servo.write(100);
    right.run(FORWARD);
    right.setSpeed(90);
    left.run(FORWARD);
    left.setSpeed(250);
    delay(899);
    l=l+10.0;
    Serial.println(l);
    right.run(RELEASE);
    left.run(RELEASE);
    delay(5000);
  } 
}




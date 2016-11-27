#include<Servo.h>
#include<AFMotor.h>
Servo wheel_servo;
Servo ultra_servo;
AF_DCMotor right(4);
AF_DCMotor left(1);
float pingTime; 
float targetDistance; 
float speedOfSound=776.5;

void setup() {
  Serial.begin(9600);
  wheel_servo.attach(9);
  wheel_servo.write(100);
  ultra_servo.attach(10);
  ultra_servo.write(90);
  pinMode(14, OUTPUT);
  pinMode(15, INPUT);
  delay(5000);
  Serial.println("Interupt");
  while(Serial.available()==0);
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
  targetDistance= targetDistance*63360;    

  if(targetDistance < 10.0 ){
    wheel_servo.write(120);
    right.run(BACKWARD);
    right.setSpeed(90);
    left.run(FORWARD);
    left.setSpeed(250);
    delay(1000);
  }

  else{
    wheel_servo.write(100);
    right.run(FORWARD);
    right.setSpeed(90);
    left.run(FORWARD);
    left.setSpeed(250);
  }
  
  
  
  
}




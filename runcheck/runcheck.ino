#include<Servo.h>
#include<AFMotor.h>
Servo wheel_servo;
AF_DCMotor right(4);
AF_DCMotor left(1);

void setup() {

  Serial.begin(9600);
  
  wheel_servo.attach(9);
  wheel_servo.write(100);
}

void loop() {
  int option;
  Serial.println("enter the delay:");
  while (Serial.available() == 0);
  option = Serial.parseInt();
  wheel_servo.write(100);
  right.run(FORWARD);
  right.setSpeed(200);
  right.setSpeed(90);
  left.run(FORWARD);
  left.setSpeed(250);
  delay(900);
   right.run(RELEASE);
  left.run(RELEASE);
  
}




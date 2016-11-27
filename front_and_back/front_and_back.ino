#include<Servo.h>
#include<AFMotor.h>
Servo wheel_servo;
AF_DCMotor right(4);
AF_DCMotor left(1);

void setup() {

  Serial.begin(9600);
  //pinMode(14, OUTPUT);
  //pinMode(15, INPUT);
  wheel_servo.attach(9);
  wheel_servo.write(90);
}

void loop() {
  int option;
  Serial.println("enter the delay:");
  while (Serial.available() == 0);
  option = Serial.parseInt();
  wheel_servo.write(100);
  right.run(FORWARD);
  right.setSpeed(90);
  left.run(FORWARD);
  left.setSpeed(250);
  delay(option);
   right.run(RELEASE);
  left.run(RELEASE);
  delay(5000);
  right.run(BACKWARD);
  right.setSpeed(90);
  left.run(BACKWARD);
  left.setSpeed(250);
  delay(option);
  right.run(RELEASE);
  left.run(RELEASE);

}




#include<Servo.h>
#include<AFMotor.h>
Servo wheel_servo;
AF_DCMotor right(1);
AF_DCMotor left(4);

void setup() {

  Serial.begin(115200);
  pinMode(14, OUTPUT);
  pinMode(15, INPUT);
  wheel_servo.attach(10);
  wheel_servo.write(80);
}

void loop() {
  int option;

  ultra(1, 14, 15);
  Serial.println("enter the turning direction:");
  while (Serial.available() == 0);
  option = Serial.parseInt();

  if (option == 1) {

    direction(70, FORWARD, BACKWARD);
  }
  if (option == 2) {
    direction(90, BACKWARD, FORWARD);

  }
  if (option == 3) {

    direction(80, FORWARD, FORWARD);

  }
  if (option == 4) {

    direction(80, BACKWARD, BACKWARD);

  }
  if (option == 5) {
    right.run(RELEASE);
    left.run(RELEASE);
  }
}

void ultra(int num, int trigPin, int echoPin) {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
  Serial.println(pulseIn(echoPin, HIGH));

}

void direction(int ser, char right_dir, char left_dir) {
  wheel_servo.write(ser);
  right.run(right_dir);
  right.setSpeed(250);
  left.run(left_dir);
  left.setSpeed(80);
}


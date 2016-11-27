# Autonomous Rover

Self designed four wheeled rover.

Two motors are used for back wheels.

Used differential steering to change the direction.

Powered by AC-DC adapter since it drains the batteries quickly.Rechargeable batteries are not affordable.

Integrated with python using xbee modules for serial data trannsfer.

Parts:

* Arduino Uno
* Motor Shield 
* Geared DC motors X 2 
* Servo motor x 2
* xbee x 2
* Ultrasonic Sensor x 2


Using ultrasonic sensor we can sense the distance to obstacles.So thought of creating a 360 degree 2D map around the rover by plotting the distance in a graph.

Servo motors can turn only 180 degree. To get 360 degree readings, I used two ultrasonic sensors with back to each other.


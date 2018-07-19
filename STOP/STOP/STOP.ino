//TO RUN THE SKETCH, CLICK THE RIGHT POINTING ARROW BUTTON ABOVE TO UPLOAD THE CODE TO THE NUC
//WHEN IT SAYS UPLOAD COMPLETE AT THE BOTTOM OF THE SCREEN, TURN ON THE THRUSTERS AND CLICK THE CHECK BUTTON TO RUN IT

//RUN THIS SKETCH TO STOP THE THRUSTERS
#include <Servo.h>
//HERE YOU CAN SEE WHICH SERVO NUMBER REPRESENTS EACH THRUSTER
byte servoPin1 = 3; // Right Front   - pink
byte servoPin2 = 4; // Right Top          - red
byte servoPin3 = 6; // Right Back     - grey
byte servoPin4 = 7; // Left Front          - yellow
byte servoPin5 = 8; // Right Bottom              - green
byte servoPin6 = 9; // Left Bottom       - purple
byte servoPin7 = 10; // Left Back              - blue
byte servoPin8 = 11; // Left Top        - white

int MissionSwitch = 34;
int Mission = 0;

//SET SPEED HERE: SIGNAL VALUE INDICATES SPEED, 1000 IS FULL SPEED COUNTERCLOCKWISE AND 1499 IS SLOWEST COUNTERCLOCKWISE, 1500 IS STOPPED, 1501 IS SLOWEST CLOCKWISE AND 2000 IS FULL SPEED CLOCKWISE
int signal = 1600; // Set signal value, aka speed
int stop = 1500; // Stop thruster

Servo servo1; 
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
Servo servo7;
Servo servo8;

void setup() 
{
  servo1.attach(servoPin1); 
  servo2.attach(servoPin2); 
  servo3.attach(servoPin3); 
  servo4.attach(servoPin4); 
  servo5.attach(servoPin5); 
  servo6.attach(servoPin6); 
  servo7.attach(servoPin7); 
  servo8.attach(servoPin8); 

  //stop them all
  servo1.writeMicroseconds(1500); // send "stop" signal to ESC.
  servo2.writeMicroseconds(1500); // send "stop" signal to ESC.
  servo3.writeMicroseconds(1500); // send "stop" signal to ESC.
  servo4.writeMicroseconds(1500); // send "stop" signal to ESC.
  servo5.writeMicroseconds(1500); // send "stop" signal to ESC.
  servo6.writeMicroseconds(1500); // send "stop" signal to ESC.
  servo7.writeMicroseconds(1500); // send "stop" signal to ESC.
  servo8.writeMicroseconds(1500); // send "stop" signal to ESC.

  pinMode(MissionSwitch, INPUT); //Mission switch connection as input
  
  delay(1000); // delay to allow the ESC to recognize the stopped signal
}

void loop() 
{
  Mission = digitalRead(MissionSwitch); // read Mission Switch input 
  char dir='t'; //direction
  if (Mission== HIGH)
  {
    still();
  }

}
void still()
{
  //stop them all
  servo1.writeMicroseconds(1500); // send "stop" signal to ESC.
  servo2.writeMicroseconds(1500); // send "stop" signal to ESC.
  servo3.writeMicroseconds(1500); // send "stop" signal to ESC.
  servo4.writeMicroseconds(1500); // send "stop" signal to ESC.
  servo5.writeMicroseconds(1500); // send "stop" signal to ESC.
  servo6.writeMicroseconds(1500); // send "stop" signal to ESC.
  servo7.writeMicroseconds(1500); // send "stop" signal to ESC.
  servo8.writeMicroseconds(1500); // send "stop" signal to ESC.\

  delay(60000);
}


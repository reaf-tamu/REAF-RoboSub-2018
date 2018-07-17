#include <Servo.h>

byte servoPin1 = 8; // right side, upper middle, forward facing
byte servoPin2 = 9; // right side, front, downward facing
byte servoPin3 = 10; // right side, lower middle, forward facing
byte servoPin4 = 11; // right side, back, downward facing
byte servoPin5 = 3; //left side, front, downward facing
byte servoPin6 = 4; //left side, lower middle, forward facing
byte servoPin7 = 6; // left side, back, downward facing
byte servoPin8 = 7; //left side, upper middle, forward facing

Servo servo1; 
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
Servo servo7;
Servo servo8;

void setup() {
  servo1.attach(servoPin1); 
  servo2.attach(servoPin2); 
  servo3.attach(servoPin3); 
  servo4.attach(servoPin4); 
  servo5.attach(servoPin5); 
  servo6.attach(servoPin6); 
  servo7.attach(servoPin7); 
  servo8.attach(servoPin8); 

  servo1.writeMicroseconds(1500); // send "stop" signal to ESC.
  servo2.writeMicroseconds(1500); // send "stop" signal to ESC.
  servo3.writeMicroseconds(1500); // send "stop" signal to ESC.
  servo4.writeMicroseconds(1500); // send "stop" signal to ESC.
  servo5.writeMicroseconds(1500); // send "stop" signal to ESC.
  servo6.writeMicroseconds(1500); // send "stop" signal to ESC.
  servo7.writeMicroseconds(1500); // send "stop" signal to ESC.
  servo8.writeMicroseconds(1500); // send "stop" signal to ESC.
  
  delay(1000); // delay to allow the ESC to recognize the stopped signal
}

void loop() {
  int signal = 1550; // Set signal value, which should be between 1100 and 1900

  servo1.writeMicroseconds(signal); // Send signal to ESC.
  servo2.writeMicroseconds(signal); // Send signal to ESC.
  servo3.writeMicroseconds(signal); // Send signal to ESC.
  servo4.writeMicroseconds(signal); // Send signal to ESC.
  servo5.writeMicroseconds(signal); // Send signal to ESC.
  servo6.writeMicroseconds(signal); // Send signal to ESC.
  servo7.writeMicroseconds(signal); // Send signal to ESC.
  servo8.writeMicroseconds(signal); // Send signal to ESC.

}

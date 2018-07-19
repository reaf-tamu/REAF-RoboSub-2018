#include <Servo.h>

byte servoPin1 = 8; 
byte servoPin2 = 9; 
byte servoPin3 = 10; 
byte servoPin4 = 11;                                                                                                    

int signal = 1550; // Set signal value, which should be between 1100 and 1900
int stop = 1500; // Stop thruster

Servo servo1; 
Servo servo2;
Servo servo3;
Servo servo4;

void setup() {
  // put your setup code here, to run once:
  servo1.attach(servoPin1); 
  servo2.attach(servoPin2); 
  servo3.attach(servoPin3); 
  servo4.attach(servoPin4); 

  servo1.writeMicroseconds(1500); // send "stop" signal to ESC.
  servo2.writeMicroseconds(1500); // send "stop" signal to ESC.
  servo3.writeMicroseconds(1500); // send "stop" signal to ESC.
  servo4.writeMicroseconds(1500); // send "stop" signal to ESC.

  delay(1000); // delay to allow the ESC to recognize the stopped signal
}

void loop() {
  // put your main code here, to run repeatedly:

    servo1.writeMicroseconds(signal); // Send signal to ESC.
    delay(2000);
    servo1.writeMicroseconds(stop); // Send signal to ESC.
    delay(2000);

    servo2.writeMicroseconds(signal); // Send signal to ESC.
    delay(2000);
    servo2.writeMicroseconds(stop); // Send signal to ESC.
    delay(2000);

    servo3.writeMicroseconds(signal); // Send signal to ESC.
    delay(2000);
    servo3.writeMicroseconds(stop); // Send signal to ESC.
    delay(2000);

    servo4.writeMicroseconds(signal); // Send signal to ESC.
    delay(2000);
    servo4.writeMicroseconds(stop); // Send signal to ESC.
    delay(2000);

}

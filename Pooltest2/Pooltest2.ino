#include <Servo.h>

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

int signal = 1750; // Set signal value, which should be between 1100 and 1900
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
  /*
  Serial.begin(9600);
  Serial.println("Directions (d=Down,f=Forward,l=Left,r=Right)");
  */
}

void loop() 
{
  Mission = digitalRead(MissionSwitch); // read Mission Switch input 
  char dir='t'; //direction
  if (Mission== HIGH)
  {
    down();
    forward();
    right();
    left();
    //flipc();
    //flipf();
  }
  /*
  if (Mission == HIGH || dir!='q')
  {
    dir= Serial.read();
    switch(dir){
      case 'd':
        down();
        break;
      case 'f':
        forward();
        break;
      case 'l':
        left();
        break;
      case 'r':
        right();
        break;
      default:
        Serial.println("Directions (D=Down,F=Forward,L=Left,R=Right)");
        break;  
   }

  }
  */

}
void down()
{
    servo2.writeMicroseconds(signal); // Send signal to ESC.
    servo3.writeMicroseconds(signal); // Send signal to ESC.
    servo6.writeMicroseconds(signal); // Send signal to ESC.
    servo7.writeMicroseconds(signal); // Send signal to ESC.
    
    delay(5000);

    servo2.writeMicroseconds(stop); // Send signal to ESC.
    servo3.writeMicroseconds(stop); // Send signal to ESC.
    servo6.writeMicroseconds(stop); // Send signal to ESC.
    servo7.writeMicroseconds(stop); // Send signal to ESC.

    delay(5000);
}
void forward()
{

    servo1.writeMicroseconds(signal); // Send signal to ESC.
    servo4.writeMicroseconds(signal); // Send signal to ESC.
    servo5.writeMicroseconds(signal); // Send signal to ESC.
    servo8.writeMicroseconds(signal); // Send signal to ESC.

    delay(5000);

    servo1.writeMicroseconds(stop); // Send signal to ESC.
    servo4.writeMicroseconds(stop); // Send signal to ESC.
    servo5.writeMicroseconds(stop); // Send signal to ESC.
    servo8.writeMicroseconds(stop); // Send signal to ESC.

    delay(5000);    

}
void left()
{

  servo3.writeMicroseconds(signal);
  servo2.writeMicroseconds(signal);

  delay(5000);

  servo3.writeMicroseconds(stop);
  servo2.writeMicroseconds(stop);

  delay(5000);
}  
void right()
{

  servo5.writeMicroseconds(signal);
  servo6.writeMicroseconds(signal);

  delay(5000);
  
  servo5.writeMicroseconds(stop);
  servo6.writeMicroseconds(stop);  

  delay(5000);
}  
void flipc()
{

  servo1.writeMicroseconds(signal);
  servo4.writeMicroseconds(signal);

  delay(5000);

  servo1.writeMicroseconds(stop);
  servo4.writeMicroseconds(stop);
  
  delay(5000);
}  
void flipf()
{
  servo7.writeMicroseconds(signal);
  servo4.writeMicroseconds(signal);

  delay(5000);

  servo7.writeMicroseconds(stop);
  servo4.writeMicroseconds(stop);

  delay(5000);
}


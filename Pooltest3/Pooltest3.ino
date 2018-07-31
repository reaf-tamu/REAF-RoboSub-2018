//TO RUN THE SKETCH, CLICK THE RIGHT POINTING ARROW BUTTON ABOVE TO UPLOAD THE CODE TO THE NUC
//WHEN IT SAYS UPLOAD COMPLETE AT THE BOTTOM OF THE SCREEN, TURN ON THE THRUSTERS AND CLICK THE CHECK BUTTON TO RUN IT

//TO TEST THE THRUSTER SPEEDS IN THE POOL, TRY RUNNING ONE FUNCTION AT A TIME
//TRY SEEING HOW THE STARTING 1600 SPEED WORKS AND IF IT IS TOO SLOW OR FAST, ALTAR THE VALUE A FEW LINES DOWN
//YOU CAN ALSO CHANGE THE DELAY TIME IN EACH FUNCTION WHICH WILL ALLOW THE THRUSTERS TO RUN FOR LONGER OR SHORTER AMOUNTS OF TIME
//BE CAREFUL NOT TO RUN THEM FOR TOO LONG SO IT DOESN'T RUN INTO ANYTHING
//IF THE AUV NEEDS TO BE STOPPED IMMEDIATLY, RUN THE STOP SKETCH IN THE STOP FOLDER OR HIT THE KILL SWITCH
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
  
  Serial.begin(9600);
  Serial.println("Directions (d=Down,f=Forward,l=Left,r=Right)");
  
}

void loop() 
{
  Mission = digitalRead(MissionSwitch); // read Mission Switch input 
  char dir='t'; //direction
  if (Mission== HIGH)
  {
    //CHOOSE WHICH MOTIONS YOU WANT TO RUN HERE, COMMENT OUT THE ONES YOU DON'T WANT TO USE BY PLACING // IN FRONT OF IT
    //THE ACTUAL CODE FOR EACH FUNCTION IS FURTHER DOWN
    //down();
    //forward();
    //right();
    //left();
    //hover();
    //up();
    //each();  //RUN THIS ONE IF YOU NEED TO TEST EACH INDIVIDUAL THRUSTER
    //still();   //RUN THIS AT THE END EVERYTIME TO STOP THE AUV FROM MOVING LONG ENOUGH TO KILL THE THRUSTERS
  }
  
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
  

}

//CHANGE THE CODE FOR EACH MOTION FUNCTION HERE; THE 'SIGNAL' REFERS TO THE VALUE YOU SET TOWARDS THE TOP
//YOU CAN CHANGE THAT VALUE TO EFFECT ALL OF THEM, OR SIMPLY PUT THE NUMBER VALUE IN PARANTHESIS TO CHANGE AN INDIVIDUAL VALUE IF NECESSARY
void down()
{
    servo2.writeMicroseconds(signal); // Send signal to ESC.
    servo3.writeMicroseconds(signal); // Send signal to ESC.
    servo6.writeMicroseconds(signal); // Send signal to ESC.
    servo7.writeMicroseconds(signal); // Send signal to ESC.
    
    delay(3000); //THIS IS HOW LONG THE THRUSTERS RUN IN MILLISECONDS (1000 MILLISECONDS = 1 SECOND)

    servo2.writeMicroseconds(stop); // Send signal to ESC.
    servo3.writeMicroseconds(stop); // Send signal to ESC.
    servo6.writeMicroseconds(stop); // Send signal to ESC.
    servo7.writeMicroseconds(stop); // Send signal to ESC.

    delay(10000); //THIS IS HOW LONG THE THRUSTERS ARE STOPPED IN MILLISECONDS (1000 MILLISECONDS = 1 SECOND)
}
void hover()
{
    //FIND THE RIGHT SPEED TO KEEP THE AUV STEADY AT A CERTAIN LEVEL
    servo2.writeMicroseconds(signal); // Send signal to ESC.
    servo3.writeMicroseconds(signal); // Send signal to ESC.
    servo6.writeMicroseconds(signal); // Send signal to ESC.
    servo7.writeMicroseconds(signal); // Send signal to ESC.
    
    delay(3000); //THIS IS HOW LONG THE THRUSTERS RUN IN MILLISECONDS (1000 MILLISECONDS = 1 SECOND)

    servo2.writeMicroseconds(stop); // Send signal to ESC.
    servo3.writeMicroseconds(stop); // Send signal to ESC.
    servo6.writeMicroseconds(stop); // Send signal to ESC.
    servo7.writeMicroseconds(stop); // Send signal to ESC.

    delay(10000); //THIS IS HOW LONG THE THRUSTERS ARE STOPPED IN MILLISECONDS (1000 MILLISECONDS = 1 SECOND)
}
void up()
{
    //1400 SHOULD BE COUNTERCLOCKWISE WHICH SHOULD MOVE THE AUV UP
    servo2.writeMicroseconds(1400); // Send signal to ESC.
    servo3.writeMicroseconds(1400); // Send signal to ESC.
    servo6.writeMicroseconds(1400); // Send signal to ESC.
    servo7.writeMicroseconds(1400); // Send signal to ESC.
    
    delay(3000); //THIS IS HOW LONG THE THRUSTERS RUN IN MILLISECONDS (1000 MILLISECONDS = 1 SECOND)

    servo2.writeMicroseconds(stop); // Send signal to ESC.
    servo3.writeMicroseconds(stop); // Send signal to ESC.
    servo6.writeMicroseconds(stop); // Send signal to ESC.
    servo7.writeMicroseconds(stop); // Send signal to ESC.

    delay(10000); //THIS IS HOW LONG THE THRUSTERS ARE STOPPED IN MILLISECONDS (1000 MILLISECONDS = 1 SECOND)
}
void forward()
{

    servo1.writeMicroseconds(signal); // Send signal to ESC.
    servo4.writeMicroseconds(signal); // Send signal to ESC.
    servo5.writeMicroseconds(signal); // Send signal to ESC.
    servo8.writeMicroseconds(signal); // Send signal to ESC.

    delay(3000); //THIS IS HOW LONG THE THRUSTERS RUN IN MILLISECONDS (1000 MILLISECONDS = 1 SECOND)

    servo1.writeMicroseconds(stop); // Send signal to ESC.
    servo4.writeMicroseconds(stop); // Send signal to ESC.
    servo5.writeMicroseconds(stop); // Send signal to ESC.
    servo8.writeMicroseconds(stop); // Send signal to ESC.

    delay(10000); //THIS IS HOW LONG THE THRUSTERS ARE STOPPED IN MILLISECONDS (1000 MILLISECONDS = 1 SECOND)    

}
void left()
{

  servo3.writeMicroseconds(signal);
  servo2.writeMicroseconds(signal);

  delay(3000); //THIS IS HOW LONG THE THRUSTERS RUN IN MILLISECONDS (1000 MILLISECONDS = 1 SECOND)

  servo3.writeMicroseconds(stop);
  servo2.writeMicroseconds(stop);

  delay(10000); //THIS IS HOW LONG THE THRUSTERS ARE STOPPED IN MILLISECONDS (1000 MILLISECONDS = 1 SECOND)
}  
void right()
{

  servo5.writeMicroseconds(signal);
  servo6.writeMicroseconds(signal);

  delay(3000); //THIS IS HOW LONG THE THRUSTERS RUN IN MILLISECONDS (1000 MILLISECONDS = 1 SECOND)
  
  servo5.writeMicroseconds(stop);
  servo6.writeMicroseconds(stop);  

  delay(10000); //THIS IS HOW LONG THE THRUSTERS ARE STOPPED IN MILLISECONDS (1000 MILLISECONDS = 1 SECOND)
}  
void each()
{
    servo1.writeMicroseconds(signal); // Send signal to ESC.
    delay(2000); //THIS IS HOW LONG THE THRUSTERS RUN IN MILLISECONDS (1000 MILLISECONDS = 1 SECOND)
    servo1.writeMicroseconds(stop); // Send signal to ESC.
    delay(5000); //THIS IS HOW LONG THE THRUSTERS ARE STOPPED IN MILLISECONDS (1000 MILLISECONDS = 1 SECOND)
    servo2.writeMicroseconds(signal); // Send signal to ESC.
    delay(2000); //THIS IS HOW LONG THE THRUSTERS RUN IN MILLISECONDS (1000 MILLISECONDS = 1 SECOND)
    servo2.writeMicroseconds(stop); // Send signal to ESC.
    delay(5000); //THIS IS HOW LONG THE THRUSTERS ARE STOPPED IN MILLISECONDS (1000 MILLISECONDS = 1 SECOND)
    servo3.writeMicroseconds(signal); // Send signal to ESC.
    delay(2000); //THIS IS HOW LONG THE THRUSTERS RUN IN MILLISECONDS (1000 MILLISECONDS = 1 SECOND)
    servo3.writeMicroseconds(stop); // Send signal to ESC.
    delay(5000); //THIS IS HOW LONG THE THRUSTERS ARE STOPPED IN MILLISECONDS (1000 MILLISECONDS = 1 SECOND)
    servo4.writeMicroseconds(signal); // Send signal to ESC.
    delay(2000); //THIS IS HOW LONG THE THRUSTERS RUN IN MILLISECONDS (1000 MILLISECONDS = 1 SECOND)
    servo4.writeMicroseconds(stop); // Send signal to ESC.
    delay(5000); //THIS IS HOW LONG THE THRUSTERS ARE STOPPED IN MILLISECONDS (1000 MILLISECONDS = 1 SECOND)
    servo5.writeMicroseconds(signal); // Send signal to ESC.
    delay(2000); //THIS IS HOW LONG THE THRUSTERS RUN IN MILLISECONDS (1000 MILLISECONDS = 1 SECOND)
    servo5.writeMicroseconds(stop); // Send signal to ESC.
    delay(5000); //THIS IS HOW LONG THE THRUSTERS ARE STOPPED IN MILLISECONDS (1000 MILLISECONDS = 1 SECOND)
    servo6.writeMicroseconds(signal); // Send signal to ESC.
    delay(2000); //THIS IS HOW LONG THE THRUSTERS RUN IN MILLISECONDS (1000 MILLISECONDS = 1 SECOND)
    servo6.writeMicroseconds(stop); // Send signal to ESC.
    delay(5000); //THIS IS HOW LONG THE THRUSTERS ARE STOPPED IN MILLISECONDS (1000 MILLISECONDS = 1 SECOND)
    servo7.writeMicroseconds(signal); // Send signal to ESC.
    delay(2000); //THIS IS HOW LONG THE THRUSTERS RUN IN MILLISECONDS (1000 MILLISECONDS = 1 SECOND)
    servo7.writeMicroseconds(stop); // Send signal to ESC.
    delay(5000); //THIS IS HOW LONG THE THRUSTERS ARE STOPPED IN MILLISECONDS (1000 MILLISECONDS = 1 SECOND)
    servo8.writeMicroseconds(signal); // Send signal to ESC.
    delay(2000); //THIS IS HOW LONG THE THRUSTERS RUN IN MILLISECONDS (1000 MILLISECONDS = 1 SECOND)
    servo8.writeMicroseconds(stop); // Send signal to ESC.
    delay(5000); //THIS IS HOW LONG THE THRUSTERS ARE STOPPED IN MILLISECONDS (1000 MILLISECONDS = 1 SECOND)
    
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



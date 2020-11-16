#include <AFMotor.h> 

AF_DCMotor motor1(1, MOTOR12_64KHZ     );
AF_DCMotor motor2(2, MOTOR12_64KHZ     );
AF_DCMotor motor3(3, MOTOR34_64KHZ     );
AF_DCMotor motor4(4, MOTOR34_64KHZ     );

int serail_value = 'e';
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
int speed = 200;
motor1.setSpeed(speed);
motor2.setSpeed(speed);
motor3.setSpeed(speed);
motor4.setSpeed(speed);

motor1.run(RELEASE);   
motor2.run(RELEASE); 
motor3.run(RELEASE); 
motor4.run(RELEASE); 
}


void all4Forward()
{
  motor1.run(FORWARD);        
  motor2.run(FORWARD); 
  motor3.run(FORWARD); 
  motor4.run(FORWARD);     
}

void only2Forward()
{
  motor1.run(FORWARD);        
  motor2.run(FORWARD); 
  motor3.run(0); 
  motor4.run(0);     
}

void Left()
{
  motor1.run(0);        
  motor2.run(0); 
  motor3.run(FORWARD); 
  motor4.run(FORWARD);     
}

void Right()
{
  motor1.run(FORWARD);        
  motor2.run(FORWARD); 
  motor3.run(0); 
  motor4.run(0);     
}

void LeftWithAngle()
{
  motor3.setSpeed(100);
  motor4.setSpeed(100);
  motor1.run(0);        
  motor2.run(0); 
  motor3.run(FORWARD); 
  motor4.run(FORWARD);     
}

void TestLeft()
{

  motor3.setSpeed(100);
  motor4.setSpeed(100);
  motor2.setSpeed(90);
  motor1.setSpeed(200);    
  motor1.run(0);        
  motor2.run(FORWARD); 
  motor3.run(FORWARD); 
  motor4.run(FORWARD);     
}

void TestRight()
{

  motor1.setSpeed(150);
  motor2.setSpeed(150);
  motor3.setSpeed(100);
  motor4.setSpeed(200); 
  motor4.run(0);        
  motor1.run(FORWARD); 
  motor2.run(FORWARD); 
  motor3.run(FORWARD);     
}

void loop() {

if(Serial.available()>0){
serail_value = Serial.read();
}

if(serail_value == 'a')
{
TestLeft();
delay(3000); 
Right();
//delay(1000); 
motor1.run(RELEASE);   
motor2.run(RELEASE); 
motor3.run(RELEASE); 
motor4.run(RELEASE); 
delay(1000); 
}
}

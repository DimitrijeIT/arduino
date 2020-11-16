#include <AFMotor.h> 

AF_DCMotor motor(1, MOTOR12_64KHZ);
void setup() {
  // put your setup code here, to run once:
motor.setSpeed(200);
motor.run(RELEASE);
}

void loop() {
  // put your main code here, to run repeatedly:
motor.run(FORWARD);       
delay(1000); 
motor.run(BACKWARD);      
delay(1000);  
motor.run(RELEASE);       
delay(1000); 
}

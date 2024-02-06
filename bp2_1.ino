#include <Servo.h>
Servo servoMotor;
int potansiyometre=A0;
int potdeg;
void setup() 
{
  servoMotor.attach(3);
}

void loop() 
{
potdeg=analogRead(potansiyometre);
potdeg=map(potdeg,0,1023,0,179);
servoMotor.write(potdeg);
delay(15);
}

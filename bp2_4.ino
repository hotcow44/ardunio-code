#include <Servo.h>
Servo servomotor1;
Servo servomotor2;
int potdeg;

void setup() 
{
 Serial.begin(9600);
 servomotor1.attach(9);
 servomotor2.attach(10);

}
void loop() 
{
 potdeg=analogRead(A0);
 potdeg=map(potdeg,0,1023,0,180);
 potdeg=constrain(potdeg,0,180);
 servomotor1.write(potdeg);
 servomotor2.write(180-potdeg);
 delay(5);

}

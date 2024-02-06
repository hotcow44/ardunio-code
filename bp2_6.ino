#include <Servo.h>
Servo servo1;
int angle;

void setup()
 {
 servo1.attach(9,900,2100);
 Serial.begin(9600);

}

void loop() 
{
  int speed;
  Serial.println("Type an angle (0-180) into the box above,");
  Serial.println("then click[send] or press[return]");
  Serial.println();
  while(true)
  {
    while(Serial.available()>0)
    {
     angle=Serial.println();
     angle=constrain(angle,0,180);
     Serial.print("setting angle to");
     Serial.print(angle);
     servo1.write(angle);
    }
  }
}

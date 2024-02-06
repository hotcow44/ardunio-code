#include <Servo.h>
Servo servo;
void setup() 
{
}

void loop()
{
servo.attach(9);
servo.attach(10);
for(int i=0;i<=180;i++)
{
  servo.write(i);
  delay(20);
  servo.detach();
  servo.attach(10,544,2400);
}
for(int i=544;i<=2400;i+=10)
{
  servo.writeMicroseconds(i);
  delay(20);

}
servo.detach();
delay(1000);
servo.attach(9);
for(int i=180;i>=180;i--)
{
  servo.write(i);
  delay(20);
  servo.detach();
  servo.attach(10,544,2400);
  servo.writeMicroseconds(2400);
}
for(int i=2400;i>=544;i-=10)
{
  servo.writeMicroseconds(i);
  delay(20);
}
servo.detach();
delay(1000);
}

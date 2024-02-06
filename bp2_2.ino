#include <Servo.h>
#include <EEPROM.h>
Servo servom;
float resoltion=1000;
float recordtime=5;
bool recording=false;
void setup()
 {
pinMode(13,OUTPUT);
pinMode(2,OUTPUT);
servom.attach(3);
Serial.begin(9600);
digitalWrite(2,HIGH);

}

void loop()
 {
if(recording==true)
{
  for(int i=1;i<=resoltion;i++)
  {
    digitalWrite(13,HIGH);
    int val=map(analogRead(A0),0,1023,0,180);
    EEPROM.write(i,val);
    servom.write(val);
    delay(recordtime);
  }
  digitalWrite(13,LOW);
  delay(1000);
  recording=false;
}
else
{
  for(int i=1;i<=resoltion;i++)
  {
    if(digitalRead(2)==0)
    recording=true;
    break;
  }int i;
  int readval = EEPROM.read(i);
  servom.write(readval);
  delay(recordtime);
}
digitalWrite(13,HIGH);
delay(100);
digitalWrite(13,LOW);
}



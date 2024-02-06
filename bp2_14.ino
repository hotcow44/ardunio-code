#include <Servo.h>
Servo myservo;
int ledr2=5;
int  ledr1=4;
int ledy1=2;
int ledy2=3;
int ledg1=1;
int gas=A0;
int buzzer=8;
int servo=9;
void setup() {
 pinMode(ledy1,OUTPUT);
 pinMode(ledy2,OUTPUT);
 pinMode(ledr1,OUTPUT);
 pinMode(ledr2,OUTPUT);
 pinMode(ledg1,OUTPUT);
 pinMode(buzzer,OUTPUT);
 myservo.attach(servo);
 pinMode(gas,INPUT);
 Serial.begin(9600);

}

void loop() 
{
int read=analogRead(gas);
int val=map(read,80,380,0,100);
Serial.println(val);
int servo=map(read,80,380,0,180);
digitalWrite(ledg1,HIGH);
if(val>=20 && val<40)
{
  digitalWrite(ledy1,HIGH);
}
if(val>=40 && val<60)
{
  digitalWrite(ledy2,HIGH);
}
if(val>=60 && val<80)
{
  digitalWrite(ledr1,HIGH);
}
if(val>=80)
{
  digitalWrite(ledr2,HIGH);

}
delay(500);
digitalWrite(ledy1,LOW);
digitalWrite(ledy2,LOW);
digitalWrite(ledr1,LOW);
digitalWrite(ledr2,LOW);
digitalWrite(ledg1,LOW);
delay(1000);
tone(buzzer,100,500);

 if(val<80)
 {
  noTone(buzzer);
 }
}


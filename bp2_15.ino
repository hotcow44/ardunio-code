#include <Servo.h>
Servo servo;
int smoke=A0;
int buzzer=9;
int motor=4;
int sensorthreshold=65;
void setup() {
pinMode(buzzer,OUTPUT);
pinMode(motor,OUTPUT);
pinMode(smoke,INPUT);
servo.attach(11);
Serial.begin(9600);

}

void loop() {
int sensordeger=analogRead(smoke);
if(sensordeger>=sensorthreshold)
{
  servo.write(90);
  digitalWrite(motor,HIGH);
  tone(buzzer,250,2500);
  delay(8000);
  digitalWrite(motor,LOW);
}
else
{
  servo.write(0);
  noTone(buzzer);
}
Serial.println(sensordeger);
delay(50);
}

#include <Servo.h>
const int trigpin=8;
const int echopin=7;
Servo radarservo;
int aci;
long mesafeolcumu()
{
  long sure;
  long uzaklik;
  digitalWrite(trigpin,LOW);
  delayMicroseconds(5);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(5);
  digitalWrite(trigpin,LOW);
  sure=pulseIn(echopin,HIGH,11600);
  uzaklik=sure/29.1/2;
  if(uzaklik>200||uzaklik<1)
  uzaklik=0;
  return uzaklik;
}
void ekranayazdir(int acideger,long uzaklikdeger)
{
  Serial.print("aci=");
  Serial.print(acideger);
  Serial.print("uzaklik");
  Serial.print(uzaklikdeger);
}
void setup() 
{
pinMode(trigpin,OUTPUT);
pinMode(echopin,INPUT);
radarservo.attach(9);
Serial.begin(9600);

}

void loop() {
 for(aci=0;aci<180;aci+=10)
{
  radarservo.write(aci);
  delay(15);
  ekranayazdir(aci,mesafeolcumu);
}
 for(aci=180;aci>=1;aci-=10)
{
  radarservo.write(aci);
  delay(15);
  ekranayazdir(aci,mesafeolcumu);
}
}

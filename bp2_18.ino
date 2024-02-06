int trigpin=8;
int echopin=7;
long sure;
long uzaklik;
boolean oncekidurum=0;
boolean sonrakidurum=0;

void setup() {
 pinMode(trigpin,OUTPUT);
 pinMode(3,OUTPUT);
 pinMode(echopin,INPUT);
}

void loop() {
 digitalWrite(trigpin,LOW);
delayMicroseconds(5);
 digitalWrite(trigpin,HIGH);
delayMicroseconds(10);
 digitalWrite(trigpin,LOW);
sure=pulseIn(echopin,HIGH);
uzaklik=sure/29.1/2;
if(uzaklik<60 && oncekidurum==0)
{
  digitalWrite(3,HIGH);
  sonrakidurum=1;
  delay(3000);
}if(uzaklik<60 && oncekidurum==1)
{
  digitalWrite(3,HIGH);
  sonrakidurum=0;
  delay(3000);
}

}

const int motor=9;

void setup() {
 pinMode(motor,OUTPUT);
 Serial.begin(9600);

}

void loop() {
 int ontime=3000;
 int offtime=1000;
 analogWrite(motor,255);
 delay(ontime);
  analogWrite(motor,0);
delay(offtime);
speedandupdown();
serialspeed();

}
void speedandupdown()
{
  int speed;
  int delaytime=500;
  for(int speed=0;speed<=255;speed++)
  {
    analogWrite(motor,speed);
    delay(delaytime);

  }
  for(speed=255;speed>=0;speed--)
  {
    analogWrite(motor,speed);
    delay(delaytime);
  }
}
void serialspeed()
{
  int speed;
  Serial.print("type a speed(0-255) into the box above");
  Serial.println("then click[send] or press[return]");
  Serial.println();
  while(true)
  {
    while(Serial.parseInt()>0)
    {
      speed=Serial.parseInt();
      speed=constrain(speed,0,255);
      Serial.print("setting speed to");
      Serial.print(speed);
      analogWrite(motor,speed);
    }
  }

}

const int motorpin=9;
int potansiyometre=A0;
void setup() {
 pinMode(motorpin,OUTPUT);
 Serial.begin(9600);

}

void loop() {
 int potansiyometre,hiz;
 int potokunan=analogRead(potansiyometre);
 hiz=map(potokunan,0,1023,0,255);
 analogWrite(motorpin,hiz);
 Serial.println(hiz);
 delay(50);

}

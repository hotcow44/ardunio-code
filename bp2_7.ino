int sensorReading=0;
void setup()
 {
pinMode(A0,INPUT);
pinMode(9,OUTPUT);
Serial.begin(9600);
}

void loop()
 {
sensorReading=analogRead(A0);
Serial.println(sensorReading);
tone(9,440*pow(2.0,(constrain(int(map(sensorReading,0,1023,36,84)),35,127)-57)/12.0),1000);
delay(10);

}

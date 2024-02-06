int titresimmotoru=10;
void setup() {
pinMode(titresimmotoru,OUTPUT);

}

void loop() {
analogWrite(titresimmotoru,128);
delay(500);
analogWrite(titresimmotoru,255);
delay(500);
}

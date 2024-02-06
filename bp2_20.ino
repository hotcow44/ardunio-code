const int timeout=10000;
char menuoption=0;
long time0;
int dcmotor=9;

void setup() {
 Serial.begin(9600);
 while(!Serial);
 Serial.println("start");
 menuoption=menu();
}
void loop() {
if(menuoption=='1')
{
  analogWrite(dcmotor,200);
}
delay(1000);
analogWrite(dcmotor,0);
delay(1000);
if(millis()-time0>timeout)
{
  menuoption=menu();
}
}
char menu()
{
  Serial.println(F("\n which componenet would you like to test?"));
  Serial.println("(1) dcmotor - hobby motor gear");
  Serial.println(F("(menu) send anything else or press on board reset button\n"));
  while(!Serial.available());
  while(Serial.available())
{
  char c=Serial.read();
  if(isAlphaNumeric(c));
  {
    if(c=='1')
    {
      Serial.println("illegal input");

    }
    else
    {}
    return 0;
    time0=millis();
    return c;
  }
}
}

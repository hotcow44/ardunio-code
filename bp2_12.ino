int const PIN_GAS=A1;
int LED_YESIL=7;
int LED_SARI=6;
int LED_TURUNCU=5;
int LED_KIRMIZI=4;
void setup() 
{
pinMode(LED_YESIL,OUTPUT);
pinMode(LED_SARI,OUTPUT);
pinMode(LED_TURUNCU,OUTPUT);
pinMode(LED_KIRMIZI,OUTPUT);
Serial.begin(9600);
}

void loop() 
{
  int deger=analogRead(PIN_GAS);
  deger=map(deger,300,750,0,100);
  digitalWrite(LED_YESIL,HIGH);
  if(deger>=30)
  {
    digitalWrite(LED_SARI,HIGH);
    Serial.println("duman yaklaştı 2. kademe");
  }
  else
  {
    digitalWrite(LED_SARI,LOW);
  }
   if(deger>=50)
  {
    digitalWrite(LED_TURUNCU,HIGH);
    Serial.println("duman yaklaştı 3. kademe");
  }
  else
  {
    digitalWrite(LED_TURUNCU,LOW);
  }
    if(deger>=80)
  {
    digitalWrite(LED_KIRMIZI,HIGH);
    Serial.println("duman yaklaştı 4. kademe");
  }
  else
  {
    digitalWrite(LED_KIRMIZI,LOW);
  }
delay(250);
}

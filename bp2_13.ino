#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int soundpin=8;
int detectorpin=A0;
float smokelvl=0;
void setup() {
lcd.begin(16,2);

}

void loop() {
smokelvl=analogRead(detectorpin);
lcd.setCursor(0,0);
lcd.clear();
lcd.print("NO SMOKE");
lcd.setCursor(0,1);
lcd.print("detector...");
while(smokelvl>30)
{
  smokelvl=analogRead(detectorpin);
  tone(soundpin,400,200);
  delay(2000);
  tone(soundpin,1000,200);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("***WARNING***");
  lcd.setCursor(0,1);
  lcd.print("SMOKE DETECTED!");
  delay(200);
}
delay(100);

}

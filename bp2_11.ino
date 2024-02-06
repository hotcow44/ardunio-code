const int buzzerPin=9;
const int songlength=18;
char notes[songlength]={'c','d','f','d','a','x','a','g','x','c','d','f','d','g','x','g','f','x'};
int beats[songlength]={1,1,1,1,1,1,4,4,1,1,1,1,1,1,4,4,2};
int tempo=113;
void setup() 
{
pinMode(buzzerPin,OUTPUT);

}

void loop()
{
 int i,duration;
 for(i=0;i<songlength;i++)
 {
  duration=beats[i]*tempo;
  if(notes[i]=='x')
  {
    delay(duration);
  }
  else 
  {
    tone(buzzerPin,frequency(notes[i]),duration);
    delay(duration);
  }
  delay(tempo/10);
}
while(1)
{

}


 int frequency(char note)
 {
  int i;
  const int numNotes=8;
  char names[numNotes]={'c','d','e','f','g','a','b','c'};
  int frequencies[numNotes]={262,294,330,349,392,440,494,523};
  for(i=0;i<numNotes;i++)
  {
    if(names[i]==note)
    {
      return (frequencies[i]);
    }
  }

 return 0;
 }

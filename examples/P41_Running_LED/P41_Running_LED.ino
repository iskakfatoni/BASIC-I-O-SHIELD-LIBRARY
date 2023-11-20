void setup()
{
  pinMode(6, OUTPUT); //pin 6 sebagai output (LED hijau)
  pinMode(7, OUTPUT); //pin 7 sebagai output (LED biru)
  pinMode(8, OUTPUT); //pin 8 sebagai output (LED kuning)
  pinMode(9, OUTPUT); //pin 9 sebagai output (LED merah)
}

void loop()
{
  for(int i = 6; i <= 9; i++)
  {
    digitalWrite(i, HIGH);

    if(i == 6)
      digitalWrite(9, LOW);
    else
      digitalWrite(i - 1, LOW);
  }
  
  delay(500);
}
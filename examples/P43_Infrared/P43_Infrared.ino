void setup()
{
  //pin 3 sebagai output (Buzzer)
  pinMode(3, OUTPUT);
  //pin 5 sebagai output (Transmitter)
  pinMode(5, OUTPUT);
  //pin A1 sebagai output (Receiver)
  pinMode(A1, INPUT);

  digitalWrite(5, HIGH); //megaktifkan Transmitter
}

void loop()
{
  //melakukan pemeriksaan kondisi Receiver
  switch(digitalRead(A1))
  {
    case HIGH:
      //menyalakan Buzzer
      digitalWrite(3, HIGH);
      break;
    case LOW:
      //memadamkan Buzzer
      digitalWrite(3, LOW);
      break;
  }  
}

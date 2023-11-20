void setup()
{
  pinMode(3, OUTPUT); //pin 3 sebagai output (Buzzer)
  pinMode(6, OUTPUT); //pin 6 sebagai output (LED hijau)
  //mengaktifkan interrupt pada pin 2 (interrupt 0)
  //interrupt tersebut dieksekusi saat kondisi pin 2 high
  attachInterrupt(0, ISRButton1, HIGH);
}

void loop()
{
  //kode program untuk membuat LED hijau berkedip
  digitalWrite(6, HIGH);
  delay(500);
  digitalWrite(6, LOW);
  delay(500);
}

//fungsi ISR (Interrupt Service Routine) bertipe void
void ISRButton1()
{
  static unsigned long oldTime = 0;
  //fungsi millis() digunakan untuk mendapatkan nilai
  //waktu sekarang, terhitung dari saat modul Arduino
  //pertama kali dinyalakan
  unsigned long newTime = millis();
  //apabila waktu antara interrupt satu dengan berikutnya
  //<= 200 ms, maka sinyal akan dianggap tidak valid,
  //sebaliknya, apabila waktu antara interrupt satu dengan
  //berikutnya > 200 ms, maka sinyal akan dianggap valid
  if (newTime - oldTime > 200)
  {
    digitalWrite(3, !digitalRead(3)); //toggle Buzzer
  }
  oldTime = newTime;
}

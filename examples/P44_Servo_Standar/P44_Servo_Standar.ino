//penyertaan library Servo
#include <Servo.h>

Servo Servo1; //deklarasi objek servo 

void setup()
{
  //penentuan pin 10 sebagai pin yang akan memberikan
  //sinyal kendali motor servo
  Servo1.attach(10);
}

void loop()
{
  //menentukan nilai sudut yang dituju oleh motor servo
  for(int i = 0; i <= 180; i++)
  {
    Servo1.write(i);
    delay(15);
  }
  for(int i = 180; i >= 0; i--)
  {
    Servo1.write(i);
    delay(15);
  }
}

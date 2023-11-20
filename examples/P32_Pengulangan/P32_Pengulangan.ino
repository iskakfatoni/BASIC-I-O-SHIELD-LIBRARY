//penyertaan library BasicIOShield dan Wire
#include <BasicIOShield.h>
#include <Wire.h>
BasicIOShield shield; //objek BASIC I/O SHIELD

void setup()
{
  //pengulangan sebanyak 10 kali
  for(int i = 0; i < 10; i++)
  {
    shield.GreenOn(); //menyalakan LED hijau
    delay(500); //delay 500 ms
    shield.GreenOff(); //memadamkan LED hijau
    delay(500); //delay 500 ms
  }
}

void loop()
{
  
}

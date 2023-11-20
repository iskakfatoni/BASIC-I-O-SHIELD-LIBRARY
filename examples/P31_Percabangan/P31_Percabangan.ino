//penyertaan library BasicIOShield dan Wire
#include <BasicIOShield.h>
#include <Wire.h>
BasicIOShield shield; //objek BASIC I/O SHIELD

void setup()
{
  
}

void loop()
{
  if(shield.Button1State()) //pemeriksaan Button 1
  {
    shield.RedOn(); //menyalakan LED merah
  }
  else if(!shield.Button1State()) // pemeriksaan Button 1
  {
    shield.RedOff(); //memadamkan LED merah
  }
}
